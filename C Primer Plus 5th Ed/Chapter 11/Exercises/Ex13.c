/*
*  13. Write a program that echoes the command-line arguments in reverse word order. That
* is, if the command-line arguments are see you later, the program should print later
* you see.
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
   for(int i=argc-1; i; --i)
      printf("%s ", argv[i]);
   putchar('\n'); 

   return 0;
}