#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 41

int main(void)
{
   FILE *fp;
   char words[MAX];

   if(!(fp=fopen("wordy","a+"))){
      fprintf(stderr, "Can't open \"wordy\" file.\n");
      perror("Reason");
      exit(EXIT_FAILURE);
   }
   
   puts("Enter words to add to the file; press the #");
   puts("key at the beginning of a file to terminate.");
    
   while(fscanf(stdin,"%40s", words)==1 && words[0]!='#')
      fprintf(fp, "%s\n", words);
  
   puts("File contents: ");
   rewind(fp);          // Go back to the beginning of file

   while(fscanf(fp,"%s",words)==1)
      puts(words);
   puts("Done!");
   
   if(fclose(fp)){
      fprintf(stderr, "Error closing file.\n");
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   return 0;
}