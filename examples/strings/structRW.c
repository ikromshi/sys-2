#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define MAX 5
#define STRMAX 32

  struct person{
	char name[32];
	int id;
  };

int readline(char s[ ],int max)
{
        int c,i=0;

        max--;
        while (i < max && (c = getchar()) != EOF && c != '\n')
                s[i++] =c;
        if (c != '\n') s[i++] = c;
        s[i] = '\0';
        return(i);
}


int main()
{
  struct person *students, *stdPtr, *stud2;
  int i;
  FILE *sFile;

  students = (struct person*)malloc(MAX * sizeof(struct person));
  stud2 = (struct person*)malloc(MAX * sizeof(struct person));

  stdPtr = students;

  for (i = 0; i < MAX; i++)
  {
    printf("Enter name: ");
    readline(stdPtr->name, STRMAX);
    printf("Enter id: ");
    scanf("%d", &stdPtr->id);
    __fpurge(stdin);
    stdPtr++;
  }
  printf("\nStudents Entered:\n");
  stdPtr = students;
  for (i = 0; i < MAX; i++)
  {
    printf("%s", stdPtr->name);
    printf(",  %d\n", stdPtr->id);
    stdPtr++;
  }

  sFile = fopen("students.txt", "w");
  if (sFile == NULL){
    fprintf(stderr, "Could not open file\n");
    exit(1);
  }
  int numWritten = fwrite(students, sizeof(struct person), MAX, sFile);
  printf("\nWrote %d elements\n", numWritten);
  fclose(sFile);

  sFile = fopen("students.txt", "r");
  if (sFile == NULL){
    fprintf(stderr, "Could not open file\n");
    exit(1);
  }
  /* Now read the structs that we just wrote */
  int numRead = fread(stud2, sizeof(struct person), MAX, sFile);
  stdPtr = stud2;
  printf("\nRead %d student elements\n", numRead);
  printf("Here are the students: \n");
  for (i = 0; i < numRead; i++)
  {
    printf("%s", stdPtr->name);
    printf(",  %d\n", stdPtr->id);
    stdPtr++;
  }

  fclose(sFile);
  free(students);
  free(stud2);
  
}
