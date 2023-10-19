#include  <sys/wait.h>
#include  <sys/types.h>
#include  <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
        if (fork() == 0){ /* this is child */
          fprintf(stderr,"Process[%d]:  child in execution....\n",getpid() );
           sleep(5);
           fprintf(stderr,"Process[%d]:  child terminating....\n",getpid()  );
           exit(0);
}
        /* Parent code here */
        printf("Process[%d]: Parent in execution ... \n", getpid() );
        sleep(2);
        if (wait(NULL) > 0) /* Child terminating */
                printf("Process[%d]: Parent detects terminating child \n", getpid() );
        printf("Process[%d]: Parent terminating....\n", getpid() );
}
