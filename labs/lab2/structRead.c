/*******************************************************************
 * File:   structRead.c
 * Author: John Barr
 *
 * Created on February 25, 2021, 11:00 PM
 * Last Modified February 25, 2021, 11:41 PM
 *
 * Purpose: To demonstrate reading and writing arrays of structs
 *      in binary format.
 *
 * Algorithm:
 *      a) Dynamically allocate MAX person structs 
 *      b) Ask user for name of file.
 *      c) Open file.
 *      d) Read in the structs in binary format from the file
 *      e) print the structs
 *      f) store the structs in a different file
 *
 ****************************************************************/
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define MIN 3
#define MAXCHAR 32

  struct person{
    char name[32];
    int id;
  };

int main()
{

  struct person *students, *stdPtr;
  int i, numRead, numWrote;
  FILE *sFile;
  char fName[MAXCHAR];

  students = (struct person*)malloc(MAX * sizeof(struct person));

  stdPtr = students;


  printf("Enter the name of the file with student info: \n");
  fgets(fName, MAXCHAR, stdin);
  if ((strlen(fName) > 0) && (fName[strlen (fName) - 1] == '\n'))
    fName[strlen (fName) - 1] = '\0';

  //  "rb" means "read bytes"
  if ( (sFile = fopen(fName, "rb")) == NULL)
  {
      fprintf(stderr, "cannot open %s for reading", fName);
      exit(1);
  }
  numRead = fread(students, sizeof(struct person), MAX, sFile);
  fprintf(stderr, "Read %d structs\n", numRead);

  printf("Here are the current students:\n");
  i = 0;
  while (i < numRead && stdPtr != NULL)
  {
    printf("%s", stdPtr->name);
    printf(",  %d\n", stdPtr->id);
    stdPtr++;
    i++;
  }

  printf("Now lets get some new students:\n");
  i = 0;
  stdPtr = students;
  while (i < MIN && stdPtr != NULL)
  {
    printf("Getting %dth student\n", i);
    printf("Enter name: ");
    scanf("%s", stdPtr->name);
    printf("Enter id: ");
    scanf("%d", &stdPtr->id);
    stdPtr++;
    i++;
  }
  printf("\nStudents:\n");

  i = 0;
  stdPtr = students;
  while (i < MIN && stdPtr != NULL)
  {
    printf("%s", stdPtr->name);
    printf(",  %d\n", stdPtr->id);
    stdPtr++;
    i++;
  }

  fclose(sFile);
  printf("Enter the name of the file to save student info: \n");
  __fpurge(stdin);
  fgets(fName, MAXCHAR, stdin);
  if ((strlen(fName) > 0) && (fName[strlen (fName) - 1] == '\n'))
    fName[strlen (fName) - 1] = '\0';
  if ( (sFile = fopen(fName, "wb")) == NULL)
  {
      fprintf(stderr, "cannot open %s for writing", fName);
      exit(1);
  }
  numWrote = fwrite(students, sizeof(struct person), 5, sFile);
  fprintf(stderr, "Wrote %d bytes\n", numWrote);

  fclose(sFile);
  free(students);

}

