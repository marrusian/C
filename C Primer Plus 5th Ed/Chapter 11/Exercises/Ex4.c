/*
*  4. Design and test a function like that described in Programming Exercise 3 except that it
* accepts a second parameter specifying the maximum number of characters that can be
* read.
*/

#include<stdio.h>
#include<ctype.h>
#define SIZE 20

void getn_w(char *buffer, size_t n);

int main(void)
{
   char arr[SIZE];
  
   printf("Enter something: ");
   getn_w(arr, SIZE-1);
   puts(arr);

   return 0;
}

void getn_w(char *buffer, size_t n)
{
   int ch = 0;

   // Skip leading whitespace
   while(isspace(ch=getchar()))
      continue;
   
   if(ungetc(ch,stdin)!=EOF){
      // Fetch word of maximum 'n' characters long
      while(n-- && !isspace(ch=getchar()) && !feof(stdin))
         *buffer++ = ch;

      // Discard rest of line
      if(ch!='\n')
         while(!feof(stdin) && getchar()!='\n')
            continue;  
   }
   
   *buffer = '\0';
} 