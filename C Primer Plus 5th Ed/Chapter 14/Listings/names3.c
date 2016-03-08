#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SLEN 81

struct namect{
   char *fname;
   char *lname;
   int letters;
};

void get_info(struct namect*);
void make_info(struct namect*);
void show_info(const struct namect*);
void clean_up(struct namect *);

char *s_gets(char *st, int n);

int main(void)
{
   struct namect person;

   get_info(&person);
   make_info(&person);
   show_info(&person);
   clean_up(&person);

   return 0;
}

void get_info(struct namect *pst)
{
   char temp[SLEN] = {0};

   puts("Please enter your first name.");
   s_gets(temp, SLEN);
   pst->fname = (char*) malloc(strlen(temp)+1);
   strcpy(pst->fname, temp);
   
   puts("Please enter your last name.");
   s_gets(temp, SLEN);
   pst->lname = (char*) malloc(strlen(temp)+1);
   strcpy(pst->lname, temp);
}

void make_info(struct namect *pst)
{
   pst->letters = strlen(pst->fname)+strlen(pst->lname);
}

void show_info(const struct namect *pst)
{
   printf("%s %s, your name contains %d letters.\n",
          pst->fname, pst->lname, pst->letters);
}

void clean_up(struct namect *pst)
{
   free(pst->fname);
   free(pst->lname);
}

char *s_gets(char *st, int n)
{
   char *ret_val, *find;

   if((ret_val=fgets(st, n, stdin))){
      if((find=strchr(st,'\n')))
         *find = '\0';
      else
         while(getchar()!='\n')
            continue;
   }

   return ret_val;
}