/*
*  9. Write a program that initializes a two-dimensional 3×5 array-of-double and uses a VLA-
* based function to copy it to a second two-dimensional array. Also provide a VLA-based
* function to display the contents of the two arrays. The two functions should be capable,
* in general, of processing arbitrary N×M arrays. (If you don’t have access to a VLA-capable
* compiler, use the traditional C approach of functions that can process an N×5 array).
*/

#include<stdio.h>
#define DIMENSION_OF(a) (sizeof(a)/sizeof((a)[0]))

void copy_dmatr(int rows, int cols, double dest[rows][cols], const double source[rows][cols]);
void print_dmatrix(int rows, int cols, const double matr[rows][cols]);

int main(void)
{
   const double dmatr[3][5] =
   {
      {2.1, -4.5, 6.43, 2.2, 1.1},
      {9.63, 2.11, 14.23, -5.63, 2.1},
      {23.1, -3.1, 3.25, 6.74, -8.43}
   };

   double dmatr_new[3][5];
   copy_dmatr(DIMENSION_OF(dmatr), DIMENSION_OF(dmatr[0]), dmatr_new, dmatr);
   print_dmatrix(DIMENSION_OF(dmatr_new), DIMENSION_OF(dmatr_new[0]), dmatr_new);

   return 0;
}

void copy_dmatr(int rows, int cols, double dest[rows][cols], const double source[rows][cols])
{
   for(int i=0; i<rows; ++i)
      for(int j=0; j<cols; ++j)
         dest[i][j] = source[i][j];
}

/* 
*  Traditional C style:
* void copy_dmatr(double *dest, double *source, int rows, int cols)
* {
*    for(int i=0, limit=rows*cols; i<limit; i+=cols)
*       for(int j=0; j<cols; ++j)
*          dest[i+j] = source[i+j];
* }
*/

void print_dmatrix(int rows, int cols, const double matr[rows][cols])
{
   for(int i=0; i<rows; ++i){
      for(int j=0; j<cols; ++j)
         printf("%.2f ", matr[i][j]);
      putchar('\n');
   }
}