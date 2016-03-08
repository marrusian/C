#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE * restrict source, FILE * restrict dest);
char *s_gets(char *st, int n);

int main(void)
{
   FILE *fa, *fs;
   int files = 0;
   char file_app[SLEN];
   char file_src[SLEN];
   int ch;

   puts("Enter name of destination file: ");
   s_gets(file_app, SLEN);
   if(!(fa=fopen(file_app,"a+"))){
      fprintf(stderr, "Can't open \"%s\"\n", file_app);
      perror("Reason");
      exit(EXIT_FAILURE);
   }  
   if(setvbuf(fa, NULL, _IOFBF, BUFSIZE)){
      fputs("Can't create output buffer\n", stderr);
      perror("Reason");
      exit(EXIT_FAILURE);
   }
   puts("Enter name of first source file (empty line to quit):");
   while(s_gets(file_src,SLEN) && file_src[0]){
      if(!strcmp(file_src, file_app))
         fputs("Can't append file to itself\n", stderr);
      else if(!(fs=fopen(file_src, "r"))){
         fprintf(stderr, "Can't open \"%s\"\n", file_src);
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
             fprintf(stderr, "Error in reading file \"%s\".\n", file_src);
             perror("Reason");
          }
          if(ferror(fa)){
             fprintf(stderr, "Error in writing file \"%s\".\n", file_app);
             perror("Reason");
          }

          if(fclose(fs)){
             fprintf(stderr, "Can't close \"%s\".\n", file_src);
             perror("Reason");
          }

          ++files;
          printf("File \"%s\" appended.\n", file_src);
          puts("Next file (empty line to quit):"); 
      }
   }
   printf("Done appending. %d files appended.\n", files);

   rewind(fa);
   printf("\"%s\" contents: \n", file_app);
   while((ch=getc(fa)) != EOF)
      putchar(ch);

   puts("Done displaying.");
   
   if(fclose(fa)){
      fprintf(stderr, "Can't close \"%s\".\n", file_app);
      perror("Reason");
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

char *s_gets(char *st, int n)
{
   char *ret_val;
   char *find;

   if((ret_val = fgets(st, n, stdin))){
      find = strchr(st, '\n');
      if(find)
         *find = '\0';
      else
         while(getchar()!='\n')
            continue;
   }

   return ret_val;
}
