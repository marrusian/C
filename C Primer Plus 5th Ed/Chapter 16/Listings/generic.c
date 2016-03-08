#include<stdio.h>
#include<math.h>

#define RAD_TO_DEG (180/(4*atanl(1)))

// Generic sqrt function
#define SQRT(x) (_Generic((x), long double: sqrtl,\
float: sqrtf, default: sqrt)(x))

// Generic sine function, angle in degrees
#define SIN(x) (_Generic((x), long double:sinl((x)/RAD_TO_DEG),\
float: sinf((x)/RAD_TO_DEG), default: sin((x)/RAD_TO_DEG)))

int main(void)
{
   float x = 45.0f;
   double xx = 45.0;
   long double xxx = 45.0L;

   long double y = SQRT(x);
   long double yy = SQRT(xx);
   long double yyy = SQRT(xxx);

   printf("%.17Lf\n", y);
   printf("%.17Lf\n", yy);
   printf("%.17LF\n", yyy);

   int i = 45;
   yy = SQRT(i);
   printf("%.17Lf\n", yy);
   yyy = SIN(xxx);
   printf("%.17Lf\n", yyy);

   return 0;
}