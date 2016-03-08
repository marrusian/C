/*
*  6. Write a function that reverses the contents of an array of double and test it in a simple
* program.
*/

#include<stdio.h>
#define BEYOND(a) ((a)+(sizeof(a)/sizeof((a)[0])))

void reverse_dseq(double *start, double *end);
void print_seq(FILE* stream, const double *start, const double *end);

int main(void)
{
   double darr[] = {-5.2, 3.95, -9.53, 88.23, -31.21, 6.003, -52.43, 65.23, -45.632};
   
   printf("         darr[]: ");
   print_seq(stdout, darr, BEYOND(darr));

   reverse_dseq(darr, BEYOND(darr));
   printf("Reversed darr[]: ");
   print_seq(stdout, darr, BEYOND(darr));   

   return 0;
}

void reverse_dseq(double *start, double *end)
{
   double temp;

   --end;
   while(start<end){
      temp = *start;
      *start++ = *end;
      *end-- = temp;
   }
}

void print_seq(FILE* stream, const double *start, const double *end)
{
   while(start<end)
      fprintf(stream, "%.2f ", *start++);
   putc('\n', stream);
}