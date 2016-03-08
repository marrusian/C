/*
*  2. Write a file-copy program that takes the original filename and the copy file from the
* command line. Use standard I/O and the binary mode, if possible.
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
   FILE *fo, *fc;
   int ch;

   if(argc==3){
      if(!(fo=fopen(argv[1],"rb"))){
         fprintf(stderr, "Can't open file \"%s\"\n", argv[1]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }
      if(!(fc=fopen(argv[2],"wb"))){
         fprintf(stderr, "Can't open file \"%s\"\n", argv[2]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }

       while((ch=getc(fo))!=EOF)
          putc(ch, fc);

       if(ferror(fo)){
          fprintf(stderr, "Error reading from file \"%s\"\n", argv[1]);
          perror("Reason");
          exit(EXIT_FAILURE);
       } 
       if(ferror(fc)){
          fprintf(stderr, "Error writing to file \"%s\"\n", argv[2]);
          perror("Reason");
          exit(EXIT_FAILURE);
       }

       if(fclose(fo)){
          fprintf(stderr, "Can't close file \"%s\"\n", argv[1]);
          perror("Reason");
          exit(EXIT_FAILURE);
       }
       if(fclose(fc)){
          fprintf(stderr, "Can't close file \"%s\"\n", argv[1]);
          perror("Reason");
          exit(EXIT_FAILURE);
       }  
   }
   else{
      fprintf(stderr, "Usage: %s filename.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   return 0;
}