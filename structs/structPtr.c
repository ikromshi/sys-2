#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define MAX 3

  struct person{
	char name[32];
	int id;
  };

int main()
{
  struct person *students, *stdPtr;
  int i;
  FILE *sFile;
  char fileName[50];

  students = (struct person*)malloc(MAX * sizeof(struct person));

  stdPtr = students;

  for (i = 0; i < MAX; i++)
  {
    printf("Enter name: ");
    scanf("%s", stdPtr->name);
    printf("Enter id: ");
    scanf("%d", &stdPtr->id);
    stdPtr++;
  }
  printf("\nStudents:\n");
  stdPtr = students;
  for (i = 0; i < MAX; i++)
  {
    printf("%s", stdPtr->name);
    printf(",  %d\n", stdPtr->id);
    stdPtr++;
  }

  printf("Enter name of file to write students to: ");
  __fpurge(stdin);
  scanf("%s", fileName);
  sFile = fopen(fileName, "w");
  if (sFile == NULL){
    fprintf(stderr, "failed to open %s\n", fileName);
  }
  else{
    printf("writing to %s\n", fileName);
    stdPtr = students;
    for (i = 0; i < MAX; i++){
      fprintf(sFile, "%s\n", stdPtr->name);
      fprintf(sFile, "%d\n",stdPtr->id);
      stdPtr++;
    }
  }
}
