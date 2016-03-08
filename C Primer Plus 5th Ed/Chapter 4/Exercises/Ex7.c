/*
*  7. Write a program that sets a type double variable to 1.0/3.0 and a type float variable
*  to 1.0/3.0. Display each result three times—once showing four digits to the right of the
*  decimal, once showing 12 digits to the right of the decimal, and once showing 16 digits
*  to the right of the decimal. Also have the program include float.h and display the
*  values of FLT_DIG and DBL_DIG. Are the displayed values of 1.0/3.0 consistent with these
*  values?
*/

#include<stdio.h>
#include<float.h>

int main(void)
{
  double v1 = 1.0/3.0;
  float v2 = 1.0f/3.0f;
  int width = sizeof("Precision")-1;

  printf("%s %20s %20s\n", "Precision", "Double", "Float");
  printf("%5d %*s %20.4f %20.4f\n", 4, width-6, v1, v2);
  printf("%5d %*s %20.12f %20.12f\n", 12, width-6, v1, v2);
  printf("%5d %*s %20.16f %20.16f\n", 16, width-6, v1, v2);

  printf("The number of significant digits for type "
         "float is: %d\n", FLT_DIG);
  printf("The number of significant digits for type "
         "double is: %d\n", DBL_DIG);

  return 0;
}