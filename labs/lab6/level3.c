
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include<unistd.h>
#include<sys/wait.h>

#include "csapp.h"

#define STDOUT_FILENO 1
#define MAX 5

struct jobs
{
  int pid;
  struct jobs *next;
};

struct jobs *head, *tail;

void initjobs(){
    head = (struct jobs *)malloc(sizeof(struct jobs));
    tail = head;
    head->pid = -1;
    head->next = NULL;
}

void addjob(int pid){
  struct jobs *nextJob = (struct jobs *)malloc(sizeof(struct jobs));
  tail->next = nextJob;
  nextJob->pid = pid;
  nextJob->next = NULL;
  tail = nextJob;
}

void deletejob(int pid){
  int found = 0;
  struct jobs *nextJob = head;
  struct jobs *prevJob = head;

  if (head->next == NULL)
    return;
  while(!found){
    if (nextJob->next == NULL){
      // not found
      found = 1;
    }
    else if (nextJob->pid == pid){
      prevJob->next = nextJob->next;
      free(nextJob);
      found = 1;
    }else{
      nextJob = nextJob->next;
      if (nextJob == NULL){
        found = 1;
      }
    }
  }
}

void printJobs(){
  struct jobs *nextJob = head;
  nextJob = head->next;
  fprintf(stderr, "Jobs in queue:\n");
  while (nextJob != NULL){
    fprintf(stderr, "Job: %d\n", nextJob->pid);
    nextJob = nextJob->next;
  }
}

void handler(int sig)
{
  int olderrno = errno;
  sigset_t mask_all, prev_all;
  pid_t pid;
  Sigfillset(&mask_all);
  while ((pid = waitpid(-1, NULL, 0)) > 0) { /* Reap child */
    Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
    deletejob(pid); /* Delete the child from the job list */
    Sigprocmask(SIG_SETMASK, &prev_all, NULL);
  }
  if (errno != ECHILD)
      Sio_error("waitpid error");
  errno = olderrno;
  }


int main(int argc, char **argv) {
  int pid;
  sigset_t mask_all, mask_one, prev_one;
  int num = 0;

  Sigemptyset(&mask_one);
  Sigaddset(&mask_one, SIGCHLD);

  Signal(SIGCHLD, handler); // Set signal handler for SIGCHLD
  initjobs(); // Initialize the job list

  Sigprocmask(SIG_BLOCK, &mask_one, &prev_one); // Block SIGCHLD

  while (num < MAX) {
    if ((pid = Fork()) == 0) { /* Child */
      Execve("/bin/date", argv, NULL);
    }

    addjob(pid);  // Add the child to the job list
    num++;
  }

  // After all children are forked, unblock SIGCHLD and pause until all children are handled
  while (num > 0) {
    Sigsuspend(&prev_one); // Wait for SIGCHLD
    num--;
  }

  Sigprocmask(SIG_SETMASK, &prev_one, NULL); // Restore original mask

  printJobs(); // Print the jobs, should print nothing if all children are reaped
  exit(0);
}


