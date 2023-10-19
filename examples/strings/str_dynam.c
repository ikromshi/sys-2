#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

int strequal(char *x, char *y) ;	// function prototype

int main()
{
        char *str1,*str2;
        str1 = (char *) malloc(10 * sizeof(char));
        str2 = (char *) malloc(10 * sizeof(char));
        printf("Enter a string or ! to halt \n");
        scanf("%s",str1);
#ifdef DEBUG
    printf("This is a debug statement.  str1 is %s \n", str1);
#endif
        while (strcmp(str1, "!") != 0){
          printf("\nEnter another string\n");
          scanf("%s",str2);
          if (strequal(str1,str2))
                printf("The strings are equal\n");
          else
                printf("The strings are not equal\n");
          printf("Enter a string or ! to halt \n");
          scanf("%s",str1);
        }
}


int strequal(char *x, char *y)
{
        if (x == y) return(1);
        while (*x++ == *y++)
        {
                if (*x == '\0' && *y == '\0')
                        return (1);
        }
        return(0);
}
