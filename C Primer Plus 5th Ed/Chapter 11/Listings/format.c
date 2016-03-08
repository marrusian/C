#include<stdio.h>

#define MAX 20

char *s_gets(char *st, int n);

int main(void)
{
   char first[MAX] = {0}, last[MAX] = {0}, formal[2*MAX+10] = {0};
   double prize = 0.0;

   puts("Enter your first name:");
   s_gets(first, MAX);
   puts("Enter your last name:");
   s_gets(last, MAX);
   puts("Enter your prize money:");
   scanf("%lf", &prize);
   sprintf(formal,"%s, %-19s: $%6.2f\n", last, first, prize);
   puts(formal);

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