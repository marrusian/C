#include<stdio.h>

int main(void)
{
   const int FREEZING = 0;
   float temperature = 0.0f;
   int cold_days = 0;
   int all_days = 0;

   printf("Enter the list of daily low temperatures.\n");
   printf("Use Celsius, and enter q to quit.\n");

   while(scanf("%f", &temperature)){
      ++all_days;
      if(temperature<FREEZING) ++cold_days;
   }
   if(all_days)
      printf("%d days total: %.1f%% were below freezing.\n",
             all_days, 100.0*cold_days/all_days);
   else
      printf("No data entered!\n");

   return 0;
}