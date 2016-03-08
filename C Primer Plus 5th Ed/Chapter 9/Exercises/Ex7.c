/*
*  7. Write a program that reads characters from the standard input to end-of-file. For each
* character, have the program report whether it is a letter. If it is a letter, also report
* its numerical location in the alphabet. For example, c and C would both be letter 3.
* Incorporate a function that takes a character as an argument and returns the numerical
* location if the character is a letter and that returns –1 otherwise.
*/

#include<stdio.h>
#include<ctype.h>
#include<inttypes.h>

int_fast32_t alph_locator(char ch);

int main(void)
{
   int_fast32_t ch = 0;
   int_fast32_t pos = 0;
 
   while((ch=getchar())!=EOF){
      pos=alph_locator(ch);
      if(pos!=-1){
         putchar(ch);
         ch=toupper(ch);
         printf(" is the %2" PRIdFAST32 "%s letter in the alphabet.\n",
                pos, ch=='A'? "st" : (ch=='B'? "nd" : "th"));
      }
   }

   return 0;
}

int_fast32_t alph_locator(char ch)
{
   if(isalpha(ch)){
      ch=toupper(ch);
      return (ch-'A')+1;
   }
   
   return -1;
}