/*
*  1. Write a program that creates an array with 26 elements and stores the 26 lowercase
* letters in it. Also have it show the array contents.
*/

#include<stdio.h>

int main(void)
{
   const size_t SIZE = 26;
   char lwc_letters[SIZE];
   
   lwc_letters[0] = 'a';
   for(size_t i = 1; i < SIZE; ++i){
      lwc_letters[i] = lwc_letters[i-1]+1;
      printf("%c\n", lwc_letters[i-1]);
   }
   printf("%c\n", lwc_letters[SIZE-1]);

   return 0;
}