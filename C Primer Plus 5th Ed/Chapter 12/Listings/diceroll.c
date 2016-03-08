#include<stdio.h>
#include<stdlib.h>
#include "diceroll.h"

int roll_count = 0;

static double uniform_deviate(int seed)
{
   return seed*(1.0/(RAND_MAX+1.0));
}

static int rollem(int sides)
{
   ++roll_count;
   return uniform_deviate(rand())*sides+1;
}

int roll_n_dice(int dice, int sides)
{
   int total=0;

   if(sides<2){
      printf("Need at least 2 sides.\n");
      return -2;
   }
   if(dice<1){
      printf("Need at least 1 die.\n");
      return -1;
   }

   for(int d=0; d<dice; ++d)
      total+=rollem(sides);

   return total;
}