/*
*  11. The ABC Mail Order Grocery sells artichokes for $2.05 per pound, beets for $1.15 per
* pound, and carrots for $1.09 per pound. It gives a 5% discount for orders of $100 or
* more prior to adding shipping costs. It charges $6.50 shipping and handling for any
* order of 5 pounds or under, $14.00 shipping and handling for orders over 5 pounds
* and under 20 pounds, and $14.00 plus $0.50 per pound for shipments of 20 pounds or
* more. Write a program that uses a switch statement in a loop such that a response of a
* lets the user enter the pounds of artichokes desired, b the pounds of beets, c the pounds
* of carrots, and q allows the user to exit the ordering process. The program should keep
* track of cumulative totals. That is, if the user enters 4 pounds of beets and later enters
* 5 pounds of beets, the program should use report 9 pounds of beets. The program then
* should compute the total charges, the discount, if any, the shipping charges, and the
* grand total. The program then should display all the purchase information: the cost per
* pound, the pounds ordered, and the cost for that order for each vegetable, the total cost
* of the order, the discount (if there is one), the shipping charge, and the grand total of all
* the charges.
*/

#include<stdio.h>
// All prices are in DOLLARS and PER POUND.
#define ARTICHOKES_PRICE 2.05
#define BEETS_PRICE 1.15
#define CARROTS_PRICE 1.09

#define DISCOUNT_RATE 0.05
#define DISCOUNT_BREAK 100

#define SHIPPING_TAX1 6.50
#define SHIPPING_TAX2 14.00
#define SHIPPING_TAX3 0.5   
#define SHIPPING_BREAK1 5   // pounds
#define SHIPPING_BREAK2 20  // pounds

void menu(void);
int request_order(const char* product);
double calculate_shipping(int pounds);

int main(void)
{
   int artichokes = 0, beets = 0, carrots = 0; // measured in pounds.   
   double total_charge = 0.0;
   double discount = 0.0;
   double shipping = 0.0;
   double grand_total = 0.0;

   char choice = '\0';
   menu();
   while(scanf(" %c", &choice) && choice!='q'){
      switch(choice){
         case 'a': artichokes += request_order("artichokes"); break;
         case 'b': beets += request_order("beets"); break;
         case 'c': carrots += request_order("carrots"); break;
         default: printf("Invalid choice. Try again!\n");
                  menu(); continue;
      }
      menu();
   }

   total_charge = artichokes*ARTICHOKES_PRICE + beets*BEETS_PRICE
                  + carrots*CARROTS_PRICE;

   if(total_charge>=DISCOUNT_BREAK)
      discount = total_charge*DISCOUNT_RATE;

   shipping = calculate_shipping(artichokes) + calculate_shipping(beets) +
              + calculate_shipping(carrots);

   grand_total = total_charge-discount+shipping;

   printf("For %d pounds of artichokes, %d pounds of beets\n"
          "and %d pounds of carrots we have:\n",
          artichokes, beets, carrots);
   printf("Total charges: $%.2f\n", total_charge);
   printf("Discount: $%.2f\n", discount);
   printf("Shipping taxes: $%.2f\n", shipping);
   printf("Grand total: $%.2f\n", grand_total);

   return 0;
}

void menu(void)
{
   printf("\nEnter the desired product:\n");
   printf("a) Artichokes\n"
          "b) Beets\n"
          "c) Carrots\n"
          "q) quit\n");
}

int request_order(const char* product)
{
   int amount = 0;

   printf("Enter the pounds of %s desired: ", product);
   scanf("%d",&amount);

   return amount;
}

double calculate_shipping(int pounds)
{
   double shipping_tax = 0.0;
   if(pounds>0){
      if(pounds<=SHIPPING_BREAK1)
         shipping_tax = SHIPPING_TAX1;
      else if(pounds<=SHIPPING_BREAK2)
         shipping_tax = SHIPPING_TAX2;
      else
         shipping_tax = SHIPPING_TAX2 + (pounds-SHIPPING_BREAK2)*SHIPPING_TAX3;
   }

   return shipping_tax;
}