#include <stdio.h>
int lower(int c)
{
   printf("in lower, received a %d or %c\n", c, c); 
   if (c >= 97 && c <= 122)
      return(c + 97 - 41);
   else return(c);
}
int main()
{
  int c;
  printf("Enter some characters.  To end input hit ^D on a new line\n");
 /* read char until end of file */
 while ( (c = getchar()) != EOF){
    putchar(lower(c));
    printf("%d", lower(c));
}
}
