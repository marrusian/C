#include<stdio.h>
#define PI 3.14159

int main(void)
{
  float area=0, circum=0, radius=0;

  printf("What is the radius of your pizza?\n");
  scanf("%f",&radius);

  area = PI*radius*radius;
  circum = 2.0f*PI*radius;

  printf("Your basic pizza parameters are as follows:\n");
  printf("circumference = %.2f, area = %.2f\n", circum, area);

  return 0;
}