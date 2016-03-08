/*
*   6-1. Compile the program in Listing 6-1 (mem_segments.c), and list its size using ls –l.
*  Although the program contains an array (mbuf) that is around 10 MB in size, the
*  executable file is much smaller than this. Why is this?
*/

#include <stdio.h>
#include <stdlib.h>

char globBuf[1<<16];
int primes[] = {2, 3, 5, 7};

static int square(int x)
{
   int result;

   result = x*x;
   return result;
}

static void doCalc(int val)
{
   printf("The square of %d ls %d\n", val, square(val));
 
   if(val<1000){
      int t;
  
      t = val*val*val;
      printf("The cube of %d is %d\n", val, t);
   }
}

int main(int argc, char *argv[])
{
   static int key = 9973;
   static char mbuf[10485760];
   char *p;

   p = malloc(1024);
 
   doCalc(key);

   exit(EXIT_SUCCESS);
}