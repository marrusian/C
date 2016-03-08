#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define LEN 81

char *s_gets(char *st, int n);

void show_menu(void);
void eat_line(void);    // read through EOL
char get_choice(void);

void show(void (*)(char *), char *str);

void ToUpper(char *);
void ToLower(char *);
void Transpose(char *); // transpose character cases
void Dummy(char *);

int main(void)
{
   char line[LEN], copy[LEN];
   char choice;
   void (*pfun)(char *);

   puts("Enter a string (empty line to quit):");
   while(s_gets(line, LEN) && line[0]){
      show_menu();
      while((choice=get_choice())!='n'){
         switch(choice){
            case 'u': pfun = ToUpper;   break;
            case 'l': pfun = ToLower;   break;
            case 't': pfun = Transpose; break;
            case 'o': pfun = Dummy;     break;
         }

         strcpy(copy, line);
         show(pfun, copy);
         show_menu();
      }
      puts("Enter a string (empty line to quit):");
   }
   puts("Bye!");

   return 0;
}

void show_menu(void)
{
   printf("\nEnter menu choice:\n"
          "u) uppercase        l) lowercase\n"
          "t) transposed case  o) original case\n"
          "n) next string\n");  
}

char get_choice(void)
{
   char ans;

   ans = tolower(getchar());
   eat_line();
   while(!strchr("ulton", ans)){
      puts("Please enter a, u, l, t, o, or n:");
      ans = tolower(getchar());
      eat_line();
   }

   return ans;
}

void eat_line(void)
{
   while(getchar()!='\n')
      continue;
}

void ToUpper(char *str)
{
   while(*str){
      *str = toupper(*str);
      ++str;
   }
}

void ToLower(char *str)
{
   while(*str){
      *str = tolower(*str);
      ++str;
   }
}

void Transpose(char *str)
{
   while(*str){
      if(islower(*str))
         *str = toupper(*str);
      else
         *str = tolower(*str);
      ++str;
   }
}

void Dummy(char *str){}

void show(void (*fp)(char *), char *str)
{
   fp(str);
   puts(str);
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