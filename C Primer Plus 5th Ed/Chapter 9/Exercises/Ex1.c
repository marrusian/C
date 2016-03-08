/*
*  1. Devise a function called min(x,y) that returns the smaller of two double values. Test
* the function with a simple driver.
*/

#include<stdio.h>

double min(double, double);

int main(void)
{
   double a = 0.0, b = 0.0;

   while(!feof(stdin)){
      printf("\nEnter first double: ");
      scanf("%lf", &a);
      printf("Enter second double: ");
      scanf("%lf", &b);
      printf("Min(%.1f,%.1f) = %.1f\n", a, b, min(a,b));       
   }
   
   return 0;
}

double min(double x, double y){return x<y? x : y;}