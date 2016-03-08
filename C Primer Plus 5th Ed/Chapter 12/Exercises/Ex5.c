/*
*  5. Write a program that generates a list of 100 random numbers in the range 1–1000
* in sorted decreasing order.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define SIZE 100

double uniform_deviate(void){return rand()*(1.0/(RAND_MAX+1.0));}

// Fill an integer sequence with values in the range [lower_bound,upper_bound)
void fill_iseq(int *start, int *end, int lower_bound, int upper_bound);

void print_iseq(int *start, int *end);

void insertion_sort(int *start, int *end, int gap);
void shell_sort(int *start, int *end);

int main(void)
{
   int arr[SIZE];

   srand((unsigned int)time(0));
   fill_iseq(arr, arr+SIZE, 1, 1001);
   
   shell_sort(arr, arr+SIZE);
   print_iseq(arr, arr+SIZE);
   
   return 0;
}

void print_iseq(int *start, int *end)
{
   while(start<end)
      printf("%d ", *start++);
   putchar('\n');
}

void fill_iseq(int *start, int *end, int lower_bound, int upper_bound)
{
   while(start<end)
      *start++ = (int)(uniform_deviate()*(upper_bound-lower_bound))+lower_bound;
}

// This implementation uses Tokuda's gap sequence
// Formula: h_k = ceil(h'_k), where h'_k = 2.25*h'_(k-1) + 1 and h'_1 = 1;
void shell_sort(int *start, int *end)
{
   double h=1.0;
   register int gap;

   while(h<end-start) h = 2.25*h+1.0;

   while(h>1.0){
      h = (h-1)/2.25;
      gap = ceil(h);
      insertion_sort(start+gap, end, gap);
   }
}

void insertion_sort(int *start, int *end, int gap)
{
   int temp;
   int *j;

   for(int *i = start; i<end; ++i){
      j = i;
      temp = *i;
      while(j>=start && *(j-gap)<temp){
         *j = *(j-gap);
         j -= gap;
      }
      *j = temp;
   }
}