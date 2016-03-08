/*
*  12. Consider these two infinite series:
*    1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
*    1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
*  Write a program that evaluates running totals of these two series up to some limit of
* number of terms. 
*/

#include<stdio.h>

int main(void)
{
   int t_ct;  // term count
   double limit, denominator;
   int max_loops = 0;
   int sign;

   printf("Enter the number of terms you want: ");
   scanf("%d", &max_loops);
   for(limit=0.0, t_ct=1, denominator=1.0, sign=1; t_ct<=max_loops;
       ++t_ct, ++denominator)
   {
      limit += sign*(1.0/denominator);
      sign*=-1;
      printf("limit = %f when terms = %d.\n", limit, t_ct);
   }

   return 0;
}