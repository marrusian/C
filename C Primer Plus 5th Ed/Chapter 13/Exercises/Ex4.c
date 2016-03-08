/*
*  4. Write a program that sequentially displays onscreen all the files listed in the command
* line. Use argc to control a loop.
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{  
   FILE *fp;
   int ch;
   
   if(argc>1){
      for(int i=1; i<argc; ++i){
         if(!(fp=fopen(argv[i],"r"))){
            fprintf(stderr, "Can't open file \"%s\"\n", argv[i]);
            perror("Reason");
         }     
         else{
            while((ch=getc(fp))!=EOF)
               putc(ch,stdout);
            putc('\n', stdout);

            if(ferror(fp)){
               fprintf(stderr, "Error reading from file \"%s\"\n", argv[i]);
               perror("Reason");
            }

            fclose(fp);
         }
      }
   }
   else{
      fprintf(stderr, "Usage: %s filename\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   return 0;
}