#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include<unistd.h>

#define STDOUT_FILENO 1


/* Code Listing 2.19:
   Overwriting the SIGINT handler to overwrite Ctrl-C termination
 */

/* Create the function for responding to signals */
static void sigint_handler (int signum)
{
  /* Length is hard-coded at 19; write signum into spaces */
  char buffer[] = "Received signal   \n";
  if (signum < 10)
    buffer[16] = '0' + signum;
  else
    {
      buffer[16] = '0' + (signum / 10);
      buffer[17] = '0' + (signum % 10);
    }
  /* Must use write(), because it is asynchronous-safe */
  write (STDOUT_FILENO, buffer, 19);
  //exit (0);
}

int main (int argc, char *argv[])
{
  /* Create a sigaction and link it to the handler */
  struct sigaction sa;
  memset (&sa, 0, sizeof (sa));
  sa.sa_handler = sigint_handler;

  /* Overwrite the SIGINT handler */
  if (sigaction (SIGINT, &sa, NULL) == -1)
    printf ("Failed to overwrite SIGINT.\n");

  /* Try (and fail) to overwrite SIGKILL */
  if (sigaction (SIGKILL, &sa, NULL) == -1)
    printf ("This should fail. SIGKILL cannot change.\n");

  /* Loop until SIGINT or SIGKILL is received */
  printf ("Entering loop\n");
  while (1) ;
  return 0;
}
