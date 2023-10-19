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

  students = (struct person*)malloc(MAX * sizeof(struct person));

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

  printf("\nStudents:\n");
  stdPtr = students;
  for (i = 0; i < MAX; i++)
  {
    printf("%s", stdPtr->name);
    printf(",  %d\n", stdPtr->id);
    stdPtr++;
  }
}
