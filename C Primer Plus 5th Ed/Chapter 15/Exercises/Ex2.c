/*
*  2. Write a program that reads two binary strings as command-line arguments and prints
* the results of applying the ~ operator to each number and the results of applying the
* &, |, and ^ operators to the pair. Show the results as binary strings. (If you don’t have a
* command-line environment available, have the program read the strings interactively.)
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_SIZE CHAR_BIT*sizeof(long long)
#define OPS 3

bool is_bst(const char *pb);
void str_flip(char *st, const char *str);
void str_and(char *st, const char *str_l, const char *str_r);
void str_or(char *st, const char *str_l, const char *str_r);
void str_xor(char *st, const char *str_l, const char *str_r);

int main(int argc, char *argv[])
{
   if(argc==3){
      for(int i=1; i<argc; ++i)
         if(!is_bst(argv[i]))
            exit(EXIT_FAILURE);

      if(strlen(argv[1])-strlen(argv[2])){
         fprintf(stderr, "Error: The strings have different lengths.\n");
         exit(EXIT_FAILURE);
      }

      char result[MAX_SIZE] = {0};
      char symbols[OPS+1] = "&|^";
      void (*pfun[OPS])(char*, const char*, const char*) =
       {str_and, str_or, str_xor};

      for(int i=1; i<argc; ++i){
         str_flip(result, argv[i]);
         printf("~%s = %s\n", argv[i], result); 
      }

      for(int i=0; i<OPS; ++i){
         pfun[i](result, argv[1], argv[2]);
         printf("\n%s%c\n%s=\n%s\n", argv[1], symbols[i],
                 argv[2], result);
      }
   }
   else{
      fprintf(stderr, "Usage: \"%s\" filename\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   

   return 0;
}

bool is_bst(const char *pb)
{
   const char *temp = pb;
   while(*pb){
      if(*pb!='0' && *pb!='1'){
         fprintf(stderr, "Error: \'%c\' is not a binary digit\n", *pb);
         return false;
      }
      ++pb;
   }

   if((size_t)(pb-temp)>MAX_SIZE){
      fprintf(stderr, "Error: The binary string is longer than %zd bits\n",
              MAX_SIZE);
      return false;
   }

   return true;
}

void str_flip(char *st, const char *str)
{
   while(*str)
      *st++ = ('1'^*str++)+'0';
}

void str_and(char *st, const char *str_l, const char *str_r)
{
   while(*str_l && *str_r)
      *st++ = ( (*str_l++ - '0') & (*str_r++ -'0') ) + '0';
}

void str_or(char *st, const char *str_l, const char *str_r)
{
   while(*str_l && *str_r)
      *st++ = ( (*str_l++ - '0') | (*str_r++ -'0') ) + '0';
}

void str_xor(char *st, const char *str_l, const char *str_r)
{
   while(*str_l && *str_r)
      *st++ = ( (*str_l++ - '0') ^ (*str_r++ -'0') ) + '0';
}