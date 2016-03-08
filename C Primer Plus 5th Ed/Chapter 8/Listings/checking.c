#include<stdio.h>
#include<stdbool.h>

long get_long(void);
bool bad_limits(long begin, long end,
                long low, long high);
double sum_squares(long a, long b);

int main(void)
{
   const long MIN = -10000000L;
   const long MAX = +10000000L;

   long start = 0, stop = 0;
   double answer = 0.0;

   printf("This program computes the sum of the squares of " 
          "integers in a range.\nThe lower bound should not "
          "be less than -10000000 and\nthe upper bound "
          "should not be more than +10000000.\nEnter the "
          "limits (enter 0 for BOTH limits to QUIT):\n");

   printf("Lower limit: ");
   start = get_long();
   printf("Upper limit: ");
   stop = get_long();
   while(start!=0 || stop!=0){
      if(bad_limits(start, stop, MIN, MAX))
         printf("Please try again.\n");
      else{
         answer = sum_squares(start,stop);
         printf("The sum of the squares of the integers ");
         printf("from %ld to %ld is %g\n", start, stop, answer);
      }

      printf("\nEnter the limits (enter 0 for BOTH limits to QUIT):\n");
      printf("Lower limit: ");
      start = get_long();
      printf("Upper limit: ");
      stop = get_long();
   }

   return 0;
}

long get_long(void)
{
   double input = 0;
   char ch = '\0';

   while(!scanf("%lf",&input) || (long)input!=input){
      if((ch=getchar())=='\n')
         printf("%.2f",input);
      else{
         putchar(ch);
         while((ch=getchar())!='\n')
            putchar(ch);
      }
      printf(" is not an integer.\n Please enter an integer: ");  
   }

   return (long)input;
}

bool bad_limits(long begin, long end,
                long low, long high)
{
   bool not_good = false;
  
   if(begin>end){
      printf("%ld isn't smaller than %ld.\n", begin, end);
      not_good = true;
   }
   if(begin<low || end>high){
      printf("Values must be in the [%ld,%ld] range.\n", low, high);
      not_good = true;
   }

   return not_good;
}

double sum_squares(long a, long b)
{
   double total = 0.0;
   
   for(long i = a; i<=b; ++i)
      total += (double)i * (double)i;

   return total;
}