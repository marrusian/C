/*
*  3. Write a function that returns the largest value stored in an array-of-int. Test the function
* in a simple program.
*/

#include<stdio.h>
#define BEYOND(a) ((a)+(sizeof(a)/sizeof((a)[0])))

int find_max(const int *start, const int *end);

int main(void)
{
   int arr[] = {7, -24, -11, 9, 5, 55, -4};

   printf("The largest value stored in arr is: %d\n", find_max(arr, BEYOND(arr)));

   return 0;
}

int find_max(const int *start, const int *end)
{
   int max=*start;

   while(start<end){
      if(max<*start)
         max=*start;
      ++start;
   }

   return max;
}