/*
*  1. Design and test a function that fetches the next n characters from input (including
* blanks, tabs, and newlines), storing the results in an array whose address is passed as an
* argument.
*/

#include<stdio.h>
#define SIZE 20

void getn(char *buffer, size_t n);

int main(void)
{
   char arr[SIZE];
   
   printf("Enter something: ");
   getn(arr, SIZE-1);
   puts(arr);
   
   return 0;
}

void getn(char *buffer, size_t n)
{
   while(n-- && !feof(stdin))
      *buffer++=getchar();

   if(feof(stdin))
      --buffer;

   *buffer='\0';
}