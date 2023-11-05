#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
        if (fork() == 0) { /* this is the child */
                execl("./child", "./child", (char *)0);
                exit(1); /* should never get here; terminate */
        }

        /* Parent code here; */
        printf("Process[\%d]: Parent in execution... \n", getpid());
        sleep(2);
        
        if (wait(NULL) > 0) /* Child terminating */ 
        {
                printf("Process[\%d]: Parent detects terminating child \n", getpid());
        }
        printf("Process[\%d]: Parent terminating....\n", getpid() );
}
