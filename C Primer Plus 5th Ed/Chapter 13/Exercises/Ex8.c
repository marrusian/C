/*
*  8. Write a program that takes as command-line arguments a character and zero or more
* filenames. If no arguments follow the character, have the program read the standard
* input. Otherwise, have it open each file in turn and report how many times the character
* appears in each file. The filename and the character itself should be reported along with
* the count. Include error-checking to see whether the number of arguments is correct and
* whether the files can be opened. If a file can’t be opened, have the program report that
* fact and go on to the next file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>

uint_fast32_t count_occurences(int ch, FILE * restrict stream);

int main(int argc, char *argv[])
{
   if(argc>1){
      FILE *fp;
      int ch;
     
      if(strlen(argv[1])>1){
         fprintf(stderr, "Invalid sequence -- \"%s\"\n", argv[1]);
         exit(EXIT_FAILURE);
      }
      ch = argv[1][0];

      if(argc==2){
         fp = stdin;        
         fprintf(stdout, "The character \'%c\' appears %" PRIuFAST32 " times\n",
                 ch, count_occurences(ch, fp));
      }
      else{
         for(int i=2; i<argc; ++i){
            if(!(fp=fopen(argv[i],"rb"))){
               fprintf(stderr, "Can't open file \"%s\"\n", argv[i]);
               perror("Reason");
               continue;
            }
            
            fprintf(stdout, "The character \'%c\' appears %" PRIuFAST32 " times in \"%s\" file\n",
                    ch, count_occurences(ch, fp), argv[i]);
            
            if(ferror(fp)){
               fprintf(stderr, "Error in reading from file \"%s\"\n", argv[i]);
               perror("Reason");
            }
            
            fclose(fp);
         } 
      }
   }
   else{
      fprintf(stderr, "Usage: %s filename.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   return 0;
}

uint_fast32_t count_occurences(int ch, FILE * restrict stream)
{
   uint_fast32_t count = 0;
   int_fast32_t temp;

   while((temp=getc(stream))!=EOF)
      if(ch==temp)
         ++count;

   return count;
}