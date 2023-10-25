#include  <sys/wait.h>
#include  <sys/types.h>
#include  <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
        pid_t child;

        /* Creating five children */
        for (int i=0; i<5; i++) {
                child = fork();
               
                /* Child executing */
                if (child == 0) {
                        
                        /* Creating a fork of the child process - grand child of parent*/
                        pid_t grand_child = fork();

                        /* Grand child executing */
                        if (grand_child == 0) {
                                fprintf(stderr, "Process [%d]:  grand child in execution....\n", getpid());
                                sleep(5);
                                fprintf(stderr, "Process [%d]:  grand child terminating....\n", getpid());
                                exit(0);
                        }

                        /* Rest of child executing */
                        fprintf(stderr,"Process[%d]:  child in execution....\n",getpid() );
                        sleep(5);
                        fprintf(stderr,"Process[%d]:  child terminating....\n",getpid()  );
                        exit(0);
                }
        }

        /* Parant executing */
        printf("Process[%d]: Parent in execution ... \n", getpid() );
        sleep(2);

        /* Waiting for all children to terminate */
        for (int i=0; i<5; i++) {
                if (wait(NULL) > 0) {
                        printf("Process[%d]: Parent detects terminating child \n", getpid() );
                } 
        }

        printf("Process[%d]: Parent terminating....\n", getpid() );
}
