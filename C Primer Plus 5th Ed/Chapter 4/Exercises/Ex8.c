/*
*  8. Write a program that asks the user to enter the number of miles traveled and the number
*  of gallons of gasoline consumed. It should then calculate and display the miles-per-gallon
*  value, showing one place to the right of the decimal. Next, using the fact that one gallon
*  is about 3.785 liters and one mile is about 1.609 kilometers, it should convert the mile-
*  per-gallon value to a liters-per-100-km value, the usual European way of expressing fuel
*  consumption, and display the result, showing one place to the right of the decimal. Note
*  that the U. S. scheme measures the distance traveled per amount of fuel (higher is better),
*  whereas the European scheme measures the amount of fuel per distance (lower is better).
*  se symbolic constants (using const or #define) for the two conversion factors.
*/

#include<stdio.h>
#define GALLONS_PER_LITER 3.785
#define MILES_PER_KM 1.609

int main(void)
{
  double distance = 0.0; // measured in miles
  double cons_gasoline = 0.0; // measured in gallons
  double MpG = 0.0, LpK = 0.0;

  printf("Enter the number of miles traveled: ");
  scanf("%lf", &distance);
  printf("Enter the amount of gasoline consumed(in gallons): ");
  scanf("%lf", &cons_gasoline);

  MpG = distance/cons_gasoline;
  printf("U.S Scheme: You've traveled %.1f miles-per-gallon.\n", MpG);

  LpK = ((cons_gasoline*GALLONS_PER_LITER)/(distance*MILES_PER_KM))*100;
  printf("European Scheme: You consumed %.1f liters-per-km.\n", LpK);
 
  return 0;
}