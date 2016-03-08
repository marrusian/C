#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 40

void fill_array(double ar[], int n);
void show_array(const double ar[], int n);
int my_comp(const void *p1, const void *p2);

int main(void)
{
   double vals[NUM];

   srand((unsigned int)time(0));
   fill_array(vals, NUM);
   puts("Random list: ");
   show_array(vals, NUM);
   qsort(vals, NUM, sizeof(double), my_comp);
   puts("\nSorted list: ");
   show_array(vals, NUM); 

   return 0;
}

void fill_array(double ar[], int n)
{
   for(int i=0; i<n; ++i)
      ar[i] = (double)rand()/((double)rand()+0.1);
}

void show_array(const double ar[], int n)
{
   int i;
   for(i=0; i<n; ++i){
      printf("%9.4f ", ar[i]);
      if(i%6 == 5)
         putchar('\n');
   }
   if(i%6)
      putchar('\n');
}

int my_comp(const void *p1, const void *p2)
{
   const double *a1 = (const double*) p1;
   const double *a2 = (const double*) p2;

   if(*a1<*a2)
      return -1;
   else if (*a1==*a2)
      return 0;
   else
      return 1;
}