#include <stdio.h>
#include <string.h>

#define MAX 32
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
        char str1[MAX],str2[MAX];
        printf("Enter a string\n");
        fgets(str1, MAX, stdin);
        if ((strlen(str1) > 0) && (str1[strlen (str1) - 1] == '\n'))
          str1[strlen (str1) - 1] = '\0';
        printf("You entered -->%s<--\n", str1);
        printf("Enter another string\n");
        fgets(str2, MAX, stdin);
        if ((strlen(str2) > 0) && (str2[strlen (str2) - 1] == '\n'))
          str2[strlen (str2) - 1] = '\0';
        printf("You entered -->%s<--\n", str2);
        if (strequal(str1,str2))
                printf("The strings are equal\n");
        else
                printf("The strings are not equal\n");
}

