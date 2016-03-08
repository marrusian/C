/*
*   F7. (0.5 puncte) Scrieti un program care converteste un fisier (binar) cu
*  reprezentari interne de intregi intr-un fisier (text) cu reprezentarile
*  lor externe zecimale. Specificatorii fisierelor sunti dati ca argumente
*  in linia de comanda.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define ERROR    0
#define SUCCESS  1
#define BIN_FILE "my_int.bin"

int ibin_to_text(const char *dest_filenm, const char *source_filenm);
char* format_filename(const char *source_filenm);

/* Optional function - use it only if you have no other binary file at hand */
int gen_binfile(const char *file_name);

int main(int argc, char *argv[])
{
   if(argc>1){
      char *dest_name;

      if(!(gen_binfile(BIN_FILE)))
         exit(EXIT_FAILURE);

      for(int i=1; i<argc; ++i){
         dest_name = format_filename(argv[i]);
         if(!(ibin_to_text(dest_name, argv[i]))){
            free(dest_name);  /*  The OS typically reclaims any memory allocated by a process
                               * when it terminates, but let's not bet on that */
            exit(EXIT_FAILURE);
         }
         free(dest_name);
      }
   }
   else{
      fprintf(stderr, "Insufficient arguments specified\n");
      exit(EXIT_FAILURE);
   }

   return 0;
}

int gen_binfile(const char *file_name)
{
   FILE *fpb;
   int ar[] = {1, 5, 9, 12, 15};

   if(!(fpb=fopen(file_name,"wb"))){
      fprintf(stderr, "Cannot open input file \"%s\"\n", file_name);
      perror("Reason");
      return ERROR;      
   }
   
   fwrite(ar, sizeof(int), sizeof(ar)/sizeof(ar[0]), fpb);

   if(ferror(fpb)){
      fprintf(stderr, "Error in writing to file \"%s\"\n", file_name);
      perror("Reason");
      return ERROR;      
   }

   if(fclose(fpb)){
      fprintf(stderr, "Cannot close output file \"%s\"\n", file_name);
      perror("Reason");
      return ERROR;
   }

   return SUCCESS;
}

char* format_filename(const char *source_filenm)
{
   char *dest_filenm = (char*) malloc(sizeof(char)*strlen(source_filenm)+strlen(".txt")+1);
   char *dot_pos;

   strcpy(dest_filenm, source_filenm);
   if((dot_pos=strchr(dest_filenm, '.')))
      strcpy(dot_pos, ".txt");
   else
      strcat(dest_filenm, ".txt");

   return dest_filenm;   
}

int ibin_to_text(const char *dest_filenm, const char *source_filenm)
{
   FILE *fps, *fpd;
   int temp = 0;

   if(!(fps=fopen(source_filenm, "rb"))){
      fprintf(stderr, "Cannot open input file \"%s\"\n", source_filenm);
      perror("Reason");
      return ERROR;
   }
   /* The "x" file mode means "issue an error if the file exists" */
   if(!(fpd=fopen(dest_filenm, "wx"))){ 
      fprintf(stderr, "Cannot open output file \"%s\"\n", dest_filenm);
      perror("Reason");
      return ERROR;
   }

   while(fread(&temp, sizeof(int), 1, fps))
      fprintf(fpd, "%d ", temp);

   if(ferror(fps) || ferror(fpd)){
      fprintf(stderr, "Error in writing/reading to file\n");
      perror("Reason");
      return ERROR;
   }

   if(fclose(fps)){
      fprintf(stderr, "Cannot close input file \"%s\"\n", source_filenm);
       perror("Reason");
       return ERROR;
   }
   if(fclose(fpd)){
      fprintf(stderr, "Cannot close output file \"%s\"\n", dest_filenm);
      perror("Reason");
      return ERROR;
   }

   return SUCCESS;
}