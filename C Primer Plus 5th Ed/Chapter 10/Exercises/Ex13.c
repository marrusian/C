/*
*  13. Write a program that prompts the user to enter three sets of five double numbers each.
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
#include<errno.h>

#define BEYOND(a) ((a)+(sizeof(a)/sizeof((a)[0])))

#define ROWS 3
#define COLS 5

double get_double(void);
double mean_dvalue(const double *start, const double *end);
double find_dmax(const double *start, const double *end);

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
      printf("%d%s average: %.2f\n", i+1, i? (i==1? "nd" : "rd") : "st",
             mean_dvalue(arr[i],BEYOND(arr[i])));

   printf("The average value of all sets: %.2f\n", mean_dvalue((double*)arr, (double*)BEYOND(arr)));
   printf("The largest value of all sets: %.2f\n", find_dmax((double*)arr, (double*)BEYOND(arr)));

   return 0;
}

double mean_dvalue(const double *start, const double *end)
{
   ptrdiff_t length = end-start;
   double total = 0.0;

   while(start<end)
      total += *start++;

   return total/length;
}

double find_dmax(const double *start, const double *end)
{
   double max=*start;

   while(start<end){
      if(max<*start)
         max=*start;
      ++start;
   }

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