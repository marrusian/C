/*
*  4. Write a function that takes two int arguments: a value and a bit position. Have the
* function return 1 if that particular bit position is 1, and have it return 0 otherwise. Test
* the function in a program.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<inttypes.h>
#include<limits.h>

bool is_biton(unsigned int num, unsigned int bit_pos);
size_t popcount(uintmax_t val);

#define PRECISION(x) popcount(x)
int main(void)
{
   unsigned int val, pos;

   printf("Enter an integer and a bit position: ");
   while(scanf("%u%u", &val, &pos)==2){
      printf("Bit position %u is %s in the number %u\n",
              pos, is_biton(val,pos)? "set" : "not set", val);

      printf("\nEnter another integer and bit position (q to quit): ");
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

bool is_biton(unsigned int num, unsigned int bit_pos)
{
   if((size_t)bit_pos>PRECISION(UINT_MAX)){
      fprintf(stderr, "The number %u is bigger than the maximum\n"
                      "number of available bits, which is %zd\n",
                      bit_pos, PRECISION(UINT_MAX));
      
      exit(EXIT_FAILURE);
   }

   return (1<<bit_pos)&num;
}