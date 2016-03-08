/*
*  5. Write a function that takes as arguments the name of an array of type int elements, the
* size of an array, and a value representing the number of picks. The function then should
* select the indicated number of items at random from the array and prints them. No
* array element is to be picked more than once. (This simulates picking lottery numbers or
* jury members.) Also, if your implementation has time() (discussed in Chapter 12) or a
* similar function available, use its output with srand() to initialize the rand() random-
* number generator. Write a simple program that tests the function.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZE 10

double uniform_deviate(void){return rand()*(1.0/(RAND_MAX+1.0));}
void pick_random(const int ar[], size_t length, size_t picks);

int main(void)
{
   int array[SIZE] = {6, 23, 1, 49, 21, 55, 3, 35, 41, 16};

   srand((unsigned int)time(0));   
   pick_random(array, SIZE, SIZE);

   return 0;
}

void pick_random(const int ar[], size_t length, size_t picks)
{
   if(picks>length){
      fprintf(stderr, "The number of picks is bigger "
              "than the number of elements.\n");
      return;
   }

   int *varr = (int*) malloc(sizeof(int)*length);
   if(!varr){
      fprintf(stderr, "Couldn't allocate memory on the free store.\n");
      return;
   }

   memcpy(varr, ar, sizeof(int)*length);
   size_t pos;

   while(picks--){
      printf("%d ", varr[pos=(size_t)(uniform_deviate()*length)]);
      memmove(varr+pos,varr+(pos+1), (length-- -(pos+1))*sizeof(int));  
   }
   putchar('\n');

   free(varr);
}