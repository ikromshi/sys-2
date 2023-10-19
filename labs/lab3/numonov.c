/** Level 2 of Lab 3
 *
 * Author Name: Ikrom Numonov
 * File: Lab 3
 * Last Modified: 09/20/2023
 */


#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Macro that comparing two characters
#define CHAR_COMPARE(a, b) ((a) - (b))

typedef char **StringArray; // typedef -> a pointer to an array of strings

// Function pointer for comparison
typedef int (*CompareFunc)(const char*, const char*);

// The Prototypes
void readStrings(StringArray arr, int size);
void selectionSort(StringArray arr, int size, CompareFunc cmpFunc);
void printStrings(StringArray arr, int size);
int compareTwo(const char *str1, const char *str2);

int main() {
    int n;
    printf("Enter the number of strings (up to 10): ");
    scanf("%d", &n);
    getchar(); // Consume the newline character

    if (n > 10 || n < 1) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    StringArray strings = (StringArray)malloc(n * sizeof(char *));
    if (strings == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    readStrings(strings, n);
    selectionSort(strings, n, compareTwo);
    printStrings(strings, n);

    for (int i = 0; i < n; i++) {
        free(*(strings + i));
    }
    free(strings);

    return 0;
}

// compares two strings and indicates which is larger
int compareTwo(const char *str1, const char *str2) {
    while (*str1 && *str2) { // come back to this block;
        int cmp = CHAR_COMPARE(*str1, *str2);
        if (cmp != 0) {
            return cmp;
        }
        str1++;
        str2++;
    }
    return CHAR_COMPARE(*str1, *str2); // Compare the potential null characters
}

// Queries the user for strings and read each string into an array
void readStrings(StringArray arr, int size) {
    for (int i = 0; i < size; i++) {
        char* currentString = (char *)malloc(21 * sizeof(char));
        if (currentString == NULL) {
            perror("Unable to allocate memory");
            exit(1);
    }

    arr[i] = currentString;
    
    printf("Enter string %d: ", i + 1);
    fgets(currentString, 21, stdin);

    size_t len = strlen(currentString);
    if (currentString[len - 1] == '\n') {
        currentString[len - 1] = '\0';
    }
}

}

// Selection sort implementation for strings
void selectionSort(StringArray arr, int size, CompareFunc cmpFunc) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (cmpFunc(*(arr + j), *(arr + min_idx)) < 0) {
                min_idx = j;
            }
        }
        // no swap here; why? ||
        char *temp = *(arr + min_idx);
        *(arr + min_idx) = *(arr + i);
        *(arr + i) = temp;
    }
}

// takes as parameters an array of strings and the number of strings and prints out the strings in the array
void printStrings(StringArray arr, int size) {
    printf("Sorted strings:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", *(arr + i));
    }
}

