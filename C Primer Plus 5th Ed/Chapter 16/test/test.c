#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "generic.h"

#define SIZE 20

void fill_array(unsigned short ar[], size_t length)
{
   for(size_t i=0; i<length; ++i)
      ar[i] = rand();
}

int main(void)
{
   srand((unsigned int)time(0));
   unsigned short ar[SIZE];
  
   fill_array(ar, SIZE);
   PRINT(ar, sizeof(ar)/sizeof(ar[0]), stdout);

   return 0;
}