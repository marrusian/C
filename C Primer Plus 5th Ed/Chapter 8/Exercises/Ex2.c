/*
*  2. Write a program that reads input as a stream of characters until encountering EOF. Have
* the program print each input character and its ASCII decimal value. Note that characters
* preceding the space character in the ASCII sequence are nonprinting characters.
* Treat them specially. If the nonprinting character is a newline or tab, print \n or \t,
* respectively. Otherwise, use control-character notation. For instance, ASCII 1 is Ctrl+A,
* which can be displayed as ^A. Note that the ASCII value for A is the value for Ctrl+A
* plus 64. A similar relation holds for the other nonprinting characters. Print 10 pairs per
* line, except start a fresh line each time a newline character is encountered. (Note: The
* operating system may have special interpretations for some control characters and keep
* them from reaching the program.)
*/

#include<stdio.h>
#include<inttypes.h>

#define ADJUST 64
#define CHARS_PER_LINE 10
#define RESET_COUNTER -1

int main(void)
{
   int_fast32_t ch = 0;
   int_fast32_t count = 0;

   for(int_fast32_t count = 0; (ch=getchar())!=EOF; ++count){
      if(!(count %= CHARS_PER_LINE)) putchar('\n');
      switch(ch){
         case '\n': printf("\\n - %3" PRIdFAST32 "", ch);
                    putchar('\n'); count = RESET_COUNTER; break;
         case '\t': printf("\\t - %3" PRIdFAST32 "", ch); break;
         default: if(ch<32) printf("^%c - %3" PRIdFAST32 "", ch+ADJUST, ch);  // control character
                  else printf("%2c - %3" PRIdFAST32 "", ch, ch);            
      } 
      putchar(' ');   
    }

   return 0;
}
