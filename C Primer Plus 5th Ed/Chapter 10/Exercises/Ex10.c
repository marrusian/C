/*
*  10. Write a function that sets each element in an array to the sum of the corresponding
* elements in two other arrays. That is, if array 1 has the values 2, 4, 5, and 8 and array 2
* has the values 1, 0, 4, and 6, the function assigns array 3 the values 3, 4, 9, and 14. The
* function should take three array names and an array size as arguments. Test the function
* in a simple program.
*/

#include<stdio.h>
#define DIMENSION_OF(a) (sizeof(a)/sizeof((a)[0]))
#define BEYOND(a) ((a)+DIMENSION_OF(a))

void dot_product(int *target, const int *source1, const int *source2, int length);
void print_iseq(FILE *stream, const int *start, const int *end);

int main(void)
{
   int arr1[] = {2, 4, 5, 8};
   int arr2[] = {1, 0, 4, 6};
   int arr3[DIMENSION_OF(arr1)];

   dot_product(arr3, arr1, arr2, DIMENSION_OF(arr1));
   print_iseq(stdout, arr3, BEYOND(arr3));
   
   return 0;
}

void dot_product(int *target, const int *source1, const int *source2, int length)
{
   while(length--)
      *target++ = *source1++ + *source2++;
}

void print_iseq(FILE *stream, const int *start,const int *end)
{
   while(start<end)
      fprintf(stream, "%d ", *start++);
   putc('\n', stream);
}