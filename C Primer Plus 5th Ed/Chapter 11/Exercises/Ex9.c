/*
*  9. Write a function that replaces the contents of a string with the string reversed. Test the
* function in a complete program that uses a loop to provide input values for feeding to
* the function.
*/

#include<stdio.h>
#define SIZE 80

void strrev(char *str);

int main(void)
{
   char arr[SIZE];
   
   puts("Enter a string to be reversed: ");
   while(fgets(arr, SIZE, stdin)){
      for(int i=0; arr[i]; ++i)
         if(arr[i]=='\n')
            arr[i]='\0';

      strrev(arr);
      puts(arr);
      
      puts("Enter another string for reversing (EOF to quit): ");
   }

   return 0;
}

void strrev(char *str)
{
   char *it = str;
   char temp;

   while(*it)
      ++it;
   --it;

   while(str<it){
      temp = *str; 
      *str++ = *it;
      *it-- = temp;
   }
}