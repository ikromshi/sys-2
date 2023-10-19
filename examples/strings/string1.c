#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main( )
{
        char line[SIZE], newLine[SIZE];
        int n, count;

        count = 0;
        printf("Enter a character.  End your input with ^d: \n");
        n = scanf(" %c", &line[count]);
        while (n != EOF)
        {
          count++;
          printf("Enter a character.  End your input with ^d: \n");
          n = scanf(" %c", &line[count]);
        }
        line[count] = '\0';

        strncpy(newLine, line, count);
        printf ("count is %d\n", count);
        printf ("You entered the characters %s \n", line);
        printf ("You entered the characters %s \n", newLine);
}
