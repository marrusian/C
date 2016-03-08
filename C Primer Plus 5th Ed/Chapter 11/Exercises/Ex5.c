/*
*  5. Design and test a function that searches the string specified by the first function
* parameter for the first occurrence of a character specified by the second function
* parameter. Have the function return a pointer to the character if successful, and a null
* if the character is not found in the string. (This duplicates the way that the library
* strchr() function works.) Test the function in a complete program that uses a loop to
* provide input values for feeding to the function.
*/

#include<stdio.h>
#define SIZE 80

char *find_char(const char *str, int ch);

int main(void)
{
   char arr[SIZE] = {0};
   char *position;
   int token = 0;

   printf("Enter a character string: ");
   while(fgets(arr, SIZE, stdin)){
      printf("Enter the character to search for: ");

      while((token=getchar())==EOF)
         continue;

      if(token!='\n')
         while(getchar()!='\n')
            continue;
      
      if((position=find_char(arr,token)))
         printf("First occurence of \'%c\' found on position %td\n", token, position-arr);
      else
         puts("Character not found!");

      printf("Enter another character string (EOF to quit): ");
   }
   putchar('\n');

   return 0;
}

char *find_char(const char *str, int ch)
{
   while(*str!=ch && *str)
      ++str;
   return (*str||!ch)? str : NULL;
}
