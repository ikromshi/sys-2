#include <stdio.h>
#include <stdio_ext.h>

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
        // does not work:  scanf("%s ", str1);
        //scanf("%[^\n]s", str1);
        scanf("%s", str1);
        __fpurge(stdin);
        printf("\nYou entered -->%s<--\n", str1);
        printf("Enter another string\n");
        //scanf("%s ", str2);
        scanf("%[^\n]s", str2);
        printf("You entered -->%s<--\n", str2);
        if (strequal(str1,str2))
                printf("The strings are equal\n");
        else
                printf("The strings are not equal\n");
}

