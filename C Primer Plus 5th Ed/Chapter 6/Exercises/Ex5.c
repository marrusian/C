/*
*   5. Have a program request the user to enter an uppercase letter. Use nested loops to produce
*  a pyramid pattern like this:
*
*      A
*     ABA
*    ABCBA
*   ABCDCBA
*  ABCDEDCBA
*
*  The pattern should extend to the character entered. For example, the preceding pattern
* would result from an input value of E.
*/

#include<stdio.h>

int main(void)
{
   const char REAR_LETTER = 'A';
   char limit_letter = '\0';
   char middle_letter = '\0';
   size_t loops = 0;

   printf("Enter a letter in the range [A,Z]: ");
   scanf(" %c", &limit_letter);
   loops = limit_letter-'A';

   middle_letter = REAR_LETTER;
   for(size_t i=0; i<=loops; ++i, ++middle_letter){
      char loop_letter=REAR_LETTER;

      for(size_t blanks=0; blanks<(loops-i); ++blanks) 
         printf(" ");

      while(loop_letter<=middle_letter)
         printf("%c", loop_letter++);
      --loop_letter;

      while(--loop_letter>=REAR_LETTER)
         printf("%c", loop_letter);
      
      printf("\n");
   }
   return 0;
}