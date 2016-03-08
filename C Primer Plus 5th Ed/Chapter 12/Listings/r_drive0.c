#include<stdio.h>

extern void srand1(unsigned int);
extern int rand0(void);

int main(void)
{
   unsigned int seed;
   puts("Please enter your choice for seed.");
   while(scanf("%u", &seed)){
      srand1(seed);
      for(int count=0; count<5; ++count)
         printf("%d\n", rand0());
      puts("Please enter next seed (q to quit):");
   }
   puts("Done!");

   return 0;
}