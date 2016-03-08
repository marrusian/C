/*
*  5. Write a function that rotates the bits of an unsigned int by a specified number of bits
* to the left. For instance, rotate_l(x,4) would move the bits in x four places to the left,
* and the bits lost from the left end would reappear at the right end. That is, the bit moved
* out of the high-order position is placed in the low-order position. Test the function in a
* program.
*/

#include<stdio.h>
#include<limits.h>
#include<inttypes.h>

unsigned int rotate(unsigned int num, int bit_pos);
size_t popcount(uintmax_t val);

#define PRECISION(x) popcount(x)

int main(void)
{
   unsigned int val;
   int pos;

   printf("Enter a positive integer and the number of bits to be rotated: ");
   while(scanf("%u%d", &val, &pos)==2){
      printf("%uROL%d = %u\n", val, pos, rotate(val, pos));
      printf("\nEnter another positive integer and the number of bits to be rotated: ");
   }
   return 0;
}

size_t popcount(uintmax_t val)
{
   size_t precision = 0;
   while(val){
      val>>=1;
      ++precision;
   }

   return precision-1;
}

unsigned int rotate(unsigned int num, int bit_pos)
{
   int temp;
   register size_t precision = PRECISION(UINT_MAX);

   if(bit_pos>0)
      while(bit_pos--){
         temp = (num>>precision);
         num<<=1;
         num|=temp;
      }
   else
      while(bit_pos++){
         temp = num&1;
         num>>=1;
         num|=(temp<<precision);
      }

   return num;
}