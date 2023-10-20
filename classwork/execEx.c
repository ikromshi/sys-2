#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    int x = 1;

    pid_t child = -1;
    pid_t pid = 0;

    char *path = "/home/barr/bin/hello";
    char * argv[] = {"Hello", "John", NULL};

    if ((pid = fork()) == 0) {
        if (execve(path, argv, NULL) < 0) {
            printf("%s Command not found\n", argv[0]);
            exit(1);
        }
    }
}
