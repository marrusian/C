/*
*  4. The harmonic mean of two numbers is obtained by taking the inverses of the two
* numbers, averaging them, and taking the inverse of the result. Write a function that
* takes two double arguments and returns the harmonic mean of the two numbers.
*/

#include<stdio.h>

double dharm_mean(double a, double b){return 2.0/(1/a+1/b);}

int main(void)
{
   double x=0.0, y=0.0;

   while(!feof(stdin)){
      printf("\nEnter first double: ");
      scanf("%lf",&x);
      printf("Enter second double: "); 
      scanf("%lf",&y);
      printf("H(%.2f,%.2f) = %.2f\n", x, y, dharm_mean(x,y));
   }

   return 0;
}



 