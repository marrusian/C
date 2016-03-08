/*
*  9. Modify the program in Listing 13.3 so that each word is numbered according to the order
* in which it was added to the list, starting with 1. Make sure that, when the program is
* run a second time, new word numbering resumes where the previous numbering left off.
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

#define MAX 40

uint_fast32_t get_index(FILE * restrict stream);

int main(void)
{
   FILE *fp;
   char words[MAX];
   uint_fast32_t index;   

   if(!(fp=fopen("wordy","ab+"))){
      fprintf(stderr, "Can't open \"wordy\" file.\n");
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   index = get_index(fp);

   puts("Enter words to add to the file; press the #");
   puts("key at the beginning of a file to terminate.");
    
   while(fscanf(stdin,"%40s", words)==1 && words[0]!='#')
      fprintf(fp, "%" PRIuFAST32 ". %s\n", ++index, words);
  
   puts("File contents: ");
   rewind(fp);          // Go back to the beginning of file

   while(fgets(words, MAX, fp))
      fputs(words, stdout);
   puts("Done!");
   
   if(fclose(fp)){
      fprintf(stderr, "Error closing file.\n");
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   return 0;
}

uint_fast32_t get_index(FILE * restrict stream)
{
   long count;
   uint_fast32_t ind = 0;
   long beginning = ftell(stream);
   long end;

   fseek(stream, 0L, SEEK_END);
   end = ftell(stream);

   if(end - beginning > 0){
      for(count = 2L; count<=end; ++count){
         fseek(stream, -count, SEEK_END);
         if(getc(stream)=='\n')
            break;
      } 

      fseek(stream, -count+1, SEEK_END);
      if(fscanf(stream, "%" SCNuFAST32, &ind)!=1)
         ind = 0;
   }

   return ind;
}