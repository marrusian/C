#include <sys/types.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

#define APPEND 0
#define HELP   1

#ifndef BUFSIZE             /* Allow "cc -D" to override definition */
#define BUFSIZE 512+1
#endif

#define STDOUT 1

bool check_options(int argc, const char *argv[], _Bool opts[]);
size_t count_files(const char *argv[]);
int* open_files(const char *argv[], size_t length, _Bool append);
void show_help_menu(void);

int main(int argc, char *argv[])
{
   char buffer[BUFSIZE] = {0};
   size_t fileNum = 0;
   ssize_t numRead = 0;
   _Bool opts[5] = {0};

   if(!check_options(argc, argv, opts))
      exit(EXIT_FAILURE);

   if(opts[HELP]){
      show_help_menu();
      exit(EXIT_SUCCESS);
   }

   fileNum = count_files(argv) + STDOUT;
   int *outputFDs = open_files(argv, fileNum, opts[APPEND]);
   if(!outputFDs)
      exit(EXIT_FAILURE);

   while((numRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0){
      for(size_t i=0; i<fileNum; ++i){
         if(write(outputFDs[i], buffer, numRead) != numRead)
            fatal("Couldn't write whole buffer");
      }
   }
   if(numRead == -1)
      errExit("Read");

   free(outputFDs);

   exit(EXIT_SUCCESS);
}

int* open_files(const char *argv[], size_t length, _Bool append)
{
   int *outputFDs = (int*) malloc(sizeof(int)*length + STDOUT*sizeof(int));

   if(!outputFDs){
      fprintf(stderr, "Cannot allocate memory\n");
      perror("Reason");
      return NULL;
   }

   mode_t filePerm = S_IRUSR | S_IWUSR | S_IRGRP |       
                     S_IWGRP | S_IROTH | S_IWOTH;      /* rw-rw-rw- */

   outputFDs[0] = STDOUT_FILENO;
   for(int i=1, j=1; argv[i]; ++i){
      if(argv[i][0] != '-'){
         switch(append){
            case false: outputFDs[j] = open(argv[i], O_CREAT|O_WRONLY|O_TRUNC, filePerm);
                        break;
            case true:  outputFDs[j] = open(argv[i], O_CREAT|O_WRONLY|O_APPEND, filePerm); 
                        break;
         }

         if(outputFDs[j] == -1){
            fprintf(stderr, "Cannot open output file \"%s\"\n", argv[i]);
            perror("Reason");
            return NULL;
         }

         ++j;
      }
   }
   
   return outputFDs;
}

size_t count_files(const char *argv[])
{
   size_t cnt = 0;

   for(size_t i=1; argv[i]; ++i)
      if(argv[i][0] != '-')
         ++cnt;

   return cnt;      
}

bool check_options(int argc, const char *argv[], _Bool opts[])
{
   for(int i=1; i<argc; ++i){
      if(argv[i][0]=='-'){
         if(!argv[i][1]){
            fprintf(stderr, "Options set is empty.\n");
            return false;
         }

         if(!strcmp(argv[i], "-a") || !strcmp(argv[i], "--append"))
            opts[APPEND] = true;
         else if(!strcmp(argv[i], "--help")){
            opts[HELP] = true;
            break;
         }
         else{
            if(argv[i][1] != '-')
               fprintf(stderr, "Invalid option -- \'%c\'\n", argv[i][1]);
            else
               fprintf(stderr, "Unrecognized option \'%s\'\n", argv[i]);

            return false;
         }         
      }
   }

   return true;
}

void show_help_menu(void)
{
   printf("Usage: tee [OPTION]... [FILE]...\n"
          "Copy standard input to each FILE, and also to standard output\n\n"
          "-a, --append\t\t append to the given FILEs, do not overwrite\n"
          "    --help  \t\t display this help and exit\n");
}