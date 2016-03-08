/*
*  7. Write a program that initializes a two-dimensional array-of-double and uses one of the
* copy functions from exercise 2 to copy it to a second two-dimensional array. (Because a
* two-dimensional array is an array of arrays, a one-dimensional copy function can be used
* with each subarray.)
*/

#include<stdio.h>
#include<inttypes.h>

#define DIMENSION_OF(a) (sizeof(a)/sizeof((a)[0]))
#define BEYOND(a) ((a)+ DIMENSION_OF(a))

void copy_ptrs(double *restrict dest, const double *start, const double *end);
void print_dseq(FILE* stream, const double *start, const double *end);

int main(void)
{
   double dmatr[2][4] = { {4.2,1.4,3.3,-5.2}, {-9.5,1.1,5.23,-2.45} };
   double dmatr_new[2][4];

   for(int_fast32_t i=0, limit=DIMENSION_OF(dmatr); i<limit; ++i){
      copy_ptrs(dmatr_new[i], dmatr[i], BEYOND(dmatr[i]));
      print_dseq(stdout, dmatr_new[i], BEYOND(dmatr_new[i]));
   }

   return 0;
}

void copy_ptrs(double *restrict dest, const double *start, const double *end)
{
   while(start<end)
      *dest++ = *start++;
}

void print_dseq(FILE* stream, const double *start, const double *end)
{
   while(start<end)
      fprintf(stream, "%.2f ", *start++);
   putc('\n', stream);
}