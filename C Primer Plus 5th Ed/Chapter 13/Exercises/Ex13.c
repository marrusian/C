/*
*  13. Do Programming Exercise 12, but use variable-length arrays (VLAs) instead of standard
* arrays.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20
#define COLS 30
#define UPB 10
#define FLNM "pic"
#define IMGNM "img"
#define ERRGEN -1

double uniform_deviate(void);

int generate_file(const char *file_name, int rows, int cols);
char match_level(int darkness_level);

int generate_image(const char *source_file, int rows, int cols, char arr[rows][cols]);
void display_image(int rows, int cols, char arr[rows][cols]);
int store_image(const char *dest_file, int rows, int cols, char arr[rows][cols]);

int main(void)
{
   char picture[ROWS][COLS+1] = {{0}};

   srand((unsigned int) time(0));
   if(generate_file(FLNM, ROWS, COLS)==ERRGEN)
      exit(EXIT_FAILURE);
 
   if(generate_image(FLNM, ROWS, COLS, picture)==ERRGEN)
      exit(EXIT_FAILURE);

   display_image(ROWS, COLS, picture);

   if(store_image(IMGNM, ROWS, COLS, picture)==ERRGEN)
      exit(EXIT_FAILURE);

   return 0;
}

int store_image(const char *dest_file, int rows, int cols, char arr[rows][cols])
{
   FILE *fp;

   if(!(fp=fopen(dest_file,"w"))){
      fprintf(stderr, "Can't open output file \"%s\"\n", dest_file);
      perror("Reason");
      return ERRGEN;
   }

   for(int i=0; i<rows; ++i){
      for(int j=0; j<cols; ++j)
         fprintf(fp, "%c ", arr[i][j]);
      putc('\n', fp);
   }

   if(ferror(fp)){
      fprintf(stderr, "Error in writing to file \"%s\"\n", dest_file);
      perror("Reason");
      return ERRGEN;
   }
   if(fclose(fp)){
      fprintf(stderr, "Can't close output file \"%s\"\n", dest_file);
      perror("Reason");
      return ERRGEN;
   }

   return 0;
}

void display_image(int rows, int cols, char arr[rows][cols])
{
   for(int i=0; i<rows; ++i){
      for(int j=0; j<cols; ++j)
         printf("%c ", arr[i][j]);
      putchar('\n');
   }
}

int generate_image(const char *source_file, int rows, int cols, char arr[rows][cols])
{
   FILE *fp;
   int temp;

   if(!(fp=fopen(source_file,"r"))){
      fprintf(stderr, "Can't open input file \"%s\"\n", source_file);
      perror("Reason");
      return ERRGEN;
   }

   for(int i=0; i<rows; ++i)
      for(int j=0; j<cols; ++j){
         fscanf(fp, "%d", &temp);
         arr[i][j] = match_level(temp);
      }
         
   if(ferror(fp)){
      fprintf(stderr, "Error in reading from file \"%s\"\n", source_file);
      perror("Reason");
      return ERRGEN;
   }
   if(fclose(fp)){
      fprintf(stderr, "Can't close input file \"%s\"\n", source_file);
      perror("Reason");
      return ERRGEN;
   }

   return 0;
}

char match_level(int darkness_level)
{
   char ch;
   switch(darkness_level){
      case 0: ch = ' '; break;
      case 1: ch = '.'; break;
      case 2: ch = '\''; break;
      case 3: ch = ':'; break;
      case 4: ch = '~'; break;
      case 5: ch = '*'; break;
      case 6: ch = '='; break;
      case 7: ch = '@'; break;
      case 8: ch = '%'; break;
      case 9: ch = '#'; break;
   }

   return ch;
}

double uniform_deviate(void){return rand()*(1.0/(RAND_MAX+1.0));}

int generate_file(const char *dest_file, int rows, int cols)
{
   FILE *fp;

   if(!(fp=fopen(dest_file,"w"))){
      fprintf(stderr, "Can't open output file \"%s\"\n", dest_file);
      perror("Reason");
      return ERRGEN;
   }

   for(int i=0; i<rows; ++i){
      for(int j=0; j<cols; ++j)
         fprintf(fp, "%d ", (int)(uniform_deviate()*UPB));
      putc('\n', fp);
   }

   if(ferror(fp)){
      fprintf(stderr, "Error in writing to file \"%s\"\n", dest_file);
      perror("Reason");
      return ERRGEN;
   }
   if(fclose(fp)){
      fprintf(stderr, "Can't close output file \"%s\"\n", dest_file);
      perror("Reason");
      return ERRGEN;
   }

   return 0;
}