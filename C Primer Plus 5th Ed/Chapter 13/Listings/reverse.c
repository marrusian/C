#include<stdio.h>
#include<stdlib.h>

#define CTRL_Z '\32'   /* EOF marker in DOS text files */
#define SLEN 81

int main(void)
{
   char file[SLEN];
   char ch;
   FILE *fp;
   long last;

   puts("Enter the name of the file to be processed:");
   scanf("%80s", file);
   if(!(fp=fopen(file,"rb"))){
      fprintf(stderr, "Reverse can't open \"%s\"\n", file);
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   fseek(fp, 0L, SEEK_END);
   last = ftell(fp);

   for(long count = 1L; count<=last; ++count){
      fseek(fp, -count, SEEK_END);
      ch = getc(fp);
      if(ch != CTRL_Z && ch != '\r')
         putchar(ch);
   }

   putchar('\n');
   if(fclose(fp)){
      fprintf(stderr, "Error closing file\n");
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   return 0;
}