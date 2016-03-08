#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
   int ch;
   FILE *fp;
   unsigned long count = 0;

   if(argc!=2){
      printf("Usage: %s filename\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   if(!(fp=fopen(argv[1],"r"))){
      printf("Can't open \"%s\"\n", argv[1]);
      perror("Reason");
      exit(EXIT_FAILURE);
   }  

   while((ch=getc(fp))!=EOF){
      putc(ch, stdout);
      ++count;
   }

   if(fclose(fp)){
      printf("Error in closing file \"%s\"\n", argv[1]);
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   printf("\nFile \"%s\" has %lu characters.\n", argv[1], count);

   return 0;
}