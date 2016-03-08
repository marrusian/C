/*
*  4. Write a function that returns the index of the largest value stored in an array-of-double.
* Test the function in a simple program.
*/

#include<stdio.h>
#define BEYOND(a) ((a)+(sizeof(a)/sizeof((a)[0])))

double find_dmax(const double *start, const double *end);

int main(void)
{
   double darr[] = {-23.35, 0.332, 65.3, 9.66, 44,3, -14.3};
 
   printf("The largest value stored in darr[] is: %g\n", find_dmax(darr, BEYOND(darr)));   

   return 0;
}

double find_dmax(const double *start, const double *end)
{
   double max = *start;

   while(start<end){
      if(max<*start)
         max=*start;
      ++start;
   }

   return max;
}