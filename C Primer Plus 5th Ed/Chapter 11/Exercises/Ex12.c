/*
*  12. Write a program that reads input up to EOF and reports the number of words, the
* number of uppercase letters, the number of lowercase letters, the number of punctuation
* characters, and the number of digits. Use the ctype.h family of functions.
*/

#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<inttypes.h>

#define WORDS   0
#define UP_CASE 1
#define LW_CASE 2
#define PUNCT   3
#define DIGITS  4

int main(void)
{
   uint_fast32_t data[5] = {0};
   int ch = 0;
   bool in_word = true;
   
   while((ch=getchar())!=EOF){
      if(isspace(ch))
         in_word = false;
      else{   
         if(islower(ch)) ++data[LW_CASE];
         else if(ispunct(ch)) ++data[PUNCT]; 
         else if(isupper(ch)) ++data[UP_CASE];
         else if(isdigit(ch)) ++data[DIGITS];
      }

      if(!in_word){
         ++data[WORDS];
         in_word = true;
      }
   }   
   putchar('\n');

   printf("Number of words: %" PRIuFAST32 "\n"
          "Number of uppercase letters: %" PRIuFAST32 "\n"
          "Number of lowercase letters: %" PRIuFAST32 "\n"
          "Number of punctuation characters: %" PRIuFAST32 "\n"
          "Number of digits: %" PRIuFAST32 "\n",
          data[WORDS], data[UP_CASE], data[LW_CASE],
          data[PUNCT], data[DIGITS]);
   
   return 0;
}