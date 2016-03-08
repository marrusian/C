#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10

char *s_gets(char *st, int n);

struct book{
   char title[MAXTITL];
   char author[MAXAUTL];
   float value;
};

int main(void)
{
   struct book library[MAXBKS];

   int count = 0;
   int file_count = 0;
   FILE *pbooks;
   
   if(!(pbooks = fopen("book.dat", "a+b"))){
      fprintf(stderr, "Can't open \"book.dat\" file.\n");
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   rewind(pbooks);
   while(count<MAXBKS && fread(&library[count], sizeof(struct book), 1, pbooks)==1){
      if(!count)
         puts("Current contents of book.dat: ");
      printf("%s by %s: $%.2f\n", library[count].title,
             library[count].author, library[count].value);
      ++count;
   }

   file_count = count;
   if(count==MAXBKS){
      fprintf(stderr, "The \"book.dat\" file is full.");
      exit(EXIT_FAILURE);
   }

   puts("Please add new book titles.");
   puts("Press [enter] at the start of a line to stop.");
   while(count<MAXBKS && s_gets(library[count].title, MAXTITL)
         && library[count].title[0]){
      puts("Now enter the author.");
      s_gets(library[count].author, MAXAUTL);

      puts("Now enter the value.");
      scanf("%f", &library[count++].value);
      while(getchar()!='\n')
         continue;

      if(count<MAXBKS)
         puts("Enter the next title.");   
   }

   if(count>0){
      puts("Here is the list of your books: ");
      for(int i=0; i<count; ++i)
         printf("%s by %s: $%.2f\n", library[i].title,
                library[i].author, library[i].value);

      fwrite(&library[file_count], sizeof(struct book), count-file_count, pbooks);
   }
   else
      puts("No books? Too bad.");

   puts("Bye!"); 
   fclose(pbooks);

   return 0;
}

char *s_gets(char *st, int n)
{
   char *ret_val, *find;

   if((ret_val=fgets(st,n,stdin))){
      if((find=strchr(st,'\n')))
         *find = '\0';
      else
         while(getchar()!='\n')
            continue;
   }

   return ret_val;
}