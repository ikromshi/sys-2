#include <stdio.h>
int lower(int c)
{
   if (c >= 'A' && c <= 'Z')
      return(c + 'a' - 'A');
   else return(c);
}
int main()
{
  int c;
  printf("Enter some characters.  To end input hit ^D on a new line\n");
 /* read char until end of file */
 while ( (c = getchar()) != EOF)
    putchar(lower(c));
}
