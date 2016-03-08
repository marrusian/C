#include<stdio.h>

long fact(int n);
long rfact(int n);

int main(void)
{
   int num = 0;
   
   printf("This program calculates factorials.\n");

   printf("Enter a value in the range [0,12] (q to quit):\n");
   while(scanf("%d", &num) && !feof(stdin)){
      if(num<0)
         printf("No negative numbers, please.\n");
      else if(num>12)
         printf("Keep input under 13.\n");
      else{
         printf("loop: %d! = %ld\n", num, fact(num));
         printf("recursion: %d! = %ld\n", num, rfact(num));
      }

      printf("\nEnter a value in the range [0,12] (q to quit):\n");
   } 

   return 0;
}

long fact(int n)
{
   long ans;
   
   for(ans = 1; n>1; --n)
      ans*=n;

   return ans;
}

long rfact(int n)
{
   if(n>0)
      return n *= rfact(n-1);
   else
      return 1;
}