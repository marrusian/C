#include<stdio.h>
#include<string.h>

#define SIZE 81
#define LIM  20

void stsrt(char *strings[], int num);
char *s_gets(char *st, int n);

int main(void)
{
   char input[LIM][SIZE] = {{'\0'}};
   char *ptstr[LIM] = {0};

   printf("Input up to %d lines, and I will sort them.\n", LIM);
   printf("To stop, press the Enter key at a line's start.\n");

   int ct = 0;
   while(ct<LIM && s_gets(input[ct], SIZE) && input[ct][0]){
      ptstr[ct] = input[ct];
      ++ct;
   }

   stsrt(ptstr, ct);
   puts("\nHere's the sorted list:\n");
   for (int k=0; k<ct; ++k)
      puts(ptstr[k]);

   return 0;
}

void stsrt(char *strings[], int num)
{
   char *temp;
   
   for(int i=0; i<num-1; ++i)
      for(int j=i+1; j<num; ++j)
         if(strcmp(strings[i],strings[j])>0){
            temp = strings[i];
            strings[i] = strings[j];
            strings[j] = temp;
         }
}

char *s_gets(char *st, int n)
{
   char *ret_val;
   int i = 0;

   if(ret_val = fgets(st, n, stdin)){
      while(st[i]!='\n' && st[i])
         ++i;
      if(st[i]=='\n')
         st[i]='\0';
      else
         while(getchar()!='\n')
            continue;
   }

   return ret_val;
}