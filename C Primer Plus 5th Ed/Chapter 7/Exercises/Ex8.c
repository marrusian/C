/*
*  8. Modify assumption a. in exercise 7 so that the program presents a menu of pay rates
*  from which to choose. Use a switch to select the pay rate. The beginning of a run
*  should look something like this:
* 
*      *****************************************************************
*      Enter the number corresponding to the desired pay rate or action:
*      1) $8.75/hr                         2) $9.33/hr   
*      3) $10.00/hr                        4) $11.20/hr
*      5) quit
*      *****************************************************************
*
*  If choices 1 through 4 are selected, the program should request the hours worked. The
* program should recycle until 5 is entered. If something other than choices 1 through 5
* is entered, the program should remind the user what the proper choices are and then
* recycle. Use #defined constants for the various earning rates and tax rates.
*/

#include<stdio.h>
#define OVERTIME_BREAK 40  // breakpoints for overtime bonus rate

#define TAX_BREAK1 300.0   // first breakpoint for tax rates
#define TAX_BREAK2 450.0   // second breakpoint for tax rates
#define TAX_RATE1 0.15 
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25
#define TAX_BASE1 (TAX_BREAK1*TAX_RATE1)
#define TAX_BASE2 (TAX_BASE1+TAX_RATE2*(TAX_BREAK2-TAX_BREAK1))

void menu(void);

int main(void)
{
   int hours_worked = 0;
   double gross_pay = 0.0;
   double taxes = 0.0;
   double net_pay = 0.0;
   
   int choice = 0;
   menu();
   while(scanf("%d",&choice) && choice!=5){
      double rate = 0.0;
      switch(choice){
         case 1: rate = 8.75; break;
         case 2: rate = 9.33; break;
         case 3: rate = 10.00; break;
         case 4: rate = 11.20; break;
         default: printf("That's not a valid value!\n");
                  menu(); continue;
      }
      const double BASIC_PAY_RATE = rate;
      const double OVERTIME_RATE = BASIC_PAY_RATE*1.5;

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

      menu();
   }

   return 0;
}

void menu(void)
{
   printf("\nEnter the number corresponding to the desired pay rate or action:\n");
   printf("1) $8.75/hr       2) $9.33/hr\n"
          "3) $10.00/hr      4) $11.20/hr\n"
          "5) quit\n");
} 