/*
*  11. Write a program that takes two command-line arguments. The first is a string; the
* second is the name of a file. The program should then search the file, printing all lines
* containing the string. Because this task is line oriented rather than character oriented,
* use fgets() instead of getc(). Use the standard C library function strstr() (briefly
* described in exercise 7 of Chapter 11) to search each line for the string. Assume no lines
* are longer than 255 characters.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 256

int main(int argc, char *argv[])
{
   if(argc==3){
      FILE *fp;
      char line[BUFSIZE];
 
      if(!(fp=fopen(argv[2],"rb"))){
         fprintf(stderr, "Cannot open input file \"%s\"\n", argv[2]);
         perror("Reason");
         exit(EXIT_FAILURE);
      } 

      while(fgets(line, sizeof(line), fp)){
         if(strstr(line, argv[1]))
            fputs(line, stdout);
      }

      if(ferror(fp)){
         fprintf(stderr, "Error in reading file \"%s\"\n", argv[2]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }

      fclose(fp);      
   }
   else{
      fprintf(stderr, "Invalid number of arguments specified.\n");
      exit(EXIT_FAILURE);
   }

   return 0;
}