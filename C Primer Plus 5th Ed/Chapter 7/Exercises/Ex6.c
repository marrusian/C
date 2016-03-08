/*
*  6. Write a program that reads input up to # and reports the number of times that the
* sequence "ei" occurs.
*/

#include<stdio.h>

int main(void)
{
   char prev = '\0', ch = '\0';
   int sequence_count = 0;

   printf("Enter characters (# to quit): ");
   while((ch=getchar())!='#'){
      if(prev=='e' && ch=='i') ++sequence_count;
      prev = ch;
   }

   printf("The sequence \"ei\" appeared %d times.\n", sequence_count);
   return 0;
}