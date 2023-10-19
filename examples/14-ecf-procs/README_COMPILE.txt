To compile a file:

gcc -o fork fork.c csapp.c -lpthread

must include the csapp.c functions.  Since csapp.c has functions that use pthreads, must 
include the pthread library with the -lpthread option.
