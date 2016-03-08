/*
*  7. Write a program that opens two files. You can obtain the filenames either by using
* command-line arguments or by soliciting the user to enter them.
*
*    a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the
*    first file, line 2 of the second file, and so on, until the last line of the longer file (in
*    terms of lines) is printed.
*
*    b. Modify the program so that lines with the same line number are printed on the
*    same line.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 256

int main(int argc, char *argv[])
{
   if(argc==3){
      FILE *fp_first, *fp_second;
      char line[BUFSIZE];
      char *find_nl;

      if(!(fp_first=fopen(argv[1],"r"))){
         fprintf(stderr, "Can't open file \"%s\"\n", argv[1]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }
      if(!(fp_second=fopen(argv[2],"r"))){
         fprintf(stderr, "Can't open file \"%s\"\n", argv[2]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }

      while(!feof(fp_first) || !feof(fp_second)){
         if(fgets(line, BUFSIZE, fp_first)){
            if((find_nl=strchr(line, '\n')))
               *find_nl = '\0';
            fputs(line, stdout);
         }

         if(fgets(line, BUFSIZE, fp_second))
            fputs(line, stdout);
      }

      if(ferror(fp_first) || ferror(fp_second)){
         fprintf(stderr, "Error in reading files.\n");
         perror("Reason");
         exit(EXIT_FAILURE);
      }

      if(fclose(fp_first) || fclose(fp_second)){
         fprintf(stderr, "Can't close the files.\n");
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