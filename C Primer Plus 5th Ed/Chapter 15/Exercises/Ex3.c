/*
*  3. Write a function that takes an int argument and returns the number of “on” bits in the
* argument. Test the function in a program.
*/

#include<stdio.h>

int count_bits(int num);

int main(void)
{
   int val;
  
   printf("Enter an integer: ");
   while(scanf("%d", &val)==1){
      printf("The number of set bits in %d is %d\n",
             val, count_bits(val));
      printf("\nPlease enter another integer (q to quit): ");
   }
   return 0;
}

int count_bits(int num)
{
   int ct = 0;
   while(num){
      num&=num-1;
      ++ct;
   }

   return ct;
}