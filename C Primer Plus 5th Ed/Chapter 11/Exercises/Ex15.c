/*
*  15. Use the character classification functions to prepare an implementation of atoi(); have
* this version return the value of 0 if the input string is not a pure number.
*/

#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int myatoi(const char *str);

int main(void)
{
   printf("%d\n", myatoi("51"));
   return 0;
}

int myatoi(const char *str)
{
   int val = 0;
   bool sign = false;

   while(isspace(*str))
      ++str;

   switch(*str){
      case '+': ++str;
                break;
      case '-': sign = true;
                ++str;
                break;
      default: break;
   }

   while(isdigit(*str)){
      val = val*10+*str-'0';
      ++str;
   }

   if(*str)
      val = 0;
   else if(sign)
      val *= -1;

   return val;
}