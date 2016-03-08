#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "diceroll.h"

int main(void)
{
   int dice, roll;
   int sides;

   srand((unsigned int)time(0));
   printf("Enter the number of sides per die, 0 to stop.\n");
   while(scanf("%d",&sides) && sides>0){
      printf("How many dice?\n");
      if(!scanf("%d",&dice)){
            printf("You should have entered an integer.");
            printf(" Let's begin again.\n");
            while(getchar()!='\n')
               continue;
            printf("How many sides? Enter 0 to stop.\n");
            continue;
      }
      if(feof(stdin))
         break;
      roll = roll_n_dice(dice, sides);
      printf("You have rolled a %d using %d %d-sided dice.\n",
             roll, dice, sides);
      printf("How many sides? Enter 0 to stop.\n");
   }
   printf("The rollem() function was called %d times.\n", roll_count);

   return 0;
}