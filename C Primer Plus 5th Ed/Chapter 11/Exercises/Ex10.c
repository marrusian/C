/*
*  10. Write a function that takes a string as an argument and removes the spaces from the
* string. Test it in a program that uses a loop to read lines until you enter an empty line.
* The program should apply the function to each input string and display the result.
*/

#include<stdio.h>
#define SIZE 80

void remove_blanks(char *str);

int main(void)
{
   char arr[SIZE];
   
   puts("Enter a string: ");
   while(fgets(arr, SIZE, stdin)){
      for(int i=0; arr[i]; ++i)
         if(arr[i]=='\n')
            arr[i]='\0';

      remove_blanks(arr);
      puts(arr);
      
      puts("Enter another string (EOF to quit): ");
   }

   return 0;
}

void remove_blanks(char *str)
{
   while(*str){
      if(*str==' ')
         for(char *it=str; *it; ++it)
            *it=*(it+1);
      ++str;
   }
}