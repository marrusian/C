/*
*  3. Design and test a function that reads the first word from a line of input into an array and
* discards the rest of the line. It should skip over leading whitespace. Define a word as a
* sequence of characters with no blanks, tabs, or newlines in it. Use getchar(), not scanf().
*/

#include<stdio.h>
#include<ctype.h>
#define SIZE 20

void get_w(char *buffer);

int main(void)
{
   char arr[SIZE];
   
   printf("Enter something: ");
   get_w(arr);
   puts(arr);

   return 0;
}

void get_w(char *buffer)
{
   int ch = 0;

   // Discard leading whitespace
   while(isspace(ch=getchar()))
      continue;
   
   if(ungetc(ch, stdin)!=EOF){
      // Fetch word
      while(!isspace(ch=getchar()) && !feof(stdin))
         *buffer++ = ch;

      // Discard the rest of line
      if(ch!='\n')
         while(!feof(stdin) && getchar()!='\n')
            continue;
   }

   *buffer = '\0';
}