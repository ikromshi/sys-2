#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

void trimWhite(char *str);
void reverse(char *str);
void cpStr(char *str1, char *str2);
int strequal(char *x, char *y);
void getInput(char *str1);

int main()
{
    char *str1, *str2;

	str1 = (char *) malloc(SIZE * sizeof(char));
	str2 = (char *) malloc(SIZE * sizeof(char));
    
	//	int i, n;
	
	// read input
	getInput(str1);
    
	// call trimWhite to eliminate white space and 
	// change to lower case
	trimWhite(str1);
    printf("str1 trimmed is %s\n", str1);

    // call cpStr to copy str1 into str2
	cpStr(str1, str2);
    printf("str2 is %s\n", str2);

    // call reverse to reverse str2
    reverse(str2);
	printf("str2 reversed is %s\n", str2);

    // call streq to determine if the string is a palindrome
    // print result
	if (strequal(str1, str2)) {
		printf("String %s is a palindrome.\n", str1);
	}
	else {
		printf("String %s is not a palindrome.\n", str1); 
	}

	free(str1);
	free(str2);
}

void getInput(char *str1) {
	 printf("Enter the string:\n");
    
	// read in the string using fgets
	fgets(str1, SIZE, stdin);
    fprintf(stderr, "you entered: %s\n", str1);
}

int strequal(char *x, char *y) {
	int i=0;
	if (x==y) return 1;
	
	while (x[i] == y[i]) {
		if (x[i] == '\0') {
			return 1;
		}
		i++;
	}

	return 0;
}

void trimWhite(char *str)
{
    int i = 0, j = 0;
    char str2[SIZE];

    while (str[i] != '\0')
    {
        // ignore newline, tab and spaces
		if (str[i] == '\t' || str[i] == '\n' || str[i] == ' ') {
			i++;
		}

        // change upper case letters to lower case
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			str2[j] = str[i] + 'a' - 'A';
			i++;
			j++;
		}
		else {
			str2[j] = str[i];
			i++;
			j++;
		}
    }
    str2[j] = '\0';
    printf("trimmed string str2 = %s\n", str2);
    i = 0;
    cpStr(str2, str);
}


void cpStr(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}

void reverse(char *str)
{
    int i = 0, j = 0;
    int len = 0;
	char *rev;
	rev = (char *) malloc(SIZE * sizeof(char));

    // reverse str in place
	// first reverse str into a new string
	while (str[i] != '\0') {
		len++;
		i++;
	}
	for (i=0; i<len; i++) {
		rev[i] = str[len-i-1];
	}
	rev[len] = '\0';

    // and then copy the new string back into str
	cpStr(rev, str);
}

