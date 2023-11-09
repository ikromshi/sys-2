/**
 * LEVEL II
 * Author: Ikrom Numonov;
 * Date Modified: Oct 25, 2023;
 * Program purpose: This program deals with concurrency in the context of web servers;
 * Program algorithm: The main function of the program gets an input from the user and passes it into the 
 *      request_process function while forking the process off. The child process reads a corresponding html
 *      file and sends it to standard out with the input included;
 *
 * IMPORTANT: While running the program, you will notice that you can provide an input even before the program 
 *      asks or prints out the prompt for the input after the first run. I don't think this is a bug, but rather is
 *      a side effect of the fact that the child process's output and the parent process's output are both being 
 *      written to the standard out at the same time.
 */
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**************************************

function request_process
purpose:
        open the html file requested in a user's input and send it to standard out with an <h1> tag of the input;
parameters:
        char* page: a pointer to a file name located in the same directory as the program file;
return value:
        void;

 *************************************/
void request_process(const char* page) {
        char limit[1024];
        FILE* file_ptr;

        // check if the file exists; if so, open it;
        if (strcmp(page, "page1.html") == 0 || strcmp(page, "page2.html") == 0 || strcmp(page, "page3.html") == 0) {
                file_ptr = fopen(page, "r");
        }
        else {
                file_ptr = fopen("notFound.html", "r");
        }

        // once the file has been opened, send it to stdout;
        if (file_ptr) {
                printf("<h1>Process ID: %d", getpid());

                while (fgets(limit, sizeof(limit), file_ptr)) {
                        printf("%s", limit);
                }

                fclose(file_ptr);
        }
        else {
                printf("Error opening file;\n");
        }
        exit(0);
}

/**************************************
 
function main
purpose:
       handles input from the user and spawns a child process to handle the input; 

 * ***********************************/

int main() {
        char page[50];

        while(1) {
                printf("Enter the request or 'quit' to quit: \n");
                fflush(stdout);
                scanf("%s", page);

                if (strcmp(page, "quit") == 0) {
                        break;
                }

                pid_t child = fork();
                if (child == 0) { // child process;
                        request_process(page);
                }
        }

        printf("PID [%d]. Parent terminating....", getpid());
        return 0;
}
