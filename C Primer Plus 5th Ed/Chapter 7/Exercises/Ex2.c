/*
*  2. Write a program that reads input until encountering #. Have the program print each
* input character and its ASCII decimal code. Print eight character-code pairs per line.
* Suggestion: Use a character count and the modulus operator (%) to print a newline
* character for every eight cycles of the loop.
*/

#include<stdio.h>
#define LOOP_CYCLE 8

int main(void)
{
   char ch = '\0';

   for(int i=1; (ch=getchar())!='#'; ++i)
      if(ch!='\n'){
         printf("\'%c\' - %3d  ", ch, ch);
         if(!(i%=LOOP_CYCLE)) putchar('\n');
      }
      else{
         i=0;
         putchar('\n');
      }
   putchar('\n');

   return 0;
}