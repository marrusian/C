/*
*  3. Write a program that reads integers until 0 is entered. After input terminates, the
* program should report the total number of even integers (excluding the 0) entered, the
* average value of the even integers, the total number of odd integers entered, and the
* average value of the odd integers.
*/

#include<stdio.h>

int main(void)
{
   int even_nums = 0, odd_nums = 0;

   int total_nums = 0;
   printf("Enter integers (0 to quit): ");
   for(int num = 0; scanf("%d",&num) && num; ++total_nums)
      (num%2) ? ++odd_nums : ++even_nums;

   printf("Total number of even integers: %d\n", even_nums);
   printf("Total number of odd integers: %d\n", odd_nums);
   printf("Average value of even integers: %.2f\n", 100.0*((double)even_nums/total_nums));
   printf("Average value of odd integers: %.2f\n", 100.0*((double)odd_nums/total_nums));
 
   return 0;
}