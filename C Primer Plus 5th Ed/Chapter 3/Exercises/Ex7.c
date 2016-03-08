/*
*  7. There are 2.54 centimeters to the inch. Write a program that asks you to enter your
* height in inches and then displays your height in centimeters. Or, if you prefer, ask for
* the height in centimeters and convert that to inches.
*/

#include<stdio.h>

int main(void)
{
  const float CM_PER_INCH = 2.54;
  float height = 0.0f;

  printf("Enter your height in centimeters: ");
  scanf("%f",&height);
  printf("Your height in inches is %f.\n", (1/CM_PER_INCH)*height);

  return 0;
}