#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/* Code listing 2.18:
   Using the kill() function to terminate a child process in an infinite loop
 */

int main(){
    /* Create a child process */
    pid_t child_pid = fork();
    printf ("Process %d is running\n", getpid());

    /* Exit if the fork fails to create a process */
    if (child_pid < 0){
      exit (1);
    }

    /* The child enters an infinite loop */
    if (child_pid == 0){
      fprintf(stderr, "Child process %d starting\n", getpid());
      while (1) ;
    }

    /* Make the parent sleep so the child gets a chance to run */
    sleep (1);
    /* The parent sends the SIGKILL signal to kill the child */
    kill (child_pid, SIGKILL);
    printf ("Process %d is exiting\n", getpid());
}
