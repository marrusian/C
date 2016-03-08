/*
*  5. Write a function that returns the difference between the largest and smallest elements of
* an array-of-double. Test the function in a simple program.
*/

#include<stdio.h>
#define BEYOND(a) ((a)+(sizeof(a)/sizeof((a)[0])))

double ddif_minimax(const double *start, const double *end);

int main(void)
{
   double darr[] = {-5.2, 3.95, -9.53, 88.23, -31.21, 6.003, -52.43, 65.23, -45.632};
 
   printf("max(darr[])-min(darr[]) = %g\n", ddif_minimax(darr, BEYOND(darr)));

   return 0;
}

double ddif_minimax(const double *start, const double *end)
{
   double max, min;
   max = min = *start;

   // Even out the number of elements
   if((end-start)%2)
      ++start;

   // Find BOTH min and max in 3*n/2 comparisons
   while(start<end){
      if(*start<*(start+1)){
         if(min>*start)
            min=*start;
         if(max<*(start+1))
            max=*(start+1);
      }
      else{
         if(min>*(start+1))
            min=*(start+1);
         if(max<*start)
            max=*start;
      }
      start+=2;
   }
   
   return max-min;
}