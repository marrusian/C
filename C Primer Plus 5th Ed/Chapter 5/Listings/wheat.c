#include<stdio.h>
#define SQUARES 64

int main(void)
{
  const double CROP = 2E16;
  double current, total;
  int count = 0;

  printf("square      grains      total      "
         "fraction of \n");
  printf("            added       grains     "
         "world total\n");

  current = total = 1.0;
  while(++count<SQUARES){
    printf("%4d %13.2e %12.2e %12.2e\n", count, current,
           total, total/CROP);
    current *= 2.0;
    total += current;
  }
  printf("That's all.\n");

  return 0;
}