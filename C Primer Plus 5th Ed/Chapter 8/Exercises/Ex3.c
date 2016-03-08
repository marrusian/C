/*
*  3. Write a program that reads input as a stream of characters until encountering EOF.
* Have it report the number of uppercase letters, the number of lowercase letters, and the
* number of other characters in the input. You may assume that the numeric values for the
* lowercase letters are sequential and assume the same for uppercase. Or, more portably,
* you can use appropriate classification functions from the ctype.h library.
*/

#include<stdio.h>
#include<inttypes.h>
#include<ctype.h>

int main(void)
{
   int_fast32_t ch = 0;
   int_fast32_t uppercase = 0, lowercase = 0, other = 0;
 
   while((ch=getchar())!=EOF){
      if(islower(ch)) ++lowercase;
      else if(isupper(ch)) ++uppercase;
      else ++other;
   }
   
   printf("\nLowercase letters: %" PRIdFAST32 "\n", lowercase);
   printf("Uppercase letters: %" PRIdFAST32 "\n", uppercase);
   printf("Other characters: %" PRIdFAST32 "\n", other);

   return 0;
}