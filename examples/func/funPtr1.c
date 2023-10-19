#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a, int b)
{
  if (a >= b)
     printf("Value of a is %d\n", a);
  else
     printf("Value of b is %d\n", b);
}

int main()
{
   // fun_ptr is a pointer to function fun() 
   void (*fun_ptr)(int, int) = &fun;

   /* The above line is equivalent of following two
   void (*fun_ptr)(int);
   fun_ptr = &fun; 
   */
   // Invoking fun() using fun_ptr
   (*fun_ptr)(10, 20);

   return 0;
}

