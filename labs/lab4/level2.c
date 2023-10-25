#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void request_process(const char* page) {
        char limit[1024];
        FILE* file_ptr;

        if (strcmp(page, "page1.html") == 0 || strcmp(page, "page2.html") == 0 || strcmp(page, "page3.html") == 0) {
                file_ptr = fopen(page, "r");
        }
        else {
                file_ptr = fopen(page, "r");
        }

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
