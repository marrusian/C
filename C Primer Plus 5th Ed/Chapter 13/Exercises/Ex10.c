/*
*  10. Write a program that opens a text file whose name is obtained interactively. Set up a
* loop that asks the user to enter a file position. The program then should print the part of
* the file starting at that position and proceed to the next newline character. Let negative
* or nonnumeric input terminate the user-input loop.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 40

int main(void)
{
   char file_name[MAX];
   FILE *fp;
   long file_pos;
   int ch;

   printf("Enter input file name: ");
   scanf("%40s", file_name);

   if(!(fp=fopen(file_name, "rb"))){
      fprintf(stderr, "Cannot open input file \"%s\"\n", file_name);
      perror("Reason");
      exit(EXIT_FAILURE);
   }   

   printf("Enter a file position: ");
   while(scanf("%ld", &file_pos)==1 && file_pos>=0){
      fseek(fp, file_pos, SEEK_SET);
      
      while((ch=getc(fp))!=EOF && ch!='\n')
         putchar(ch);

      printf("\nEnter another file position (q or <0 to quit): "); 
   }
   putchar('\n');

   fclose(fp);

   return 0;
}