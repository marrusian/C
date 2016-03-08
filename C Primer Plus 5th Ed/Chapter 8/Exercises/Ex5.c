/*
*  8. Write a program that shows you a menu offering you the choice of addition, subtraction,
* multiplication, or division. After getting your choice, the program asks for two numbers,
* then performs the requested operation. The program should accept only the offered
* menu choices. It should use type float for the numbers and allow the user to try again
* if he or she fails to enter a number. In the case of division, the program should prompt
* the user to enter a new value if 0 is entered as the value for the second number. A typical
* program run should look like this:
*/

#include<stdio.h>
#include<stdlib.h>

void menu(void);
char get_choice(void);
float get_float(void);

int main(void)
{
   int choice = 0;
   float num1 = 0.0f, num2 = 0.0f;

   menu();
   while((choice=get_choice())!='q' && !feof(stdin)){
      printf("Enter first number: ");
      num1=get_float();
      printf("Enter second number: ");
      if(choice=='d')
         while(!(num2=get_float()))
            printf("Can't divide by zero. Try again: ");
      else
         num2=get_float();
      
      switch(choice){
         case 'a': printf("%.1f + %.1f = %.1f\n", num1, num2, num1+num2);
                   break;
         case 's': printf("%.1f - %.1f = %1.f\n", num1, num2, num1-num2);
                   break;
         case 'm': printf("%.1f * %.1f = %1.f\n", num1, num2, num1*num2);
                   break;
         case 'd': printf("%.1f / %.1f = %1.f\n", num1, num2, num1/num2);
                   break;
         default: printf("Program error!\n"); exit(EXIT_FAILURE);
      }
      menu();
   }

   return 0;
}

void menu(void)
{
   printf("\nEnter the operation of your choice:\n");
   printf("a)add          s)subtract\n"
          "m)multiply     d)divide\n"
          "q)quit\n");
}

char get_choice(void)
{
   char ch = '\0';

   while(scanf(" %c",&ch)!=EOF && ch!='a' && ch!='s' && ch!='m' && ch!='d' && ch!='q'){
      printf("Please respond with a, s, m, d or q.\n");
      while((ch=getchar())!='\n')
         continue;
   }

   return (char)ch;
}

float get_float(void)
{
   float number = 0.0f;
   char ch = '\0';

   while(!scanf("%f",&number)){
      while((ch=getchar())!='\n')
         putchar(ch);
      printf(" is not a number.\nPlease enter a number: ");
   }

   return number;
}