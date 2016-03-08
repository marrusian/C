/*
*  4. Write a program that requests your height in inches and your name, and then displays
*  the information in the following form:
*       "Dabney, you are 6.208 feet tall"
*    Use type float, and use / for division. If you prefer, request the height in centimeters
*  and display it in meters.
*/

#include<stdio.h>
#define CM_IN_METERS 100

int main(void)
{
  float height = 0.0f;
  char name[15] = {};
  
  printf("Enter your height(in centimeters) and your name: ");
  scanf("%f%s", &height, name);
  printf("%s, you are %.3f meters tall!\n", name, height/CM_IN_METERS);

  return 0;
}