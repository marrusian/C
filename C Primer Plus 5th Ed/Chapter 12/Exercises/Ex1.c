/*
* 1. Rewrite the program in Listing 12.4 so that it does not use global variables.
*/

#include<stdio.h>

void critic(int *units);

int main(void)
{
   int units = 0;
   
   puts("How many pounds to a firkin of butter?");
   scanf("%d", &units);
   while(units!=56)
      critic(&units);
   puts("You must have looked it up!");

   return 0;
}

void critic(int *units)
{
   puts("No luck, my friend. Try again.");
   scanf("%d", units);
}