/**
 * Author: Ikrom Numonov;
 * Date Modified: Nov 4, 2023;
 * Program purpose: This program deals with concurrency in the context of web servers with the exec family;
 * Program algorithm: The main function of the program is to use a function from the exec family to create a process that
 * will run the child code when you read a request from the user *
 */
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char htmlFile[256];

    while(1) {
        printf("Enter the name of the HTML file 'quit' to exit: \n");
        fflush(stdout);
        scanf("%s", htmlFile);

        if (strcmp(htmlFile, "quit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == 0) { // Child process;
            char *envp[] = {"WEBPATH=www/pages", NULL};
            execle("./child", "child", htmlFile, NULL, envp);
            exit(1); // Should not reach here;
        } else if (pid > 0) { // Parent process;
            printf("Process[%d]: Parent in execution... \n", getpid());
            printf(">> "); // next prompt
        } else {
            printf("Error with fork()");
            exit(1);
        }
    }

    printf("Process[%d]: Parent terminating....\n", getpid());
    return 0;
}

