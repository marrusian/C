/*
*  3. Write a function that takes three arguments: a character and two integers. The character
* is to be printed. The first integer specifies the number of times that the character is to
* be printed on a line, and the second integer specifies the number of lines that are to be
* printed. Write a program that makes use of this function.
*/

#include<stdio.h>

void print_ch(char ch, int times, int rows);

int main(void)
{
   print_ch('*',10,2);
   printf("BLOCK OF STARS!\n");
   print_ch('*',10,2);
   putchar('\n');

   return 0;
}

void print_ch(char ch, int times, int rows)
{
   for(int i=1; i<=rows; ++i){
      for(int j=1; j<=times; ++j)
         putchar(ch);
      putchar('\n');
   }
}