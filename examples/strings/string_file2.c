#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int readline(char s[], int max, FILE *fptr);

int main( )
{
        char line[SIZE], newLine[SIZE];
        char c;
        int n, count;

        count = 0;
        printf("Enter a bunch of characters.  End your input with ^d . Note that a newline is a character!\n");
        c = getchar();

        n = readline(line, SIZE, stdin);

        while (n != 0)
        {
                printf("n = %d \t line = %s\n", n, line);
                n = readline(line, SIZE, stdin);
        }
        printf ("Goodbye! \n");
}
