#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 20

int main(int argc, char *argv[])
{
   FILE *in, *out;
   int ch;
   char name[LEN];
   int count = 0;

   if(argc<2){
      fprintf(stderr, "Usage: \"%s\" filename\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   if(!(in=fopen(argv[1],"r"))){
      fprintf(stderr, "Can't open \"%s\"\n", argv[1]);
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   strncpy(name, argv[1], LEN-5);
   name[LEN-5] = '\0';
   strcat(name, ".red");

   if(!(out=fopen(name,"w"))){
      fprintf(stderr, "Cant create output file.\n");
      perror("Reason");
      exit(3);
   }

   while((ch=getc(in))!=EOF)
      if(!(count++%3))
         putc(ch, out);     // print every 3rd char
    
   if(fclose(in) || fclose(out)){
      fprintf(stderr, "Error in closing files\n");
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   return 0;
}