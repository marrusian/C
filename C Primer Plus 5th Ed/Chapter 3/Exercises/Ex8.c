/*
*  8. In the U.S. system of volume measurements, a pint is 2 cups, a cup is 8 ounces, an
* ounce is 2 tablespoons, and a tablespoon is 3 teaspoons. Write a program that requests a
* volume in cups and that displays the equivalent volumes in pints, ounces, tablespoons,
* and teaspoons.
*/

#include<stdio.h>

int main(void)
{
  const int PINT_PER_CUP = 2;
  const int CUP_PER_OUNCE = 8;
  const int TBSP_PER_CUP = CUP_PER_OUNCE*2;
  const int TSP_PER_CUP = TBSP_PER_CUP*3;
  float vol_in_cups = 0.0f;

  printf("Enter a volume in cups: ");
  scanf("%f",&vol_in_cups);
  printf("%f cups are equivalent to:\n",vol_in_cups);
  printf("   %f pints\n"
         "   %f ounces\n"
         "   %f tablesppons\n"
         "   %f teaspoons\n",
         (1.0/PINT_PER_CUP)*vol_in_cups,
         CUP_PER_OUNCE*vol_in_cups,
         TBSP_PER_CUP*vol_in_cups,
         TSP_PER_CUP*vol_in_cups);

  return 0;
}