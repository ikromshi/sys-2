/**
 * Author: Ikrom Numonov;
 * Date Modified: Nov 4, 2023;
 * Program purpose: This program deals with concurrency in the context of web servers;
 * Program algorithm: The main function of the program gets an input from the parent  and passes it into the
 *      request_process function. The child process reads a corresponding html
 *      file and sends it to standard out with the input included;
 *
 *
 */
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**************************************

function request_process
purpose:
        open the html file requested in a user's input and send it to standard out with an <h1> tag of the input;
parameters:
        char* pagePath: a pointer to a file name located in the same directory as the program file;
return value:
        void;

 *************************************/
void request_process(const char* pagePath) {
    char buffer[1024];
    FILE* file_ptr = fopen(pagePath, "r");

    if (file_ptr) {
        printf("<h1>Process ID: %d</h1>\n", getpid());

        while (fgets(buffer, sizeof(buffer), file_ptr)) {
            printf("%s", buffer);
        }

        fclose(file_ptr);
    } else {
        printf("Error opening file;\n");
    }
    exit(0);
}

int main(int argc, char *argv[], char *envp[]) {
    char filePath[512];

    if (argc != 2) {
        fprintf(stderr, "Error: Incorrect arguments\n");
        return 1;
    }

    char* webPath = getenv("WEBPATH");
    if (webPath == NULL) {
        fprintf(stderr, "WEBPATH not set\n");
        return 1;
    }

    snprintf(filePath, sizeof(filePath), "%s/%s", webPath, argv[1]);
    request_process(filePath);

    return 0;
}

