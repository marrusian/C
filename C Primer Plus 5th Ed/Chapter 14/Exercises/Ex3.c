/*
*  3. Revise the book-listing program in Listing 14.2 so that it prints the book descriptions in
* the order entered, then alphabetized by title, and then in order of increased value.
*/

#include<stdio.h>
#include<string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book{
   char title[MAXTITL];
   char author[MAXAUTL];
   float value;
};

char *s_gets(char *st, int n);
void sort(struct book *list[], size_t list_length, int (*pcomp)(struct book *, struct book *));
int by_title(struct book *a, struct book *b);
int by_value(struct book *a, struct book *b);

int main(void)
{
   struct book library[MAXBKS];
   struct book *ptrbks[MAXBKS];
   int count = 0;

   puts("Please enter the book title.");
   puts("Press [enter] at the start of a line to stop");
   while(count<MAXBKS && s_gets(library[count].title, MAXTITL)
         && library[count].title[0]){

      ptrbks[count] = &library[count];

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
      puts("Here is the list of your books in the entered order:");
      for(int i=0; i<count; ++i)
         printf("%s by %s: $%.2f\n", library[i].title,
                library[i].author, library[i].value);

      sort(ptrbks, count, by_title);
      puts("\nHere is the list of your books alphabetized by title:");
      for(int i=0; i<count; ++i)
         printf("%s by %s: $%.2f\n", ptrbks[i]->title,
                ptrbks[i]->author, ptrbks[i]->value);

      sort(ptrbks, count, by_value);
      puts("\nHere is the list of your books in order of increased value:");
      for(int i=0; i<count; ++i)
         printf("%s by %s: $%.2f\n", ptrbks[i]->title,
                ptrbks[i]->author, ptrbks[i]->value);
   }
   else
      puts("No books? Too bad.");

   return 0;
}

int by_title(struct book *a, struct book *b){return strcmp(a->title,b->title);}

int by_value(struct book *a, struct book *b){return a->value>b->value;}

void sort(struct book *list[], size_t list_length, int (*pcomp)(struct book *, struct book *))
{
   struct book *temp;

   for(size_t i=0; i<list_length; ++i)
      for(size_t j=i+1; j<list_length; ++j)
         if(pcomp(list[i], list[j])>0){
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
         }
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