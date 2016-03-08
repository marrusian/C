/*
*  5. There are approximately 3.156 × 10^7 seconds in a year. Write a program that requests
* your age in years and then displays the equivalent number of seconds.
*/

#include<stdio.h>

int main(void)
{ 
  const double SECONDS_IN_YEAR = 3.156E7;
  int age = 0;
  
  printf("Enter your age(in years): ");
  scanf("%d", &age);
  printf("%d years are equivalent to %e seconds\n", age, SECONDS_IN_YEAR*age);

  return 0;
}