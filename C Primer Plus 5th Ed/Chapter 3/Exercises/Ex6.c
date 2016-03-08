/*
*  6. The mass of a single molecule of water is about 3.0×10-23 grams. A quart of water is
* about 950 grams. Write a program that requests an amount of water, in quarts, and
* displays the number of water molecules in that amount.
*/

#include<stdio.h>

int main(void)
{
  const double WATER_MOLECULE_MASS = 3.0E-23; // in grams
  const int WATER_QUART = 950; // in grams
  int quarts = 0;

  printf("Enter an amount of water(in quarts): ");
  scanf("%d",&quarts);
  printf("The number of water molecules in %d quarts of water is %e\n",
         quarts, (WATER_QUART/WATER_MOLECULE_MASS)*quarts);

  return 0;
}