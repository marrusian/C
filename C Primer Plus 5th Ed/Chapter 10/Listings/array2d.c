#include<stdio.h>

#define STACKS 2
#define ROWS 3
#define COLS 4

void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int);
int sum2d(int (*ar)[COLS], int rows);

int main(void)
{
   int junk[ROWS][COLS] = 
   {
      {2,4,6,8},
      {3,5,7,9}, 
      {12,10,8,6}
   };

   sum_rows(junk, ROWS);
   sum_cols(junk, ROWS);
   printf("Sum of all elements = %d\n", sum2d(junk,ROWS));

   return 0;
}

void sum_rows(int ar[][COLS], int rows)
{
   for(int r=0, total; r<rows; ++r){
      total = 0;
      for(int col=0; col<COLS; ++col)
         total += ar[r][col];
      printf("row %d: sum = %d\n", r, total);
   }
}

void sum_cols(int ar[][COLS], int rows)
{
   for(int col=0, total; col<COLS; ++col){
      total=0;
      for(int r=0; r<rows; ++r)
         total += ar[r][col];
      printf("col %d: sum = %d\n", col, total);
   }
}

int sum2d(int ar[][COLS], int rows)
{
   int total=0;

   for(int r=0; r<rows; ++r) 
      for(int col=0; col<COLS; ++col)
         total += ar[r][col];

   return total; 
}