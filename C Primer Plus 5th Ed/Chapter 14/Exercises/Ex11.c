/*
*  11. Write a function called transform() that takes four arguments: the name of a source
* array containing type double data, the name of a target array of type double, an int
* representing the number of array elements, and the name of a function (or, equivalently,
* a pointer to a function). The transform() function should apply the indicated function
* to each element in the source array, placing the return value in the target array. For
* example, the call:
*
*     transform(source, target, 100, sin);
*
* would set target[0] to sin(source[0]), and so on, for 100 elements. Test the function
* in a program that calls transform() four times, using two functions from the math.h
* library and two suitable functions of your own devising as arguments to successive calls
* of the transform() function.
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define SZ 100

double uniform_deviate(void){return rand()*(1.0/(RAND_MAX+1.0));}
void fill_darr(double arr[], size_t length);
void print_darr(double arr[], size_t length);
void transform(double source[], double target[], size_t length, double (*pfun)(double));

int main(void)
{
   double ar[SZ] = {0};
   double store[SZ] = {0};

   srand((unsigned int)time(0));
   fill_darr(ar, SZ);
  
   transform(ar, store, SZ, sin);
   print_darr(store, SZ);

   transform(ar, store, SZ, log10);
   print_darr(store, SZ);

   return 0;
}

void transform(double source[], double target[], size_t length, double (*pfun)(double))
// Pre-conditions: length(target)>=length(source)
{
   for(size_t i=0; i<length; ++i)
      target[i] = pfun(source[i]);
}

void print_darr(double arr[], size_t length)
{
   size_t i;
   for(i=0; i<length; ++i){
      if(!(i%8)) putchar('\n');
      printf("%8.5f ", arr[i]);
   }
   if(i%8) putchar('\n');
}

void fill_darr(double arr[], size_t length)
{
   for(size_t i=0; i<length; ++i)
      arr[i] = uniform_deviate()*length;
}