/*
*  16. Write a program that reads input until end-of-file and echoes it to the display. Have the
* program recognize and implement the following command-line arguments:
*    -p Print input as is
*    -u Map input to all uppercase
*    -l Map input to all lowercase
*  Also, if there are no command-line arguments, let the program behave as if the –p
* argument had been used.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

void unique_copy(char *restrict dest, const char *restrict source);
bool check_options(const char *arg);
void ToUpper(char *str);
void ToLower(char *str);
void echo(const char *opt); 

int main(int argc, char *argv[])
{
   char options[10] = {0};
   
   if(argc>1){
      for(int i=1; i<argc; ++i)
         if(argv[i][0]=='-')
            unique_copy(options,argv[i]);
         else{
            printf("echo: Invalid argument -- \"%s\"\n", argv[i]);
            exit(EXIT_FAILURE);
         }

      // Skip the dash, we already checked for it.
      if(!check_options(options+1))
         exit(EXIT_FAILURE);
   }
   
   *options? echo(options+1) : echo("p");

   return 0;
}

void echo(const char *opt)
{
   int ch;
   switch(*opt){
      case 'p': while((ch=getchar())!=EOF)
                   putchar(ch);
                break;
      case 'u': while((ch=getchar())!=EOF)
                   putchar(toupper(ch));
                break;
      case 'l': while((ch=getchar())!=EOF)
                   putchar(tolower(ch));
                break;
   }
}

bool check_options(const char *arg)
{
   if(!*arg){
      puts("echo: Options set is empty.");
      return false;
   }

   int arg_counter = 0;
   while(*arg){
      switch(*arg){
         case 'p':
         case 'u':
         case 'l': break;
         default: printf("echo: Invalid option -- \'%c\'\n", *arg);
                  return false;   
      }
      ++arg_counter;
      ++arg;
   }

   if(arg_counter>1){
      puts("echo: Multiple options are not allowed");
      return false;
   } 

   return true;
}

void unique_copy(char *restrict dest, const char *restrict source)
// Pre-conditions: length(dest)>=length(source)
{
   char *temp = dest;

   while(*source){
      while(*dest && *dest!=*source)
         ++dest;
      if(!*dest)
         *dest=*source;
      dest = temp;
      ++source;         
   }
}