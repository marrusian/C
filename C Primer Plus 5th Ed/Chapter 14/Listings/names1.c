#include<stdio.h>
#include<string.h>

#define NLEN 30

struct namect{
   char fname[NLEN];
   char lname[NLEN];
   int letters;
};

void get_info(struct namect *);
void make_info(struct namect *);
void show_info(const struct namect *);
char *s_gets(char *st, int n);

int main(void)
{
   struct namect person;

   get_info(&person);
   make_info(&person);
   show_info(&person);

   return 0;
}

void get_info(struct namect *pst)
{
   puts("Please enter your first name:");
   s_gets(pst->fname, NLEN);
   puts("Please enter your last name:");
   s_gets(pst->lname, NLEN);
}

void make_info(struct namect *pst)
{
   pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void show_info(const struct namect *pst)
{
   printf("%s %s, your name contains %d letters.\n",
          pst->fname, pst->lname, pst->letters);
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