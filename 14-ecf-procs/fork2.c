/*
 * forks.c - Examples of Unix process control
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


void fork2() {
  printf("LO - %d \n", getpid());
  fork();
  printf("L1 - %d \n", getpid());
  fork();
  printf("Bye - %d \n", getpid());
}

int main() {
  fork2();
  return 0;
}
