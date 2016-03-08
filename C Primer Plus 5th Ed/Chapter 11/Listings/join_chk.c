#include<stdio.h>
#include<string.h>

#define SIZE 30
#define BUGSIZE 13
#define NullCharacter 1

char *s_gets(char *st, int n);

int main(void)
{
   char flower[SIZE];
   char addon[] = "s smell like old shoes.";
   char bug[BUGSIZE];
   int available;

   puts("What is your favorite flower?");
   s_gets(flower, SIZE);

   if((strlen(addon)+strlen(flower)+NullCharacter) <= SIZE)
      strcat(flower, addon);
   puts(flower);

   puts("What is your favorite bug?");
   s_gets(bug, BUGSIZE);

   available = BUGSIZE - strlen(bug) - NullCharacter;
   strncat(bug, addon, available);
   puts(bug);

   return 0;
}

char *s_gets(char *st, int n)
{
   char *ret_val;
   int i = 0;

   if(ret_val = fgets(st, n, stdin)){
      while(st[i]!='\n' && st[i])
         ++i;
      if(st[i]=='\n')
         st[i]='\0';
      else
         while(getchar()!='\n')
            continue;
   }

   return ret_val;
}