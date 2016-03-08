/*
*  10. Generalize the to_binary() function of Listing 9.8 to a to_base_n() function that
* takes a second argument in the range 2–10. It then should print the number that is its
* first argument to the number base given by the second argument. For example, to_
* base_n(129,8) would display 201, the base-8 equivalent of 129. Test the function in a
* complete program.
*/

#include<stdio.h>
#define BINARY 2
#define DECIMAL 10

void to_base_n(int num, int base);

int main(void)
{
   int number = 0, base = 0;

   while(!feof(stdin)){
      printf("\nEnter the number: ");
      scanf("%d", &number);
      printf("Enter the base to convert to: ");
      scanf("%d", &base);

      if(base<BINARY || base>DECIMAL){
         printf("The base has to be in the [2,10] range. Try again!\n");
         continue;
      }
      else
         printf("%d in base %d is: ", number, base);
         to_base_n(number,base);
         putchar('\n');
   }

   return 0;
}

void to_base_n(int num, int base)
{
   int r;
   if(num>0){
      r=num%base;
      to_base_n(num/base, base);
      printf("%d", r);
   }
}