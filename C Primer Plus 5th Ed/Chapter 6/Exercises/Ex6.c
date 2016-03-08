/*
*  6. Write a program that prints a table with each line giving an integer, its square, and its
* cube. Ask the user to input the lower and upper limits for the table. Use a for loop.
*/

#include<stdio.h>
#include<inttypes.h>
#include<time.h>
int main(void)
{
  int_fast32_t lower_limit = 0, upper_limit = 0;

  printf("Table of squares and cubes!\n");

  printf("Enter the lower limit of the table: ");
  scanf("%" SCNdFAST32 "", &lower_limit);
  printf("Now enter the upper limit: ");
  scanf("%" SCNdFAST32 "", &upper_limit);
  --lower_limit;

  #define n lower_limit
  printf("n                  n^2                n^3\n");

  while(++lower_limit<=upper_limit){
     printf("%-19" PRIdFAST64 "%-19" PRIdFAST64 "%-19" PRIdFAST64"\n",
            lower_limit, ((int_fast64_t)n)*n, ((int_fast64_t)n)*n*n);
  }

  return 0;
}