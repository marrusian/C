#include<stdio.h>
#define SIZE 10

int sump(const int *start, const int *end);

int main(void)
{
   int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
   long answer = 0L;

   answer = sump(marbles, marbles+SIZE);
   printf("The total number of marbles is %ld.\n", answer);

   return 0;
}

int sump(const int *start, const int *end)
{
   int total = 0;
 
   while(start<end)
      total+=*start++;

   return total;
}