/* Code Listing 2.4
 * using syscall() in C to invoke Linux system calls for writing, exiting
 */
#include <stdio.h>
/* needed for exit() */
#include <stdlib.h>
/* needed for syscall */
#include <unistd.h>
/* needed for function strerror */
#include <string.h>
/* needed for global variable errno */
#include <errno.h>


void unix_error(char *msg)
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(0);
}

int main(){
  char *message = "Hello World!\n";

  /* write system call */
  if (syscall(1,1,message,13) < 0){
    unix_error("write error");
  }
  /* exit system call */
  syscall(60, 0);

  /* should never reach here */
  return 0;
}
