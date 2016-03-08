#include<stdio.h>
#include<stdlib.h>

#define ARSIZE 1000

int main(void)
{
   double numbers[ARSIZE];
   double value;
   int i;
   const char *file = "numbers.dat";
   FILE *iofile;
   long pos;

   // Create a set of double values
   for(i=0; i<ARSIZE; ++i)
      numbers[i] = 100.0*i+1.0/(i+1);

   if(!(iofile=fopen(file,"wb"))){
      fprintf(stderr, "Could not open \"%s\" for output.\n", file);
      perror("Reason");
      exit(EXIT_FAILURE);
   } 

   fwrite(numbers, sizeof(double), ARSIZE, iofile);

   if(ferror(iofile)){
      fprintf(stderr, "Error writing to \"%s\".\n", file);
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   if(fclose(iofile)){
      fprintf(stderr, "Can't close \"%s\".\n", file);
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   if(!(iofile=fopen(file,"rb"))){
      fprintf(stderr, "Can't open \"%s\" for random access.\n", file);
      perror("Reason");
      exit(EXIT_FAILURE); 
   } 
   
   // Read selected items from file
   printf("Enter an index in the range 0-%d.\n", ARSIZE-1);
   while(scanf("%d", &i)==1 && i>=0 && i<ARSIZE){
      pos = (long) i*sizeof(double); // Calculate offset
      fseek(iofile, pos, SEEK_SET);
      fread(&value, sizeof(double), 1, iofile);
      
      printf("The value there is %f.\n", value);
      printf("Next index (out of range to quit):\n");
   }

   if(fclose(iofile)){
      fprintf(stderr, "Can't close \"%s\".\n", file);
      perror("Reason");
      exit(EXIT_FAILURE);
   }

   puts("Bye!");  

   return 0;
}