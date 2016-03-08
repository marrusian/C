/*
*  2. Modify and test the function in exercise 1 so that it stops after n characters or after the
* first blank, tab, or newline, whichever comes first. (Don’t just use scanf().)
*/

#include<stdio.h>
#include<ctype.h>

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
   int ch = 0;
   while(n-- && !isspace(ch=getchar()) && !feof(stdin))
      *buffer++=ch;

   *buffer='\0';
}