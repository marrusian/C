/*
*  16. Daphne invests $100 at 10% simple interest. (That is, every year, the investment earns
* an interest equal to 10% of the original investment.) Deirdre invests $100 at 5% interest
* compounded annually. (That is, interest is 5% of the current balance, including previous
* addition of interest.) Write a program that finds how many years it takes for the value
* of Deirdre’s investment to exceed the value of Daphne’s investment. Also show the two
* values at that time.
*/

#include<stdio.h>

int main(void)
{
   const double DEIRDRE_INTEREST = 1.05;
   const double DAPHNE_INTEREST = 1.10;
   double daphne_acc, deirdre_acc;
   int years;

   daphne_acc=deirdre_acc=100.0;
   years=0;
   for(double daphne_temp = daphne_acc; deirdre_acc<=daphne_acc; ++years){
      deirdre_acc*=DEIRDRE_INTEREST;
      daphne_acc+=daphne_temp*DAPHNE_INTEREST;
   }

   printf("It takes %d years for Deirdre's investment to exceed Daphne's investment.\n"
          "Daphne's account: $%.2f\n"
          "Deirdre's account: $%.2f\n", 
          years, daphne_acc, deirdre_acc);

   return 0;
}
