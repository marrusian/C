#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
   double sum = 0.0;
   int count = 0;
   double val = 0.0;

   if(argc>1){
      FILE* fp;

      if(!(fp = fopen(argv[1],"r"))){
         fprintf(stderr, "Can't open file \"%s\"\n", argv[1]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }

      while(fscanf(fp, "%lf", &val)==1){
         sum += val;
         ++count;
      }
      
      if(ferror(fp)){
         fprintf(stderr, "Error reading from \"%s\"\n", argv[1]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }

      if(fclose(fp)){
         fprintf(stderr, "Can't close file \"%s\"\n", argv[1]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }
   }
   else{
      printf("Enter a floating-point value: ");
      while(scanf("%lf", &val)==1){
         sum+=val;
         ++count;
         printf("Enter another FP value (EOF to quit): ");  
      }  
   }
 
   printf("\nThe arithmetic mean of the input numbers is: %g\n", sum/count);   
   
   return 0;
}