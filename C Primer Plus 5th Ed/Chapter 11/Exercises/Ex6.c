/*
*  6. Write a function called is_within() that takes a character and a string pointer as its two
* function parameters. Have the function return a nonzero value (true) if the character is
* in the string and zero (false) otherwise. Test the function in a complete program that uses
* a loop to provide input values for feeding to the function.
*/

#include<stdio.h>
#define SIZE 80

int is_within(int ch, const char *str);

int main(void)
{
   char arr[SIZE] = {0};
   int token = 0;

   printf("Enter a character string: ");
   while(fgets(arr, SIZE, stdin)){
      printf("Enter the character to search for: ");

      while((token=getchar())==EOF)
         continue;

      if(token!='\n')
         while(getchar()!='\n')
            continue;
      
      if(is_within(token,arr))
         printf("Character \'%c\' is in the string.\n", token);
      else
         puts("Character not found!");

      printf("Enter another character string (EOF to quit): ");
   }
   putchar('\n');

   return 0;
}

int is_within(int ch, const char *str)
{
   while(*str!=ch && *str)
      ++str;
   return *str? 1 : 0;
}