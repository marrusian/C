#include<stdio.h>
#include<string.h>

#define NLEN 30

struct namect{
   char fname[NLEN];
   char lname[NLEN];
   int letters;
};

struct namect get_info(void);
struct namect make_info(struct namect);
void show_info(struct namect);
char *s_gets(char *st, int n);

int main(void)
{
   struct namect person;

   person = get_info();
   person = make_info(person);
   show_info(person);

   return 0;
}  

struct namect get_info(void)
{
   struct namect temp;

   puts("Please enter your first name.");
   s_gets(temp.fname, NLEN);
   puts("Please enter your last name.");
   s_gets(temp.lname, NLEN);

   return temp;
}

struct namect make_info(struct namect info)
{
   info.letters = strlen(info.fname)+strlen(info.lname);
   
   return info;
}

void show_info(struct namect info)
{
   printf("%s %s, your name contains %d letters.\n",
          info.fname, info.lname, info.letters);
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