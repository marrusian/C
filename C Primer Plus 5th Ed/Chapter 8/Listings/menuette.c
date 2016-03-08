#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

void menu(void);
char get_choice(void);
int get_int(void);
void count(void);

int main(void)
{
   int choice = 0;

   menu();
   while((choice=get_choice())!='q' && !feof(stdin)){
      switch(choice){
         case 'a': printf("Buy low, sell high.\n"); break;
         case 'b': putchar('\a'); break;
         case 'c': count(); break;
         default: printf("Program error!"); exit(EXIT_FAILURE);
      }
      menu();
   }

   return 0;
}

void menu(void)
{
   printf("\nEnter the letter of your choice:\n");
   printf("a) advice        b) bell\n"
          "c) count         q) quit\n");
}

char get_choice(void)
{
   char ch = '\0';
   
   while(scanf(" %c", &ch) != EOF && ch!='a' && ch!='b' && ch!='c' && ch!='q'){
      printf("Please respond with a, b, c, or q.\n");
      while((ch=getchar())!='\n'){
         continue;
      }
   }

   return ch;
}

int get_int(void)
{
   double input = 0.0;
   char ch = '\0';

   while(!scanf("%lf",&input) || (int)input!=input){
      if((ch=getchar())=='\n')
         printf("%.2f",input);
      else
         do{
            putchar(ch);
         }while((ch=getchar())!='\n');

      input = 0.0;
      printf(" is not an integer.\n Please enter an integer value: "); 
   }
  
   return (int)input;
}

void count(void)
{
   int n = 0;
   
   printf("Count how far? Enter an integer:\n");
   n = get_int();
   for(int i=1; i<=n; ++i)
      printf("%d\n", i);
}