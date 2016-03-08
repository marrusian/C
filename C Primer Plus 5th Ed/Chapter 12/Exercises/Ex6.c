/*
*  6. Write a program that generates 1,000 random numbers in the range 1–10. Don’t save or
* print the numbers, but do print how many times each number was produced. Have the
* program do this for 10 different seed values. Do the numbers appear in equal amounts?
* You can use the functions from this chapter or the ANSI C rand() and srand()
* functions, which follow the same format that our functions do. This is one way to
* examine the randomness of a particular random-number generator.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
#define RAND_LIMIT 1000
#define UPB 10          // Upper bound

double uniform_deviate(void){return rand()*(1.0/(RAND_MAX+1.0));}

int main(void)
{
   int arr[SIZE] = {0};

   srand((unsigned int)time(0));
   for(int i=0; i<RAND_LIMIT; ++i)
     ++arr[(int)(uniform_deviate()*UPB)];
   
   for(size_t i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
      printf("%zd was generated %d times.\n", i+1, arr[i]);

   for(size_t i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
      printf("%d/average = %.2f.\n", arr[i], (double)arr[i]/(RAND_LIMIT/SIZE));

   return 0;
}