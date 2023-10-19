#include <stdio.h>


int strequal(char x[ ], char y[ ])
{
        int i=0;
        if (x == y) return(1);
        while (x[i] == y [i])
        {
                if (x[i] == '\0')
                        return (1);
                i++;
        }
        return(0);
}

int main()
{
        char str1[10],str2[10];
        printf("Enter a string\n");
        scanf("%s[^\n]",str1);
        printf("\nEnter another string\n");
        /* read up to the newline character */
        scanf("%s[^\n]",str2);
        if (strequal(str1,str2))
                printf("The strings are equal\n");
        else
                printf("The strings are not equal\n");
}

