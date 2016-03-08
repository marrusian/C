#include<stdio.h>
#include<stdlib.h>

#define ROWS 3
#define COLS 4

int sum2d(int rows, int cols, int ar[rows][cols]);

int main(void)
{   
   int junk[ROWS][COLS] =
   {
      {2,4,6,8},
      {3,5,7,9},
      {12,10,8,6}
   };

   int morejunk[ROWS-1][COLS+2] = 
   {
      {20,30,40,50,60,70},
      {5,6,7,8,9,10}
   };

   int rs = 3, cs = 10;
   int varr[rs][cs];  // VLA
   
   for(int i=0; i<rs; ++i)
      for(int j=0; j<cs; ++j)
         varr[i][j]=i*j+j;

   printf("3x5 array\n");
   printf("Sum of all elements = %d\n",
          sum2d(ROWS, COLS, junk));

   printf("2x6 array\n");
   printf("Sum of all elements = %d\n",
          sum2d(ROWS-1,COLS+2, morejunk));

   printf("3x10 VLA\n");
   printf("Sum of all elements = %d\n",
          sum2d(rs, cs, varr));

   return 0;
}

// Function with a VLA parameter
int sum2d(int rows, int cols, int ar[rows][cols])
{
   int total = 0;

   for(int r=0; r<rows; ++r)
      for(int c=0; c<cols; ++c)
         total += ar[r][c];

   return total;
}