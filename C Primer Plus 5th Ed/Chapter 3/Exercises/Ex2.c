/*
* 2. Write a program that asks you to enter an ASCII code value, such as 66, and then prints
* the character having that ASCII code.
*/

#include<stdio.h>

int main(void)
{
  char ch;
  printf("Enter an ASCII code value: ");
  scanf("%hhd",&ch);
  printf("The character having code %hhd is \'%c\'\n", ch, ch);

  return 0;
}