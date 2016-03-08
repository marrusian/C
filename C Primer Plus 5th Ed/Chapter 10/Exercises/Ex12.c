#include<stdio.h>
#include<inttypes.h>

#define BEYOND(a) ((a)+sizeof(a)/sizeof((a)[0]))

#define MONTHS 12
#define YEARS   5

float sum_arr(const float *start, const float *end, size_t scale_factor);

int main(void)
{
   // Initializing rainfall data for 2010-2014
   const float rain[YEARS][MONTHS] =
   {
      {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
      {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
      {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
      {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
      {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
   };

   float subtot = 0.0f, total = 0.0f;
   
   printf("YEAR     RAINFALL (inches)\n");
   for(uint_fast32_t year=0; year<YEARS; ++year){       
       printf("%" PRIdFAST32 " %15.1f\n", 2010+year, subtot = sum_arr(rain[year], BEYOND(rain[year]), 1));
       total+=subtot;  // Total for all years
   }

   printf("\nThe yearly average is %.1f inches.\n\n", total/YEARS);
   printf("MONTHLY AVERAGES:\n\n");
   printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");

   for(uint_fast32_t month=0; month<MONTHS; ++month){     
       printf("%3.1f ",
       sum_arr(rain[0]+month,(float*)BEYOND(rain), MONTHS)/YEARS);   
   }
   putchar('\n');

   return 0;
}  

float sum_arr(const float *start, const float *end, size_t scale_factor)
{
   float sum = 0.0;

   while(start<end){
      sum+=*start;
      start+=scale_factor;
   }

   return sum;
}