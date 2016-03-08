/*
*  14. Write a power-law program that works on a command-line basis. The first command-line
* argument should be the type double number to be raised to a certain power, and the
* second argument should be the integer power.
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>

double power(double base, int exp);

int main(int argc, char *argv[])
{
   if(argc>2){
      double base;
      int exp;
      char *endptr;

      errno=0;
      base = strtod(argv[1], &endptr);
      if(errno==ERANGE){
         printf("Invalid argument -- \"%s\"\n", argv[1]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }
      else if(*endptr){
         printf("Invalid argument -- \"%s\"\n", argv[1]);
         puts("Reason: No valid conversion could be performed");
         exit(EXIT_FAILURE);
      }

      errno=0;
      exp = (int)strtol(argv[2], &endptr, 10);
      if(errno==ERANGE){
         printf("Invalid argument -- \"%s\"\n", argv[2]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }
      else if(*endptr){
         printf("Invalid argument -- \"%s\"\n", argv[2]);
         puts("Reason: No valid conversion could be performed (integer type required)");
         exit(EXIT_FAILURE);
      }
      
      printf("%g^%d = %g\n", base, exp, power(base,exp));
   }
   else
      puts("Missing command-line arguments!");

   return 0;
}

double power(double base, int exp)
{
   double val = 1.0;

   if(exp){
      int aexp = abs(exp);
      while(aexp--) val*=base;

      if(exp<0) val = 1.0/val; 
   }

   return val;
}