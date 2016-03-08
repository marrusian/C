#include<stdio.h>
#include<inttypes.h>

void to_binary(uint_fast32_t n);
void to_octal(uint_fast32_t n);
void to_hexa(uint_fast32_t n);

int main(void)
{
   uint_fast32_t number = 0;
   
   printf("Enter an integer (q to quit):\n");
   while(scanf("%" PRIuFAST32 "", &number) && !feof(stdin)){
      printf("Binary equivalent: ");
      to_binary(number);
      putchar('\n');
      printf("Octal equivalent: ");
      to_octal(number);
      putchar('\n');
      printf("Hex equivalent: ");
      to_hexa(number);

      printf("\nEnter an integer (q to quit):\n");
   }

   return 0;
}

void to_binary(uint_fast32_t n)
{
   uint_fast32_t r = 0;
    
   if(n>0){
      r = n%2;
      to_binary(n/2);
      putchar(r ? '1' : '0');
   }
}

void to_octal(uint_fast32_t n)
{
#define OCTAL 8
   uint_fast32_t r = 0;

   if(n>0){
      r=n%OCTAL;
      to_octal(n/OCTAL);
      putchar(r+'0');
   }
}

void to_hexa(uint_fast32_t n)
{
#define HEX 16
   uint_fast32_t r = 0;

   if(n>0){
      r=n%HEX;
      to_hexa(n/HEX);
      putchar(r>9? r+'7' : r+'0');
   }
}