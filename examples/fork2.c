#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* Code Listing 2.7:
   Running the same code in multiple processes
 */

int main(){
  /* Start by creating a second process */
  pid_t first_fork = fork();

  /* BOTH the original parent and child create new processes */
  pid_t second_fork = fork();

  /* This line will print four times */
  printf("Hello world from %d!\n", getpid());

  return(0);
}
