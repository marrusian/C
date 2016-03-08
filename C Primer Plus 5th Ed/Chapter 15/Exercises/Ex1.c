/*
*  1. Write a function that converts a binary string to a numeric value. That is, if you have
*       char * pbin = "01001001";
* you can pass pbin as an argument to the function and have the function return an int
* value of 73.
*/

#include<stdio.h>
#include<limits.h>
#include<ctype.h>

int abtoi(const char *pbin);

int main(void)
{
   char bst[CHAR_BIT*sizeof(int)+1] = {0};

   printf("Enter a binary string: ");
   while(scanf("%s", bst)==1){
      printf("Binary \"%s\" is %d in decimal notation.\n",
              bst, abtoi(bst));
      printf("\nPlease enter another binary string (EOF to quit): ");
   }

   return 0;
}

int abtoi(const char *pbin)
{
   int dec_val = 0;
   
   while(*pbin=='0' || *pbin=='1'){
      dec_val = (dec_val<<1)+(*pbin - '0');
      ++pbin;
   }

   return dec_val;
}

