/*
*  2. Write a program that initializes an array-of-double and then copies the contents of the
* array into three other arrays. (All four arrays should be declared in the main program.) To
* make the first copy, use a function with array notation. To make the second copy, use a
* function with pointer notation and pointer incrementing. Have the first two functions
* take as arguments the name of the target array, the name of the source array, and the
* number of elements to be copied. Have the third function take as arguments the name
* of the target, the name of the source, and a pointer to the element following the last
* element of the source. That is, the function calls would look like this, given the following
* declarations:
*
*    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
*    double target1[5];
*    double target2[5];
*    double target3[5];
*    copy_arr(target1, source, 5);
*    copy_ptr(target2, source, 5);
*    copy_ptrs(target3, source, source + 5);
*/

#include<stdio.h>

#define DIMENSION_OF(a) (sizeof(a)/sizeof((a)[0]))
#define BEYOND(a) ((a)+DIMENSION_OF(a))

void print_seq(FILE* stream, const double *start, const double *end);
void copy_arr(double dest[], const double source[], int size);
void copy_ptr(double *restrict dest, const double *restrict source, int size);
void copy_ptrs(double *restrict dest, const double *start, const double *end);

int main(void)
{
   double source[] = {1.1, 2.2, 3.3, 4.4, 5.5};
   double target1[DIMENSION_OF(source)];
   double target2[DIMENSION_OF(source)];
   double target3[DIMENSION_OF(source)];

   copy_arr(target1, source, DIMENSION_OF(source));
   print_seq(stdout, target1, BEYOND(target1));

   copy_ptr(target2, source, DIMENSION_OF(source));
   print_seq(stdout, target2, BEYOND(target2));

   copy_ptrs(target3, source, BEYOND(source));
   print_seq(stdout, target3, BEYOND(target3));

   return 0;
}

void print_seq(FILE* stream, const double *start, const double *end)
{
   while(start<end)
      fprintf(stream, "%.2f ", *start++);
   putc('\n', stream);
}

void copy_arr(double dest[], const double source[], int size)
{ 
   for(int i=0; i<size; ++i)
      dest[i] = source[i];
}

void copy_ptr(double *restrict dest, const double *restrict source, int size)
{
   while(size--)
      *dest++ = *source++;
}

void copy_ptrs(double *restrict dest, const double *start, const double *end)
{
   while(start<end)
      *dest++ = *start++;
}