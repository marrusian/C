/*
*  14. Write a program that prompts the user to enter three sets of five double numbers each.
* (You may assume the user responds correctly and doesn’t enter non-numeric data.) The
* program should accomplish all of the following:
*
*    a. Store the information in a 3×5 array.
*    b. Compute the average of each set of five values.
*    c. Compute the average of all the values.
*    d. Determine the largest value of the 15 values.
*    e. Report the results.
*
*   Each major task should be handled by a separate function using the traditional C
* approach to handling arrays. Accomplish task “b” by using a function that computes
* and returns the average of a one-dimensional array; use a loop to call this function three
* times. The other tasks should take the entire array as an argument, and the functions
* performing tasks “c” and “d” should return the answer to the calling program.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<inttypes.h>
#include<float.h>
#include<errno.h>

#define BEYOND(a) ((a)+DIMENSION_OF(a))

#define ROWS 3
#define COLS 5

double get_double(void);
double mean_dvalue(size_t length, const double arr[length]);
double find_dmax(size_t length, const double arr[length]);

int main(void)
{
   double arr[ROWS][COLS];
   for(int i=0; i<ROWS; ++i){
      printf("\nEnter the %d%s set of five floating-point numbers:\n",
              i+1, i? (i==1? "nd" : "rd") : "st");    
      for(int j=0; j<COLS; ++j)
         arr[i][j] = get_double();
   }

   for(int i=0; i<ROWS; ++i)
      printf("%d%s average: %g\n", i+1, i? (i==1? "nd" : "rd") : "st",
             mean_dvalue(sizeof(arr[i])/sizeof(arr[i][i]),arr[i]));

   printf("The average value of all sets: %g\n",
          mean_dvalue(sizeof(arr)/sizeof(arr[0][0]), (double*)arr));
   printf("The largest value of all sets: %g\n",
          find_dmax(sizeof(arr)/sizeof(arr[0][0]), (double*)arr));

   return 0;
}

double mean_dvalue(size_t length, const double arr[length])
{
   double total = 0.0;

   for(uint_fast32_t i=0; i<length; ++i)
      total += arr[i];

   return total/length;
}

double find_dmax(size_t length, const double arr[length])
{
   double max=-DBL_MAX;

   for(uint_fast32_t i=0; i<length; ++i)
      if(max<arr[i])
         max=arr[i];

   return max;
}

double get_double(void)
{
   char buffer[256] = {'\0'};
   char *end;
   double val;

   printf("Enter a floating-point number: ");
   do{ 
      if(buffer[0])
         printf("Please enter a floating-point number: ");
      scanf("%s", buffer);
      errno = 0;
      val = strtod(buffer, &end);
      if(errno==ERANGE)
         perror("Error");
   }while((!feof(stdin) && *end) || errno);

   return val;
}