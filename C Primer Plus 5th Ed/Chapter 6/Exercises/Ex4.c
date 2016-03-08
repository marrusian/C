/*
*  4. Use nested loops to produce the following pattern:
*   A
*   BC
*   DEF
*   GHIJ
*   KLMNO
*   PQRSTU
*/

#include<stdio.h>

int main(void)
{
  char letter = 'A';

  for(size_t i=0; i<6; ++i){
     for(size_t j=0; j<=i; ++j)
        printf("%c", letter++);
     printf("\n");
  }

  return 0;
}