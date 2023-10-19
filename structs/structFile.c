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
  struct person students[MAX];
  int i;
  char fileName[50];
  FILE *sFile;

  for (i = 0; i < MAX; i++)
  {
    printf("Enter name: ");
    scanf("%s", students[i].name);
    printf("Enter id: ");
    scanf("%d", &students[i].id);
  }
  printf("\nStudents:\n");
  for (i = 0; i < MAX; i++)
  {
    printf("%s", students[i].name);
    printf(",  %d\n", students[i].id);
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
    for (i = 0; i < MAX; i++){
      fprintf(sFile, "%s\n", students[i].name);
      fprintf(sFile, "%d\n", students[i].id);
    }
  }

}
