#include<stdio.h>
#include<string.h>
#include<inttypes.h>

#define NAME "GIGATHINKG, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

void show_n_char(char ch, int_fast32_t num);

int main(void)
{  
   int_least32_t spaces = 0;

   show_n_char('*',WIDTH);
   putchar('\n');

   spaces = (WIDTH-strlen(NAME))/2;
   show_n_char(SPACE, spaces);
   printf("%s\n", NAME);

   spaces = (WIDTH-strlen(ADDRESS))/2;
   show_n_char(SPACE, spaces);
   printf("%s\n", ADDRESS);

   show_n_char(SPACE, (WIDTH-strlen(PLACE))/2);
   printf("%s\n", PLACE);

   show_n_char('*',WIDTH);
   putchar('\n');  
 
   return 0;
}

void show_n_char(char ch, int_fast32_t num)
{
   for(int_fast32_t count = 1; count<=num; ++count)
      putchar(ch);
}