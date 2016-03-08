/*
*  Complete the program by providing function definitions for make_array() and show_
* array(). The make_array() function takes two arguments. The first is the number
* of elements of an int array, and the second is a value that is to be assigned to each
* element. The function uses malloc() to create an array of a suitable size, sets each
* element to the indicated value, and returns a pointer to the array. The show_array()
* function displays the contents, eight numbers to a line.
*/

#include<stdio.h>
#include<stdlib.h>

int *make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
   int *pa;
   int size;
   int value;

   printf("Enter the number of elements: ");
   while(scanf("%d",&size) && size>0){
      printf("Enter the initialization value: ");
      scanf("%d", &value);

      pa = make_array(size, value);
      if(pa){
         show_array(pa, size);
         free(pa);
      }

      printf("Enter the number of elements(<1 to quit): ");
   }
   puts("Done!");   

   return 0;
}

void show_array(const int arr[], int n)
{
#define ELEM_PER_LINE 8

   int i=0;
   while(i<n){
      if(!(i%ELEM_PER_LINE)) 
         putchar('\n');
      printf("%d ", arr[i++]);
   }
   if(i)
      putchar('\n');
}

int *make_array(int elem, int val)
{
   int *ptr = (int*) malloc(elem*sizeof(int));

   if(ptr){
      for(int i=0; i<elem; ++i)
         ptr[i] = val;
   }

   return ptr;
}