/**
 *  PREREQUISITE: MUST HAVE A BINARY FILE (WITH ALREADY POPULATED STUDENTS);
 *                Code will throw an error if no file exists for reading/writing;
 *                (was running into issues that seemed to be random; so I'm turining in Level 2 as well just in case);
 *  
 *  Level 1: Complete;
 *  Level 2: Complete;
 *  Level 3: Complete; 
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
 * Purpose: Reads students from the binray file;
 * Parameters: pointer to an array of person structs - students;
 *             pointer to the filename;
 * Return Type: int;
 * Taken From structRead.c
 */
int readStudentsFromFile(struct person *students, const char *filename) {
  FILE *sFile = fopen(filename, "rb");
  if (!sFile) {
    fprintf(stderr, "cannot open %s for reading", filename);
    return -1;
  }

  int numRead = fread(students, sizeof(struct person), MAX, sFile);
  fclose(sFile);
  return numRead;
}


/**
 * Purpose: Writes students to the binary file;
 * Parameters: pointer to an array of person structs - students;
 *             count of students
 *             pointer to the filename
 * Return Type: int;
 * Taken from structRead.c;
 */
int writeStudentsToFile(struct person *students, int count, const char *filename) {
    FILE *sFile = fopen(filename, "wb");
    if (!sFile) {
        fprintf(stderr, "cannot open %s for writing", filename);
        return -1;
    }

    int numWrote = fwrite(students, sizeof(struct person), count, sFile);
    fclose(sFile);
    return numWrote;
}

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
  struct person *students = malloc(MAX * sizeof(struct person));
  int numStudents = 0;

  printf("Enter the name of the file with student info: \n");
  char fName[MAXCHAR];
  fgets(fName, MAXCHAR, stdin);
  if ((strlen(fName) > 0) && (fName[strlen(fName) - 1] == '\n'))
    fName[strlen(fName) - 1] = '\0';

  numStudents = readStudentsFromFile(students, fName);
  printf("Here are the current students:\n");
  for (int i = 0; i < numStudents; i++) {
    printf("%s, %d, %s\n", students[i].name, students[i].id, students[i].address);
  }

  printf("Now let's get some new students:\n");
  inputStudentInfo(students + numStudents, MIN);  
  numStudents += MIN;

  printf("\nStudents:\n");
  for (int i = 0; i < numStudents; i++) {
    printf("%s, %d, %s\n", students[i].name, students[i].id, students[i].address);
  }

  printf("Enter the name of the file to save student info: \n");
  __fpurge(stdin);
  fgets(fName, MAXCHAR, stdin);
  if ((strlen(fName) > 0) && (fName[strlen(fName) - 1] == '\n'))
    fName[strlen(fName) - 1] = '\0';

  if (writeStudentsToFile(students, numStudents, fName) == -1) {
    fprintf(stderr, "Failed to write students to the file.");
  }

  free(students);
  return 0;
}
