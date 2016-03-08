#include<stdio.h>
#include<string.h>

char *s_gets(char *st, int n);

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book{
   char title[MAXTITL];
   char author[MAXAUTL];
   float value;
};

int main(void)
{
   struct book library[MAXBKS];
   int count = 0;

   puts("Please enter the book title.");
   puts("Press [enter] at the start of a line to stop");
   while(count<MAXBKS && s_gets(library[count].title, MAXTITL)
         && library[count].title[0]){

      puts("Now enter the author");
      s_gets(library[count].author, MAXAUTL);

      puts("Now enter the value");
      scanf("%f", &library[count++].value);
      while(getchar()!='\n')
         continue;

      if(count<MAXBKS)
         puts("Enter the next title");
   }

   if(count>0){
      puts("Here is the list of your books:");
      for(int i=0; i<count; ++i)
         printf("%s by %s: $%.2f\n", library[i].title,
                library[i].author, library[i].value);
   }
   else
      puts("No books? Too bad.");

   return 0;
}

char *s_gets(char *st, int n)
{
   char *ret_val, *find;

   if((ret_val=fgets(st, n, stdin))){
      if((find=strchr(st, '\n')))
         *find = '\0';
      else
         while(getchar()!='\n')
            continue;
   }

   return ret_val;
}