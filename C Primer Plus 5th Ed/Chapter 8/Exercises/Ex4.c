/*
*  4. Write a program that reads input as a stream of characters until encountering EOF. Have
* it report the average number of letters per word. Don’t count whitespace as being letters
* in a word. Actually, punctuation shouldn’t be counted either, but don’t worry about that
* now. (If you do want to worry about it, consider using the ispunct() function from the
* ctype.h family.)
*/

#include<stdio.h>
#include<stdbool.h>
#include<inttypes.h>
#include<ctype.h>

int main(void)
{
   int_fast32_t ch = 0;
   int_fast32_t total_letters = 0, words = 0;
   bool in_word = false;
 
   while((ch=getchar())!=EOF){
      if(isspace(ch) || ispunct(ch)) in_word = false;
      else{
         if(!in_word){
            in_word = true;
            ++words;
         }
         ++total_letters;
      }
   }

   printf("The average number of letters per word is: %.1f\n", (double)total_letters/words);

   return 0;
}