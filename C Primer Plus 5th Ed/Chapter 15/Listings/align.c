#include<stdio.h>

int main(void)
{
   double dx, dz;
   char ca, cx, cb;
   char _Alignas(double) cz;

   printf("char alignement:  %zd\n", _Alignof(char));
   printf("double alignment: %zd\n", _Alignof(double));
   printf("&dx: %p\n", (void*)&dx);
   printf("&ca: %p\n", (void*)&ca);
   printf("&cx: %p\n", (void*)&cx);
   printf("&dz: %p\n", (void*)&dz);
   printf("&cb: %p\n", (void*)&cb);
   printf("&cz: %p\n", (void*)&cz);

   return 0;
}