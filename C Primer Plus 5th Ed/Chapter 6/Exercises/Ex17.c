/*
*  17. Chuckie Lucky won a million dollars (after taxes), which he places in an account that
* earns 8% a year. On the last day of each year, Chuckie withdraws $100,000. Write a
* program that finds out how many years it takes for Chuckie to empty his account.
*/

#include<stdio.h>

int main(void)
{
   const double MILLION_DOLLARS = 1000000.0;
   const double OHT_DOLLARS = 100000.0;
   const double INTEREST = 1.08;
 
   double chuck_account = MILLION_DOLLARS;
   int years;

   for(years=0; chuck_account>0; ++years){
      chuck_account*=INTEREST;     // 8% compound interest per year
      chuck_account-=OHT_DOLLARS;  // withdraws $100,000.00 each year
   } 

   printf("It takes %d years for Chuck to empty his account.\n", years);
   
   return 0;
}