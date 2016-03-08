/*
*  8. Write a function called string_in() that takes two string pointers as arguments. If
* the second string is contained in the first string, have the function return the address
* at which the contained string begins. For instance, string_in("hats", "at") would
* return the address of the a in hats. Otherwise, have the function return the null pointer.
* Test the function in a complete program that uses a loop to provide input values for
* feeding to the function.
*/

#include<stdio.h>
#include<string.h>
#define SIZE 30

char *find_str(const char *restrict str1, const char *restrict str2);

int main(void)
{
   char arr[SIZE];
   char subarr[SIZE];
   char *position;

   printf("Enter TWO strings: "); 
   while(fgets(arr, SIZE, stdin) && fgets(subarr, SIZE, stdin)){

      for(int i=0; subarr[i]; ++i)
         if(subarr[i]=='\n')
            subarr[i]='\0';   

      if((position = find_str(arr, subarr))){
         printf("The string was found at position %td\n", position-arr);
      }
      else
         puts("String not found!");

      printf("Enter ANOTHER two strings (EOF to quit): ");
   }
   putchar('\n');

   return 0;
}

char *find_str(const char *restrict str1, const char *restrict str2)
{
   const char *ret_val;
   for(const char *str2_copy = str2; *str1; ++str1){
      ret_val = str1;

      while(*str1==*str2 && *str2){
         ++str2;
         ++str1;
      }

      if(str1!=ret_val){
         if(*str2){
            str2=str2_copy;
            str1=ret_val;
         }
         else
            return ret_val;
      }
    }

   return NULL;
}