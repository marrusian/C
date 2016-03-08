/*
*  1. Write a program that asks for your first name, your last name, and then prints the names
* in the format last, first.
*/

#include<stdio.h>

int main(void)
{
  char fname[15] = {}, lname[15] = {};

  printf("Enter your name(first + last): ");
  scanf("%s%s",fname,lname);
  printf("Hello, %s %s!\n", fname, lname);

  return 0;
}