#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//  necessary for getrusage and struct timeval
#include <sys/resource.h>


int main(int argc, char *argv[])
{
  int i;
  struct rusage usage;
  struct timeval start, end, startS, endS;
  
  getrusage(RUSAGE_SELF, &usage);
  start = usage.ru_utime;
  startS = usage.ru_stime;
  for (i = 0; i < 10; i++){
    fprintf(stderr, "Hello!\n");
    sleep(1);
  }

  getrusage(RUSAGE_SELF, &usage);
  end = usage.ru_utime;
  endS = usage.ru_stime;

  printf("\n\n");

  printf("Started at: %ld.%ld\n", start.tv_sec, start.tv_usec);
  printf("Ended at: %ld.%ld\n", end.tv_sec, end.tv_usec);
  printf("System Started at: %ld.%ld\n", startS.tv_sec, startS.tv_usec);
  printf("System Ended at: %ld.%ld\n", endS.tv_sec, endS.tv_usec);
  printf("time executing: %ld microsections\n", end.tv_usec - start.tv_usec);

  return 0;
}
