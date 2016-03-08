#include<stdio.h>
#include<stdlib.h>

int main(void)
{
   double *ptd;
   int max = 0;
   int number;
   int i=0;

   puts("What is the maximum number of type double entries?");
   if(!scanf("%d",&max)){
      puts("Number not correctly entered -- bye.");
      exit(EXIT_FAILURE);
   }
   ptd = (double*) malloc(max*sizeof(double));
   if(!ptd){
      puts("Memory allocation failed. Goodbye.");
      exit(EXIT_FAILURE);
   }

   puts("Enter the values (q to quit): ");
   while(i<max && scanf("%lf", &ptd[i]))
      ++i;
   printf("Here are your %d entries:\n", number = i);
   for(int i=0; i <number; ++i){
      printf("%g ", ptd[i]);
      if(i%7==6)
         putchar('\n');
   }
   if(i%7)
      putchar('\n');
   puts("Done.");
   free(ptd);

   return 0;
}