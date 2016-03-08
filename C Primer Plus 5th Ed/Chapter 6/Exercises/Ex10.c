/*
*  10. Write a program that requests lower and upper integer limits, calculates the sum of all
* the integer squares from the square of the lower limit to the square of the upper limit,
* and displays the answer. The program should then continue to prompt for limits and
* display answers until the user enters an upper limit that is equal to or less than the lower
* limit. A sample run should look something like this:
*
*   Enter lower and upper integer limits: 5 9
*   The sums of the squares from 25 to 81 is 255
*   Enter next set of limits: 3 25
*   The sums of the squares from 9 to 625 is 5520
*   Enter next set of limits: 5 5
*   Done
*/

#include<stdio.h>
#include<inttypes.h>

intmax_t squares_sum(int lower_bound, int upper_bound);

int main(void)
{
   int lower_limit = 0, upper_limit = 0;   
   printf("Enter lower and upper integer limits: ");
   scanf("%d%d", &lower_limit, &upper_limit);
   while(lower_limit<upper_limit){
     printf("The sums of the squares from %d to %" PRIdMAX " is %" PRIdMAX "\n",
            lower_limit*lower_limit, (intmax_t)upper_limit*upper_limit,
            squares_sum(lower_limit,upper_limit));

     printf("Enter next set of limits: ");
     scanf("%d%d", &lower_limit, &upper_limit);
   }
   printf("Done!\n");

   return 0;
}

intmax_t squares_sum(int lower_bound, int upper_bound)
{
  #define n lower_bound
  #define m upper_bound

  return ((double)m/2*(m+1)*(2*m+1)/3 - (double)n/2*(n-1)*(2*n-1)/3);
}