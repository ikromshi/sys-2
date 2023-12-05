#include "csapp.h"
#include "assert.h"
#include <time.h>
#include <unistd.h>

/* Code Listing 6.9:
   Passing multiple arguments to a thread requires grouping them into a struct
 */

struct thread_args {
   int first;
   int second;
   int sum;
};

/* Using the convention of casting _args to args */
void *hello_thread (void *_args)
{
  /* Cast args into a meaningful pointer type that we can use */
  struct thread_args *args = (struct thread_args *) _args;
  printf ("First: %d; Second: %d\n", args->first, args->second);

  // updating sum;
  args->sum = args->first + args->second;

  printf("Returning sum: %d\n", args->sum);
  /* Do not forget to free the struct used for arguments */
  // free (args);
  pthread_exit (NULL);
}

int main(){
    time_t time_seed;
    pthread_t child;
    struct thread_args *args = malloc (sizeof (struct thread_args));

    // creating two random numbers;
    srand((unsigned) time(&time_seed));
    int random_one = (rand() % 50) + 1;
    int random_two = (rand() % 50) + 1;
    args->first = random_one;
    args->second = random_two;

    /* Note that the data structure resides on the heap */
    assert (pthread_create (&child, NULL, hello_thread, args) == 0);

    /* Code Listing 6.10:
       The child thread receives multiple values through the passed struct
     */
    /* Wait for the thread to finish */
    pthread_join (child, NULL);
    
    printf("Received sum value from child for values '%d' and '%d' is: '%d'\n", random_one, random_two, args->sum);

    // free the memory;
    free(args);
    printf("thread finished, parent %d exiting\n", getpid());

}
