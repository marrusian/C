#include<stdio.h>
#include"hotel.h"

void menu(void)
{
   printf("\n%s%s\n", STARS, STARS);
   printf("Enter the number of the desired hotel:\n");
   printf("1) Fairfield Arms         2) Hotel olympic\n"
          "3) Chertworthy Plaza      4) The Stockton\n"
          "5) Quit\n");
   printf("%s%s\n", STARS, STARS);
}

int get_code(void)
{
   float code = 0.0f;

   while(!scanf("%f", &code) || (int)code!=code || (code<1.0f || code>5.0f)){
      if(feof(stdin)) break;
      printf("Enter an integer from 1 to 5, please.\n");
      while(getchar()!='\n')
         continue;
   }

   if(!feof(stdin))
      while(getchar()!='\n')
         continue;

   return (int)code;
}

int get_nights(void)
{
   float nights = 0.0f;

   printf("How many nights are needed? ");
   while(!scanf("%f", &nights) || (int)nights!=nights){
      if(feof(stdin)) break;
      while(getchar()!='\n')
         continue;
      printf("Please enter an integer.\n");
   }

   if(!feof(stdin))
      while(getchar()!='\n')
         continue;

   return (int)nights;
}

void show_price(double rate, int nights)
{
   double total = 0.0;
   double factor = 1.0;
   
   for(int n = 1; n<=nights; ++n, factor *= DISCOUNT)
      total += rate*factor;

   printf("The total cost will be $%.2f.\n", total);
}