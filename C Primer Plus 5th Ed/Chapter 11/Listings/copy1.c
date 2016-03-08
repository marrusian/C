#include<stdio.h>
#include<string.h>

#define SIZE 40
#define LIM   5

char *s_gets(char *st, int n);

int main(void)
{
   char qwords[LIM][SIZE] = {{'\0'}};
   char temp[SIZE];
   int i=0;

   printf("Enter %d words beginning with q:\n", LIM);
   while(i<LIM && s_gets(temp,SIZE)){
      if(temp[0]!='q')
         printf("%s doesn't begin with q!\n", temp);
      else{
         strcpy(qwords[i], temp);
         ++i;
      }
   }
   puts("Here are the words accepted:");
   for(i=0; i<LIM; ++i)
      if(qwords[i][0])
         puts(qwords[i]);

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