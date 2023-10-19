/*  This function will read an entire line including 
 *  white space until either a newline character of the 
 *  EOF character is found */
#include <stdio.h>

int readline(char s[ ],int max, FILE *fptr)
{
        int c,i=0;

        // must do this so that we have room at the end for the \0
        max--;
        while (i < max && (c = getc(fptr)) != EOF && c != '\n')
                s[i++] = c;
        // uncomment the following line if you want 
        // the \n included in the string
        //if (c == '\n') s[i++] = c;
        s[i] = '\0';
        return(i);
}

