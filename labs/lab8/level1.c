#include "csapp.h"
#include "assert.h"

/* Code Listing 6.9:
   Passing multiple arguments to a thread requires grouping them into a struct
 */

struct thread_args {
   int first;
   const char *second;
};

/* Using the convention of casting _args to args */
void *hello_thread (void *_args)
{
  /* Cast args into a meaningful pointer type that we can use */
  struct thread_args *args = (struct thread_args *) _args;
  printf ("First: %d; Second: '%s'\n", args->first, args->second);

  /* Do not forget to free the struct used for arguments */
  free (args);
  pthread_exit (NULL);
}

int main(){
    pthread_t child;
    struct thread_args *args = malloc (sizeof (struct thread_args));
    args->first = 5;
    args->second = "Hello";

    /* Note that the data structure resides on the heap */
    assert (pthread_create (&child, NULL, hello_thread, args) == 0);

    /* Code Listing 6.10:
       The child thread receives multiple values through the passed struct
     */
    /* Wait for the thread to finish */
    pthread_join (child, NULL);

    printf("thread finished, parent %d exiting\n", getpid());

}
