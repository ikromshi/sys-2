#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

/* Code listing 2.18:
   Using the kill() function to terminate a child process in an infinite loop
 */

int main(){
  int running_children; // number of potential children to fork off;
  int random_sleep_time; // time, in seconds, for the parent to sleep (0 ≤ t ≤ 2);
  time_t time_seed; // time that serves as a random seed for the rand() function;

  /* Getting the number of children to run */ 
  printf("Enter the number of children to fork off: \n");
  scanf("%d", &running_children);
  
  /**********************/
  pid_t  PIDs[running_children];


  /* Creating N children and saving their PIDs*/
  for (int i=0; i<running_children; i++) {
    pid_t child_pid = fork();
    PIDs[i] = child_pid;
    //printf ("Child process %d is running\n", getpid());

    /* Exit if the fork() cails to create a process */
    if (child_pid < 0) {
      printf("Failed to fork\n");
      exit(1);
    }
    
    /* The child enters an infinite loop */
    if (child_pid == 0) {
      printf("Child process %d is running\n", getpid());
      while(1);
    }
  }

  /* Make the parent sleep so the children get a chance to run */
  srand((unsigned) time(&time_seed)); // setting the seed to a unique number;
  random_sleep_time = rand() % 3;
  sleep(random_sleep_time);

  /* The parent sends a SIGKILL signal to kill each child */
  for (int i=0; i<running_children; i++) {
    printf("Killing child PID: %d\n", PIDs[i]);
    kill(PIDs[i], SIGKILL);
  }

  printf("Parent Process %d is exiting\n", getpid());
}
