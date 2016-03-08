/*
*  7. Write a program that requests the hours worked in a week and then prints the gross pay,
* the taxes, and the net pay. Assume the following:
*    a. Basic pay rate = $10.00/hr
*    b. Overtime (in excess of 40 hours) = time and a half
*    c. Tax rate: 
          15% of the first $300
*         20% of the next $150
*         25% of the rest
*  Use #define constants, and don’t worry if the example does not conform to current
* tax law.
*/

#include<stdio.h>
#define BASIC_PAY_RATE 10.00
#define OVERTIME_RATE BASIC_PAY_RATE*1.5
#define OVERTIME_BREAK 40  // breakpoints for overtime bonus rate

#define TAX_BREAK1 300.0   // first breakpoint for tax rates
#define TAX_BREAK2 450.0   // second breakpoint for tax rates
#define TAX_RATE1 0.15 
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25
#define TAX_BASE1 (TAX_BREAK1*TAX_RATE1)
#define TAX_BASE2 (TAX_BASE1+TAX_RATE2*(TAX_BREAK2-TAX_BREAK1))

int main(void)
{
   int hours_worked = 0;
   double gross_pay = 0.0;
   double taxes = 0.0;
   double net_pay = 0.0;

   printf("Please enter the number of hours worked in a week: ");
   scanf("%d", &hours_worked);

   if(hours_worked-OVERTIME_BREAK > 0){
      gross_pay = (hours_worked-OVERTIME_BREAK)*OVERTIME_RATE;
      gross_pay += OVERTIME_BREAK*BASIC_PAY_RATE;
   }
   else 
      gross_pay = hours_worked*BASIC_PAY_RATE;

   if(gross_pay <= TAX_BREAK1)
      taxes = TAX_RATE1*gross_pay;
   else if(gross_pay <= TAX_BREAK2)
      taxes = TAX_BASE1 + (TAX_RATE2 * (gross_pay-TAX_BREAK1));
   else
      taxes = TAX_BASE2 + (TAX_RATE3 * (gross_pay-TAX_BREAK2));

   net_pay = gross_pay-taxes;
   
   printf("The gross pay per week for %d hours worked/week is $%.2f,\n",
          hours_worked, gross_pay);
   printf("from which $%.2f are taxes, resulting a net payment of $%.2f\n",
          taxes, net_pay);

   return 0;
}