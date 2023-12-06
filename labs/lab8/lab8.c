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
  int random_numbers[10];
};

// declaring the struct for thread return;
struct thread_return {
  int max;
  int min;
};

/* Using the convention of casting _args to args */
void *hello_thread (void *_args)
{
  int numbers[10];
  /* Cast args into a meaningful pointer type that we can use */
  struct thread_args *args = (struct thread_args *) _args;
  // allocate memory for the return struct;
  struct thread_return* results = malloc(sizeof(struct thread_return));

  int max = args->random_numbers[0];
  int min = args->random_numbers[0];

  // find the max number;
  for (int i=1; i<10; i++) {
    if (args->random_numbers[i] > max) {
      max = args->random_numbers[i];
    }
    else if (args->random_numbers[i] < min) {
      min = args->random_numbers[i];
    }
  }

  // recording return values;
  results->max = max;
  results->min = min;

  /* Do not forget to free the struct used for arguments */
  free (args);
  pthread_exit (results);
}

int main(){
  pthread_t child[5];
  
  // setting up the random time seed;
  time_t time_seed;
  srand((unsigned) time(&time_seed));
  
  // allocate arguments and create threads;
  struct thread_args* args[5] = {NULL, NULL, NULL, NULL, NULL};
  for (int i=0; i<5; i++) {
    args[i] = malloc(sizeof(struct thread_args));

    // populate random_numbers within each struct with 10 random numbers each;
    for (int j=0; j<10; j++) {
      args[i]->random_numbers[j] = (rand() % 50) + 1; 
    }

    // create the threads;
    assert( pthread_create(&child[i], NULL, hello_thread, args[i]) == 0);
  }
  

  // wait for the thread to finish;
  struct thread_return *results[5];
  for (int i=0; i<5; i++) {
    pthread_join(child[i],(void **)&results[i]);
    printf("Max value for thread '%d' is:'%d' \tMin value is: '%d'\n", i, results[i]->max, results[i]->min);
    free(results[i]);
  }
 
  printf("thread finished, parent %d exiting\n", getpid());
  return 0;
}
