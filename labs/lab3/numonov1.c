#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void readStrings(char *arr[], int size);
void selectionSort(char *arr[], int size);
void printStrings(char *arr[], int size);

int main() {
    char *strings[10]; // Array of pointers to char
    int n;

    printf("Enter the number of strings (up to 10): ");
    scanf("%d", &n);
    getchar(); // Consume the newline character after reading the integer

    if (n > 10 || n < 1) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    readStrings(strings, n);
    selectionSort(strings, n);
    printStrings(strings, n);

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }

    return 0;
}

void readStrings(char *arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (char *)malloc(21 * sizeof(char)); // Space for 20 chars + '\0'
        if (arr[i] == NULL) {
            perror("Unable to allocate memory");
            exit(1);
        }

        printf("Enter string %d: ", i + 1);
        fgets(arr[i], 21, stdin);

        // Remove the newline character if present
        size_t len = strlen(arr[i]);
        if (arr[i][len - 1] == '\n') {
            arr[i][len - 1] = '\0';
        }
    }
}

void selectionSort(char *arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (strcmp(arr[j], arr[min_idx]) < 0) {
                min_idx = j;
            }
        }
        // Swap the pointers
        char *temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printStrings(char *arr[], int size) {
    printf("Sorted strings:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

