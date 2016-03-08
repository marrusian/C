/*
*  2. Use nested loops to produce the following pattern:
*   $
*   $$
*   $$$
*   $$$$
*   $$$$$
*/

#include<stdio.h>

int main(void)
{
  const char DOLLAR = '$';
  
  for(size_t i=0; i<5; ++i){
     for(size_t j=0; j<=i; ++j)
        printf("%c", DOLLAR);
     printf("\n");
  }

  return 0;
}