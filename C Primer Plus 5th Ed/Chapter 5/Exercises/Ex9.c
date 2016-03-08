/*
*   9. Write a program that requests the user to enter a Fahrenheit temperature. The program
*  should read the temperature as a type double number and pass it as an argument to
*  a user-supplied function called Temperatures(). This function should calculate the
*  Celsius equivalent and the Kelvin equivalent and display all three temperatures with a
*  precision of two places to the right of the decimal. It should identify each value with the
*  temperature scale it represents. Here is the formula for converting Fahrenheit to Celsius:
*
*        Celsius = 5.0 / 9.0 * (Fahrenheit - 32.0)
*
*    The Kelvin scale, commonly used in science, is a scale in which 0 represents absolute
*  zero, the lower limit to possible temperatures. Here is the formula for converting Celsius
*  to Kelvin:
*
*        Kelvin = Celsius + 273.16
*
*    The Temperatures() function should use const to create symbolic representations of
*  the three constants that appear in the conversions. The main() function should use
*  a loop to allow the user to enter temperatures repeatedly, stopping when a q or other
*  nonnumeric value is entered. Use the fact that scanf() returns the number of items
*  read, so it will return 1 if it reads a number, but it won’t return 1 if the user enters q. The
*  == operator tests for equality, so you can use it to compare the return value of scanf()
*  with 1.
*/

#include<stdio.h>

void Temperatures(double temp);

int main(void)
{
  double temperature = 0.0; // in Fahrenheit

  printf("Enter a temperature in Fahrenheit: ");
  while(scanf("%lf", &temperature)){
    Temperatures(temperature);
    printf("Enter another temperature in Fahrenheit('q' to quit): ");
  }

  return 0;
}

void Temperatures(double temp)
{
  const double SCALE = 5.0/9.0;
  const double ADJUST_FHR = 32.0;
  const double ADJUST_KLV = 273.16;

  double celsius = SCALE*(temp-ADJUST_FHR);
  double kelvin = celsius + ADJUST_KLV;
  
  printf("Fahrenheit: %.2f\n"
         "Celsius: %.2f\n"
         "Kelvin: %.2f\n", temp, celsius, kelvin);         
}