#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main( )
{
        char line[SIZE];
        int n;
        FILE *fptr;
        char textName[15] = "inFile.txt";

        /* verify that we can open the file */
        if ( (fptr = fopen(textName, "r")) == NULL)
        {
                fprintf(stderr, "cannot open %s for reading", textName);
                exit(1);
        }


        n = fscanf(fptr, "%s", line);

        while (n != EOF)
        {
                printf("n = %d \t line = %s\n", n, line);
                n = fscanf(fptr, "%s", line);
        }
        printf ("Goodbye! \n");
}
