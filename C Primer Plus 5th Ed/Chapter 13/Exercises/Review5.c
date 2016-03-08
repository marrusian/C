/*
*  5. Write a program that takes two command-line arguments. The first is a character, and
* the second is a filename. The program should print only those lines in the file containing
* the given character.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 256

int main(int argc, char *argv[])
{
   int ch;
   FILE *fp;
   char buffer[BUFSIZE];
    
   if(argc!=3){
      if(strlen(argv[1])>1){
         fprintf(stderr, "Invalid sequence -- \"%s\"\n", argv[1]);
         exit(EXIT_FAILURE);
      }
      else ch = argv[1][0];

      if(!(fp=fopen(argv[2],"r"))){
         fprintf(stderr, "Can't open file \"%s\"\n", argv[2]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }

      while(fgets(buffer, BUFSIZE, fp)){
         if(strchr(buffer, ch))
            fputs(buffer, stdout);
      }

      if(ferror(fp)){
         fprintf(stderr, "Error reading from file \"%s\"\n", argv[2]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }

      if(fclose(fp)){
         fprintf(stderr, "Can't close file \"%s\"\n", argv[2]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }
   }
   else
      fprintf(stderr, "Incorrect number of arguments specified.\n");

   return 0;
}