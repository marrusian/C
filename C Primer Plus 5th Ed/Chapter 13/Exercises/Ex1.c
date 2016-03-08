/*
*  1. Modify Listing 13.1 so that it solicits the user to enter the filename and reads the user’s
* response instead of using command-line arguments.
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

#define BUFSIZE 30

int main(void)
{
   int ch;
   FILE *fp;
   uint_fast32_t count = 0;
   char file_in[BUFSIZE];

   printf("Enter input file name: ");
   scanf("%30s", file_in);

   if(!(fp=fopen(file_in,"r"))){
      printf("Can't open \"%s\"\n", file_in);
      perror("Reason");
      exit(EXIT_FAILURE);
   }  

   while((ch=getc(fp))!=EOF){
      putc(ch, stdout);
      ++count;
   }

   if(fclose(fp)){
      printf("Error in closing file \"%s\"\n", file_in);
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   printf("\nFile \"%s\" has %" PRIuFAST32 " characters.\n", file_in, count);

   return 0;
}