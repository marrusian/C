/*
*  2. Devise a function chline(ch,i,j) that prints the requested character in columns i
* through j. Test it in a simple driver.
*/

#include<stdio.h>

void chline(char ch, int col_begin, int col_end);

int main(void)
{
   chline('*', 0, 18);
   printf("\nTHIS IS A MESSAGE!\n");
   chline('*', 0, 18);
   putchar('\n');

   return 0;
}

void chline(char ch, int col_begin, int col_end)
{
#define SPACE ' '
   for(int i=0; i<col_begin; ++i)
      putchar(SPACE);

   while(col_begin++<=col_end){
      putchar(ch);
   }
}