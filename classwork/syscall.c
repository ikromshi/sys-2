/* Using syscall() in C to invoke Linux system calls for writing, exititng `*/
#include <unistd.h>

#include <string.h>
#include <errno.h>

char *message = "Hello World\n";
int main(void) {
    syscall(1, 1, message, 13);
    syscall(60, 0);

    /* Should never reach here */
    return 0;
}
