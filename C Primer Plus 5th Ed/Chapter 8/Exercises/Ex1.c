/*
*  1. Devise a program that counts the number of characters in its input up to the end of file.
*/

#include<stdio.h>
#include<inttypes.h>

int main(void)
{
   int_fast32_t ch = 0, chars_count = 0;
   
   while((ch=getchar())!=EOF)
      ++chars_count;

   printf("%" PRIdFAST32 " characters read!\n",chars_count);      

   return 0;
}