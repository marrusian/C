/*
*  3. Use nested loops to produce the following pattern:
*   F
*   FE
*   FED
*   FEDC
*   FEDCB
*   FEDCBA
*/

#include<stdio.h>

int main(void)
{
  const size_t LIMIT = 6;

  for(size_t i=0; i<LIMIT; ++i){
     char letter = 'F';

     for(size_t j=0; j<=i; ++j)
        printf("%c", letter--);

     printf("\n");
  }

  return 0;
}