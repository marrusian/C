/*
*  10. The 1988 United States Federal Tax Schedule was the simplest in recent times. It had
* four categories, and each category had two rates. Here is a summary (dollar amounts are
* taxable income):
*
*    Category              Tax
*    Single                15% of first $17,850 plus 28% of excess
*    Head of Household     15% of first $23,900 plus 28% of excess
*    Married, Joint        15% of first $29,750 plus 28% of excess
*    Married, Separate     15% of first $14,875 plus 28% of excess
*
*   For example, a single wage earner with a taxable income of $20,000 owes 0.15 × $17,850
* + 0.28 × ($20,000−$17,850). Write a program that lets the user specify the tax category
* and the taxable income and that then calculates the tax. Use a loop so that the user can
* enter several tax cases.
*/

#include<stdio.h>
#define BASIC_TAXRATE 0.15
#define EXCESS_TAXRATE 0.28

void menu(void);

int main(void)
{
   double tax = 0.0;
   double category_break = 0.0;
   double income = 0.0;

   int choice = 0;
   menu();
   while(scanf("%d",&choice) && choice!=5){
      switch(choice){
         case 1: category_break = 17850.0; break;
         case 2: category_break = 23900.0; break;
         case 3: category_break = 29750.0; break;
         case 4: category_break = 14875.0; break;
         default: printf("Invalid value. Try again!\n");
                  menu(); continue;
      }

      printf("Please enter your annual income: ");
      scanf("%lf", &income);
      
      if(income<=category_break)
         tax = BASIC_TAXRATE*income;
      else
         tax = BASIC_TAXRATE*category_break + EXCESS_TAXRATE*(income-category_break);
      
      printf("At an annual income of $%.2f, your tax is $%.2f\n",
             income, tax);
      menu();
   }
   
   return 0;
}

void menu(void)
{
   printf("\nEnter the number corresponding to the desired category:\n");
   printf("1)Single\n"
          "2)Head of household\n"
          "3)Married, Joint\n"
          "4)Married, Separate\n"
          "5)quit\n");
}