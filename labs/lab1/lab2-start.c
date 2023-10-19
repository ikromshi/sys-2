#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

void trimWhite(char str[]);
void reverse(char str[]);
void cpStr(char str1[], char str2[]);
// Put the function prototype for strequal here
// See the file streq.c

int main()
{
    char str1[SIZE], str2[SIZE];
    int i, n;

    printf("Enter the string:\n");
    // read in the string using fgets
    fprintf(stderr, "you entered: %s\n", str1);
    // call trimWhite to eliminate white space and 
    // change to lower case
    printf("str1 trimmed is %s\n", str1);
    // call cpStr to copy str1 into str2
    printf("str2 is %s\n", str2);
    // call reverse to reverse str2
    printf("str2 reversed is %s\n", str2);
    // call streq to determine if the string is a palindrome
    // print result
}

void trimWhite(char str [])
{
    int i = 0, j = 0;
    char str2[SIZE];

    while (str[i] != '\0')
    {
        // ignore newline, tab and spaces
        // change upper case letters to lower case
    }
    str2[j] = '\0';
    printf("trimmed string str2 = %s\n", str2);
    i = 0;
    cpStr(str2, str);
}


void cpStr(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}

void reverse(char str[])
{
    int i = 0, j = 0;
    char rev[SIZE];
    int len = 0;

    // reverse str in place
    // first reverse str into a new string
    // and then copy the new string back into str
}

// Put the definition of strequal here
