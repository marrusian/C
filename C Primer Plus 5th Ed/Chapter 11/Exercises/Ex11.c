/*
*  11. Write a program that reads in up to 10 strings or to EOF, whichever comes first. Have it
* offer the user a menu with five choices: print the original list of strings, print the strings
* in ASCII collating sequence, print the strings in order of increasing length, print the
* strings in order of the length of the first word in the string, and quit. Have the menu
* recycle until the user enters the quit request. The program, of course, should actually
* perform the promised tasks.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50
#define LIM  10
#define QUIT  5

void str_cssrt(char *strings[], size_t list_length);   // Collating Sequence Sort
void str_lsrt(char *strings[], size_t list_length);    // Sort by string length
void str_fwlsrt(char *strings[], size_t list_length);  // Sort by first word's length

char *s_gets(char *buffer, size_t length);
int get_choice(void);
void menu(void);
void print_list(const char *strs[], size_t list_length);

int main(void)
{
   char strings[LIM][SIZE];
   char *ptrs[LIM];
   int choice = 0;
   size_t str_count = 0;

   printf("Please enter up to %d strings (EOF to quit): \n", LIM);
   for(int i=0; i<LIM; ++i){
      printf("%d. ", i+1);
      if(!s_gets(strings[i], sizeof(strings[i])))
         break;
      ptrs[i] = strings[i];
      ++str_count;
   }

   menu();
   while((choice=get_choice())!=QUIT && !feof(stdin)){
      switch(choice){
         case 1: for(size_t i=0; i<str_count; ++i)
                    ptrs[i] = strings[i];
                 break;
         case 2: str_cssrt(ptrs, str_count); break;
         case 3: str_lsrt(ptrs, str_count); break;
         case 4: str_fwlsrt(ptrs, str_count); break;
         default: printf("Program error!\n"); 
                  perror("Reason");
                  exit(EXIT_FAILURE);
      }            
      
      print_list(ptrs, str_count);
      menu();
   }
   putchar('\n');

   return 0;
}

void str_cssrt(char *strings[], size_t list_length)
{
   char *temp;

   for(size_t i=0; i<list_length; ++i)
      for(size_t j=i+1; j<list_length; ++j)
         if(strcmp(strings[i],strings[j])>0){
            temp = strings[i];
            strings[i] = strings[j];
            strings[j] = temp;
         }
}

void str_lsrt(char *strings[], size_t list_length)
{
   char *temp;

   for(size_t i=0; i<list_length; ++i)
      for(size_t j=i+1; j<list_length; ++j)
         if(strlen(strings[i]) > strlen(strings[j])){
            temp = strings[i];
            strings[i] = strings[j];
            strings[j] = temp;
         }
}

void str_fwlsrt(char *strings[], size_t list_length)
{
   char *temp;
   size_t *fwlengths = (size_t*)malloc(list_length*sizeof(size_t));

   for(size_t i=0; i<list_length; ++i)
      if((temp=strchr(strings[i], ' ')))
         fwlengths[i] = temp-strings[i];
      else
         fwlengths[i] = strlen(strings[i]);

   for(size_t i=0; i<list_length; ++i)
      for(size_t j=i+1; j<list_length; ++j)
         if(fwlengths[i] > fwlengths[j]){
            temp = strings[i];
            strings[i] = strings[j];
            strings[j] = temp;
         }

   free(fwlengths);
}

void menu(void)
{
   printf("\nPlease choose one of the following:\n");
   printf("1) Print the original list of strings\n"
          "2) Print the strings in ASCII collating sequence\n"
          "3) Print the strings in order of increasing length\n"
          "4) Print the strings in order of the length of the first word\n"
          "5) Quit\n");
}

void print_list(const char *strs[], size_t list_length)
{
   for(size_t i=0; i<list_length; ++i)
      puts(strs[i]);
}

int get_choice(void)
{
   long choice = 0;
   char buffer[10] = {0};
   char *endptr;

   printf("Enter your choice: ");
   do{
      if(buffer[0])
         printf("Enter an integer from 1 to 5, please: ");
      scanf("%s", buffer);
      choice = strtol(buffer, &endptr, 10); 
   }while(!feof(stdin) && (*endptr || (choice<1 || choice>5)));

   return (int)choice;
}

char *s_gets(char *buffer, size_t length)
{
   char *ret_val;
   if((ret_val=fgets(buffer, length, stdin))){
      while(*buffer!='\n' && *buffer)
         ++buffer;

      if(*buffer=='\n')
         *buffer='\0';
      else
         while(getchar()!='\n')
            continue;
   }

   return ret_val;
}