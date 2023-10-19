#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a, int b)
{
   printf("Value of a is %d\n", a);
   printf("Value of b is %d\n", b);
}

void moreFun(void (*theFun)(int, int), int x, int y)
{
   (*theFun)(x, y);
}

int main()
{
   int x, y;
   // fun_ptr is a pointer to function fun() 
   void (*fun_ptr)(int, int) = &fun;

   /* The above line is equivalent of following two
   void (*fun_ptr)(int, int);
   fun_ptr = &fun; 
   */
   // passing the function as an argument
   printf("Enter an integer: \n");
   scanf("%d", &x);
   printf("Enter another integer: \n");
   scanf("%d", &y);
   printf("passing %d to moreFun with result:\n", x);
   moreFun(fun_ptr, x, y);

   return 0;
}

