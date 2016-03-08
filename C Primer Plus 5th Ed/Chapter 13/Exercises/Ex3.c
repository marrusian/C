/*
*  3. Write a file copy program that prompts the user to enter the name of a text file to act as
* the source file and the name of an output file. The program should use the toupper()
* function from ctype.h to convert all text to uppercase as it’s written to the output file.
* Use standard I/O and the text mode.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
   FILE *fs, *fd;
   int ch;

   if(argc==3){
      if(!(fs=fopen(argv[1],"r"))){
         fprintf(stderr, "Can't open file \"%s\"\n", argv[1]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }
      if(!(fd=fopen(argv[2],"w"))){
         fprintf(stderr, "Can't open file \"%s\"\n", argv[2]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }

       while((ch=getc(fs))!=EOF)
          putc(toupper(ch), fd);

       if(ferror(fs)){
          fprintf(stderr, "Error reading from file \"%s\"\n", argv[1]);
          perror("Reason");
          exit(EXIT_FAILURE);
       } 
       if(ferror(fd)){
          fprintf(stderr, "Error writing to file \"%s\"\n", argv[2]);
          perror("Reason");
          exit(EXIT_FAILURE);
       }

       if(fclose(fs)){
          fprintf(stderr, "Can't close file \"%s\"\n", argv[1]);
          perror("Reason");
          exit(EXIT_FAILURE);
       }
       if(fclose(fd)){
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