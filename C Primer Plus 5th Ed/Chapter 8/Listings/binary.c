#include<stdio.h>
#define SIZE 5

int main(void)
{
   double a[SIZE] = {1., 2., 3., 4., 5.};
   FILE *fp = fopen("test.bin", "wb");
   fwrite(a, sizeof(a)/sizeof(a[1]), SIZE, fp);
   fclose(fp);

   return 0;
}