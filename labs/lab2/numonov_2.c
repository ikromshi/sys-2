/**
 *  Level 1: Complete;
 *  Level 2: Complete;
 *  Level 3: (Complete; different file)
 *
 *  Author Name: Ikrom Numonov;
 *  File: Lab 2;
 *  Last Modified: 09/13/2023;
 */


#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#define NUM 50
#define MAX 10
#define MIN 3
#define MAXCHAR 32

// Uncomment the following line to enable debug mode
// #define DEBUG

  struct person{
    char name[32];
    char address[NUM];
    int id;
  };


/**
 * Purpose: Gets input from user and populates 'students' array of structs;
 * Parameters: pointer to an array of person struct types;
 *             int size to that defines the length of students[];
 * Return Type: void;
 */
void inputStudentInfo(struct person *students, int size) {
  for (int i=0; i<size; i++) {
    printf("Enter name: "); 
    __fpurge(stdin);
    fgets((students + i )->name, sizeof((students + i)->name), stdin);
    int len = strlen((students + i)->name);

    // remove newline char to add a null terminatork;
    if ((students + i)->name[len-1] == '\n') {
      (students + i)->name[len-1] = '\0';
    }

    printf("Enter id: ");
    scanf("%d", &(students + i)->id);
    __fpurge(stdin);

    printf("Enter address: ");
    fgets((students + i)->address, sizeof((students + i)->address), stdin);
    len = strlen((students + i)->address);

    // remove newline character to add a null terminator;
    if ((students + i)->address[len-1] == '\n') {
      (students + i)->address[len-1] = '\0';
    }

    // Using the debug mode to display info on the input;
    #ifdef DEBUG
    printf("DEBUG MODE\nAdded: %s, %d, %s\n", (students + i)->name, (students + i)->id, (students + i)->address);
    #endif
  }
} 

/**
 * Purpose: Brings together the other functions to run the program;
 */
int main()
{
  struct person *students = NULL;
  char name[NUM];
  int foundStudent, numStudents;

  printf("Enter the number of students (up to 10): ");
  scanf("%d", &numStudents);
  __fpurge(stdin);

  students = (struct person *) malloc(numStudents * sizeof(struct person));
  
  if (students == NULL) {
    printf("Failed to allocate memory :|\n");
    return 1;
  }

  inputStudentInfo(students, numStudents);

  printf("\nStudents:\n");
  printf("Enter a name to find or 'none' to finish: ");
  __fpurge(stdin);
  fgets(name, sizeof(name), stdin);
  int len = strlen(name);
  if (name[len-1] == '\n') {
    name[len-1] = '\0';
  }

  while (strcmp(name, "none") != 0) {
    foundStudent = 0;

    for (int i=0; i<numStudents; i++) {
      if (strcmp((students + i)->name, name) == 0) {
        printf("%s, %d, %s\n", (students + i)->name, (students + i)->id, (students + i)->address);
        foundStudent = 1;
        break;
      }
    }
    
    if (!foundStudent) {
      printf("No such student %s\n", name);
    }

    printf("Enter a name to find or 'none' to finish: ");
    __fpurge(stdin);
    fgets(name, sizeof(name), stdin);
    len = strlen(name);
    if (name[len-1] == '\n') {
      name[len-1] = '\0';
    }
  }
  
  free(students);
  return 0;
}
