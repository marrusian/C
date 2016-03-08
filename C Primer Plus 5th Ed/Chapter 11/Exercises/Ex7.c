/*
*  7. The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1, truncating
* s2 or padding it with extra null characters as necessary. The target string may not be
* null-terminated if the length of s2 is n or more. The function returns s1. Write your own
* version of this function; call it mystrncpy(). Test the function in a complete program
* that uses a loop to provide input values for feeding to the function.
*/

#include<stdio.h>
#define SIZE1 10
#define SIZE2 30

void mystrncpy(char *restrict dest, const char *restrict source, size_t n);

int main(void)
{
   char str1[SIZE1];
   char str2[SIZE2];

   printf("Enter TWO strings:\n");
   while(fgets(str1, SIZE1, stdin) && fgets(str2, SIZE2, stdin)){
      mystrncpy(str1,str2, sizeof(str1)-1);
      str1[sizeof(str1)-1] = '\0';

      printf("mystrncpy(str1,str2,sizeof(str1)-1) = ");
      puts(str1);
      
      printf("Enter ANOTHER two strings (EOF to quit): ");
   }
   putchar('\n');

   return 0;
}

void mystrncpy(char *restrict dest, const char *restrict source, size_t n)
{
   while(n--)
      if(*source)
         *dest++ = *source++;
      else
         *dest++ = *source;   
}