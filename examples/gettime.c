#include <stdio.h>
//  necessary for getrusage and struct timeval
#include <sys/resource.h>


int main(int argc, char *argv[])
{
  int i;
  struct rusage usage;
  struct timeval start, end;
  
  getrusage(RUSAGE_SELF, &usage);
  start = usage.ru_utime;

  for(i = 0; i < 100000; i++)
	printf("%d ", i);


  getrusage(RUSAGE_SELF, &usage);
  end = usage.ru_utime;

  printf("\n\n");

  printf("Started at: %ld.%ld\n", start.tv_sec, start.tv_usec);
  printf("Ended at: %ld.%ld\n", end.tv_sec, end.tv_usec);
  printf("time executing: %ld microsections\n", end.tv_usec - start.tv_usec);

  return 0;
  
}
