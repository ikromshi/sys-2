#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define MAX 3
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
  struct person *students, *stdPtr;
  int i;
  FILE *sFile;

  students = (struct person*)malloc(MAX * sizeof(struct person));

  stdPtr = students;

  sFile = fopen("students.txt", "rb");
  if(sFile == NULL)
   {
      fprintf(stderr,"Error opening students.txt\n\n");   
      exit(1);             
   }
  int numWritten = fread(students, sizeof(struct person), MAX, sFile);
  printf("\nStudents:\n");
  stdPtr = students;
  for (i = 0; i < MAX; i++)
  {
    printf("%s", stdPtr->name);
    printf(",  %d\n", stdPtr->id);
    stdPtr++;
  }

  sFile = fopen("students.txt", "wb");
  if(sFile == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
  numWritten = fwrite(students, sizeof(struct person), 10, sFile);
  printf("Wrote %d bytes\n", numWritten);
  
}
