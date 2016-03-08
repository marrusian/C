/*
*  1. Write a program that reads input until encountering the # character and then reports
* the number of spaces read, the number of newline characters read, and the number of all
* other characters read.
*/

#include<stdio.h>

int main(void)
{
   int blanks = 0, newlines = 0;
   int nonspace = 0;
   char ch = '\0';

   printf("Enter characters(# to quit): ");
   while((ch=getchar())!='#'){
      switch(ch){
         case ' ': ++blanks; break;
         case '\n': ++newlines; break;
         default: ++nonspace;
      }
   }

   printf("Spaces: %d\n"
          "Newlines: %d\n"
          "Other characters: %d\n",
          blanks, newlines, nonspace);
 
   return 0;
}