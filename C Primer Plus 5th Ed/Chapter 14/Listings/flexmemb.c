#include<stdio.h>
#include<stdlib.h>

struct flex{
   size_t count;
   double average;
   double scores[];   // flexible array member
};

void show_flex(const struct flex *pst);

int main(void)
{
   struct flex *pf1, *pf2;
   int n = 5;
   int total = 0;

   pf1 = (struct flex*) malloc(sizeof(struct flex) + n*sizeof(double));
   pf1->count = n;

   for(int i=0; i<n; ++i){
      pf1->scores[i] = 20.0 - i;
      total += pf1->scores[i];
   }

   pf1->average = total/n;
   show_flex(pf1);

   n = 9;
   total = 0;

   pf2 = (struct flex*) malloc(sizeof(struct flex) + n*sizeof(double));
   pf2->count = n;

   for(int i=0; i<n; ++i){
      pf2->scores[i] = 20.0 - i/2.0;
      total += pf2->scores[i];
   }

   pf2->average = total/n;
   show_flex(pf2);

   free(pf1);
   free(pf2);

   return 0;
}

void show_flex(const struct flex *p)
{
   printf("Scores : ");
   for(size_t i=0; i < p->count; ++i)
      printf("%g ", p->scores[i]);

   printf("\nAverage: %g\n", p->average);
}