#include<stdio.h>
#include<stdlib.h>

#define QUIT 4

void menu(void);
int get_choice(void);

int main(void)
{
   int choice = 0;

   menu();
   while((choice=get_choice())!=QUIT && !feof(stdin)){
      switch(choice){
         case 1: break;  // dummy case
         case 2: break;  // dummy case
         case 3: break;  // dummy case
         default: printf("Error!\n"); exit(EXIT_FAILURE);
      }
      menu();
   }

   return 0;
}

void menu(void)
{
   printf("\nPlease choose one of the following:\n");
   printf("1) copy files            2) move files\n"
          "3) remove files          4) quit\n"); 
}

int get_choice(void)
{
   long choice = 0L;
   char *end = NULL;
   char str[40] = {'\0'};

   printf("Enter the number of your choice:\n");
   do{
      if(str[0])
         printf("Enter an integer from 1 to 4, please:\n");
      scanf("%s",str);
      choice=strtol(str,&end,10);
      if(*end){
         choice=QUIT;
         break;
      } 
   }while(!feof(stdin) && (choice<1 || choice>4));

   return (int)choice;
}