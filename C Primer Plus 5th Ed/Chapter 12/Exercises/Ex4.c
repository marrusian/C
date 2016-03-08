/*
*  4. Write and test in a loop a function that returns the number of times it has been called.
*/

#include<stdio.h>

int function(void);

int main(void)
{
   for(int i=0; i<10; ++i)
      printf("Function called %d times\n", function());

   return 0;
}

int function(void)
{
   static int call_count = 0;
   return ++call_count;
}