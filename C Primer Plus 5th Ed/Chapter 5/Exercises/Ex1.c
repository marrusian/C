/*
*  1. Write a program that converts time in minutes to time in hours and minutes. Use
* #define or const to create a symbolic constant for 60. Use a while loop to allow the
* user to enter values repeatedly and terminate the loop if a value for the time of 0 or less
* is entered.
*/

#include<stdio.h>

int main(void)
{
  const int MIN_PER_HOUR = 60;
  int minutes = 0;

  printf("Enter the number of minutes (<=0 to quit):\n");
  scanf("%d", &minutes);
  while(minutes>0){
    printf("%d minutes is %d hours, %d minutes.\n", minutes,
           minutes/MIN_PER_HOUR, minutes%MIN_PER_HOUR);
    printf("Enter next value (<=0 to quit):\n");
    scanf("%d", &minutes);
  }

  return 0;
}