#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void request_process(const char* page) {
        char limit[1024];
        FILE* file_ptr;

}

int main() {
        char page[50];

        while(1) {
                printf("Enter the request or 'quit' to quit: ");
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
