/*
*  8. Chapter 6, “C Control Statements: Looping,” (Listing 6.20) shows a power() function
* that returned the result of raising a type double number to a positive integer value.
* Improve the function so that it correctly handles negative powers. Also, build into the
* function that 0 to any power other than 0 is 0 and that any number to the 0 power is 1.
* (It should report that 0 to the 0 is undefined, then say it’s using a value of 1.) Use a loop.
* Test the function in a program.
*/

#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#include<stdlib.h>

double power(double base, int_fast32_t exp);

int main(void)
{
   double b = 0.0;
   int_fast32_t e = 0;

   while(!feof(stdin)){
      printf("\nEnter the number: ");
      scanf("%lf", &b);
      printf("Enter the exponent: ");
      scanf("%" SCNdFAST32, &e);
      
      printf("%g^%" PRIdFAST32 " = %g\n", b, e, power(b,e));
   }

   return 0;
}

double power(double base, int_fast32_t exp)
{  
   if(base && !exp) return 1.0;

   double ans=1.0;
   int_fast32_t aexp = abs(exp);

   while(aexp--) ans*=base;

   if(exp<0) ans=1/ans;
   else if(!exp) ans=NAN;

   return ans;
}