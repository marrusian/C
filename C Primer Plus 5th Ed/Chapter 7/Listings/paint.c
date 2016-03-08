/*
*  The program calculates how many cans of paint are needed to paint a given number of square feet.
*  The basic algorithm is simple:
*
*     Divide the square footage by the number of square feet covered per can. However, suppose the
*    answer is 1.7 cans. Stores sell whole cans, not fractional cans, so you would have to buy two
*    cans. Therefore, the program should round up to the next integer when a fractional paint can
*    is involved.
*/

#include<stdio.h>
#define COVERAGE 350  // square feet per paint can

int main(void)
{
   int sq_feet = 0, cans = 0;
 
   printf("Enter the number of square feet to be painted:\n");
   while(scanf("%d", &sq_feet)){
      cans = sq_feet/COVERAGE;
      cans += !(sq_feet%COVERAGE)? 0 : 1;
      printf("You need %d %s of paint.\n", cans,
             cans==1? "can" : "cans");
      printf("Enter next value(q to quit):\n");
   }
 
   return 0;
}