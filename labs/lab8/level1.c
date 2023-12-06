/**
 *  Author: Ikrom Numonov;
 *  Date modified: Dec 6, 2023;
 */

#include "csapp.h"
#include "assert.h"
#include <time.h>
#include <unistd.h>

// declaring the struct for thread args;
struct thread_args {
  int first;
  int second;
  int sum;
};


/* Using the convention of casting _args to args */
void *hello_thread (void *_args)
{
  int numbers[10];
  /* Cast args into a meaningful pointer type that we can use */
  struct thread_args *args = (struct thread_args *) _args;

  args->sum = args->first + args->second;
  // find the max number;

  printf("Thread returning sum %d\n", args->sum);

  /* Do not forget to free the struct used for arguments */
  pthread_exit (NULL);
}

int main(){
  pthread_t child;
  
  // setting up the random time seed;
  time_t time_seed;
  srand((unsigned) time(&time_seed));
  
  // allocate arguments and create threads;
  struct thread_args* args = malloc(sizeof(struct thread_args));

  // getting the random values;
  int first = (rand() % 50) + 1;
  int second = (rand() % 50) + 1;
  args->first = first;
  args->second = second;

  printf("Parent sending random numbers %d and %d to thread\n", first, second);

  // create the thread;
  assert( pthread_create(&child, NULL, hello_thread, args) == 0);

  // wait for the thread to finish;
  pthread_join(child, NULL);

  printf("Parent received sum %d from thread\n", args->sum);
  free(args);
  printf("thread finished, parent %d exiting\n", getpid());
  return 0;
}
