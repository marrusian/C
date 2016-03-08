#include<stdio.h>
#include<inttypes.h>

#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40

void starbar(void);

int main(void)
{
   starbar();
   printf("%s\n", NAME);
   printf("%s\n", ADDRESS);
   printf("%s\n", PLACE);
   starbar();

   return 0;
}

void starbar(void)
{
   for(int_fast32_t count=0; count<=WIDTH; ++count)
      putchar('*');
   putchar('\n');
}