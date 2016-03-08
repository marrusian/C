/*
*  2. The harmonic mean of two numbers is obtained by taking the inverses of the two
* numbers, averaging them, and taking the inverse of the result. Use a #define directive
* to define a macro “function” that performs this operation. Write a simple program that
* tests the macro.
*/

#include<stdio.h>

#define HARMONIC(X,Y) (2.0/(1.0/(X) + 1.0/(Y)))

int main(void)
{
   double x = 1, y = 1;

   printf("Enter two numbers: ");
   while((scanf("%lf%lf", &x, &y)==2)){
      printf("The harmonic mean of %g and %g is: %g.\n",
             x, y, HARMONIC(x,y));
      printf("Enter another two numbers ('q' to quit): ");
   }


   return 0;
}