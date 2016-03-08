/*
*  7. Write a program that reads a single word into a character array and then prints the word
* backward. Hint: Use strlen() (Chapter 4) to compute the index of the last character in
* the array.
*/

#include<stdio.h>
#include<string.h>

int main(void)
{
   char str[30] = {};
   
   printf("Enter a word: ");
   scanf("%s", str);
   
   for(int i=strlen(str); i>=0; --i)
      printf("%c", str[i]);
   printf("\n");

   return 0;
}