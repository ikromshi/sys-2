#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
        /* The child process's new program;
          This program replaces the parent's code;
          */

        fprintf(stderr, "Process[\%d]: child in execution... \n", getpid());
        sleep(5);
        fprintf(stderr, "Process[\%d]: child terminating... \n", getpid());
}
