/*
*   3. Write a program that asks the user to enter the number of days and then converts that
*  value to weeks and days. For example, it would convert 18 days to 2 weeks, 4 days.
*  Display results in the following format:
*      18 days are 2 weeks, 4 days.
*   Use a while loop to allow the user to repeatedly enter day values; terminate the loop
*  when the user enters a nonpositive value, such as 0 or -20.
*/

#include<stdio.h>

int main(void)
{
  const int DAYS_PER_WEEK = 7;
  int days = 0;

  printf("Enter the number of days (<=0 to quit): ");
  scanf("%d", &days);
  while(days>0){
    printf("%d days are %d weeks, %d days.\n", days,
           days/DAYS_PER_WEEK, days%DAYS_PER_WEEK);
    printf("Enter a new value (<=0 to quit): ");
    scanf("%d", &days);   
  }
  
  return 0;
}