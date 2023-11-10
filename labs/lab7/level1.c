#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <signal.h>
#include <assert.h>

/* Code Listing 3.2:
   Using two pipes for bidirectional communication between parent and child
 */

int main(){

int p2cfd[2]; /* parent-to-child */
int c2pfd[2]; /* child-to-parent */
char buffer[10];
ssize_t bytes_read = 0;
time_t time_seed;


/* Clear the buffer and open the pipe */
memset (buffer, 0, sizeof (buffer));
if ((pipe (p2cfd) < 0) || (pipe (c2pfd) < 0))
  {
    printf ("ERROR: Failed to open pipe\n");
    exit (1);
  }

/* Create a child process */
pid_t child_pid = fork ();
assert (child_pid >= 0);

if (child_pid == 0)
  {
    /* Child closes write end of p2c, read of c2p */
    close (p2cfd[1]);
    close (c2pfd[0]);
    int sum = 0;

    while (1) {
      bytes_read = read (p2cfd[0], buffer, 10);
      if (bytes_read <= 0)
        exit (0);

      int number = atoi(buffer);
      sum += number;

      if (sum < 100) {
        printf("Child's current sum: %d\n", sum);
        strncpy(buffer, "more", sizeof(buffer));
        write(c2pfd[1], buffer, sizeof(buffer));
      }
      else if (sum >= 100) {
        strncpy(buffer, "goodbye", sizeof(buffer));
        write(c2pfd[1], buffer, sizeof(buffer));
        printf("\nChild's sum at least 100;\nChild exiting\n");
        exit(0);
      }
    }
  }

  /* Parent closes read end of p2c, write of c2p */
  close (p2cfd[0]);
  close (c2pfd[1]);

  srand((unsigned) time(&time_seed));
  int random_number = (rand() % 20) + 1;

  /* Parent sends first message and waits */
  sprintf (buffer, "%d", random_number);
  printf ("Parent is sending %d\n", random_number);
  write (p2cfd[1], buffer, sizeof (buffer));
  

  while (1) {
    /* Parent reads response back from child */
    bytes_read = read (c2pfd[0], buffer, 10);
    if (bytes_read <= 0)
      exit (1); /* should receive response */
    printf ("Parent received: '%s'\n", buffer);

    if (strncmp(buffer, "more", sizeof(buffer)) == 0) {
      random_number = rand() % 20 + 1;
      sprintf(buffer, "%d", random_number);
      printf("Parent sending a random number: %d\n", random_number);
      write(p2cfd[1], buffer, sizeof(buffer));
    }

    else if (strncmp(buffer, "goodbye", sizeof(buffer)) == 0) {
      printf("Parent exiting\n");
      return 0;
    }
  }
}
