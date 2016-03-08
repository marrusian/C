/*
*  4. The ANSI library features a clock() function with this description:
*      #include <time.h>
*      clock_t clock (void);
*  Here, clock_t is a type defined in time.h. The function returns the processor time,
* which is given in some implementation-dependent units. (If the processor time is
* unavailable or cannot be represented, the function returns a value of -1.) However,
* CLOCKS_PER_SEC, also defined in time.h, is the number of processor time units per
* second. Therefore, dividing the difference between two return values of clock() by
* CLOCKS_PER_SEC gives you the number of seconds elapsed between the two calls.
* Typecasting the values to double before division enables you to get fractions of a second.
* Write a function that takes a double argument representing a desired time delay and
* then runs a loop until that amount of time has passed. Write a simple program that tests
* the function.
*/

#include<stdio.h>
#include<time.h>

void wait(double seconds);

int main(void)
{
   double sec = 0.0;

   printf("Enter the number of seconds to wait: ");
   while(scanf("%lf", &sec)==1){
      printf("This program will wait %g seconds\n", sec);
      wait(sec);
      printf("%g seconds just passed\n", sec);

      printf("Enter another number of seconds to wait ('q' to quit): ");
   }

   return 0;
}

void wait(double seconds)
{
   clock_t call_time = clock();

   while((clock()-call_time)/(double)CLOCKS_PER_SEC < seconds)
      continue;
}  