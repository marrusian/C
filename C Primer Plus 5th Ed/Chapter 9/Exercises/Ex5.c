/*
*  5. Write and test a function called larger_of() that replaces the contents of two double
* variables with the maximum of the two values. For example, larger_of(x,y) would
* reset both x and y to the larger of the two.
*/

#include<stdio.h>

void larger_of(double *x, double *y){*x>*y? (*y=*x) : (*x=*y);}

int main(void)
{
   double a=0.0, b=0.0;

   while(!feof(stdin)){
      printf("\nEnter first double: "); 
      scanf("%lf",&a);
      printf("Enter second double: ");
      scanf("%lf",&b);

      printf("Before: x=%.2f, y=%.2f\n", a, b);
      larger_of(&a,&b);
      printf("After: x=%.2f, y=%.2f\n", a, b);
   }

   return 0;
}