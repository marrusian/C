/*
*  5. Modify the program in Listing 13.5 so that it uses a command-line interface instead of an
* interactive interface.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE * restrict source, FILE * restrict dest);

int main(int argc, char *argv[])
{
   FILE *fa, *fs;
   int files = 0;
   int ch;

   if(argc>3){
      if(!(fa=fopen(argv[1],"a+"))){
         fprintf(stderr, "Can't open \"%s\"\n", argv[1]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }  
      if(setvbuf(fa, NULL, _IOFBF, BUFSIZE)){
         fputs("Can't create output buffer\n", stderr);
         perror("Reason");
         exit(EXIT_FAILURE);
      }

      for(int i=2; i<argc; ++i){
         if(!strcmp(argv[1], argv[i]))
            fputs("Can't append file to itself\n", stderr);
         else if(!(fs=fopen(argv[i], "r"))){
            fprintf(stderr, "Can't open \"%s\"\n", argv[i]);
            perror("Reason");
         }
         else{
            if(setvbuf(fs, NULL, _IOFBF, BUFSIZE)){
               fputs("Can't create input buffer\n", stderr);
               perror("Reason");
               continue;
            } 
      
             append(fs, fa);

             if(ferror(fs)){
                fprintf(stderr, "Error in reading file \"%s\".\n", argv[i]);
                perror("Reason");
             }
             if(ferror(fa)){
                fprintf(stderr, "Error in writing file \"%s\".\n", argv[1]);
                perror("Reason");
             }

             if(fclose(fs)){
                fprintf(stderr, "Can't close \"%s\".\n", argv[i]);
                perror("Reason");
             }

             ++files;
             printf("File \"%s\" appended.\n", argv[i]);
         }
      }

      printf("Done appending. %d files appended.\n", files);

      rewind(fa);
      printf("\"%s\" contents: \n", argv[1]);
      while((ch=getc(fa)) != EOF)
         putchar(ch);

      puts("Done displaying.");
   
      if(fclose(fa)){
         fprintf(stderr, "Can't close \"%s\".\n", argv[1]);
         perror("Reason");
      }
   }
   else{
      fprintf(stderr, "Usage: %s filename.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   return 0;
}

void append(FILE * restrict source, FILE * restrict dest)
{
   size_t bytes;
   static char temp[BUFSIZE];

   while((bytes = fread(temp, sizeof(char), BUFSIZE, source)))
      fwrite(temp, sizeof(char), bytes, dest);
}
