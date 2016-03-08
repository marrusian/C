/*
*  1. Redo Review Question 5, but make the argument the spelled-out name of the month
* instead of the month number. (Don’t forget about strcmp().) Test the function in a
* simple program.
*/

#include<stdio.h>
#include<string.h>

#define MTHS_IN_YEAR 12

typedef struct month{
   char name[10];
   char abrv[3+1];
   int days;
   int mtnum;
} Month;

Month months[MTHS_IN_YEAR] =
   {
     {"January", "jan", 31, 1},
     {"February", "feb", 28, 2},
     {"March", "mar", 31, 3},
     {"April", "apr", 30, 4},
     {"May", "may", 31, 5},
     {"June", "jun", 30, 6},
     {"July", "jul", 31, 7},
     {"August", "aug", 31, 8},
     {"September", "sep", 30, 9},
     {"October", "oct", 31, 10},
     {"November", "nov", 30, 11},
     {"December", "dec", 31, 12}
   };

char *s_gets(char *st, int n);
int total_days(const char *month_name);

int main(void)
{
   char mth[10];
   int days;

   puts("Enter the name of a month (empty line to quit): ");
   while(s_gets(mth, sizeof(mth)) && mth[0]){ 
      days = 0;
      for(int i=0; i<MTHS_IN_YEAR; ++i)
         if(!strcmp(months[i].name,mth)){
            days = total_days(mth);
            printf("Total number of days including %s is: %d\n",
                   mth, days);
            break;
         }
      if(!days)
         puts("That's not a valid month name. Try again!");
      puts("Enter another month name (empty line to quit): ");
   }
   
   return 0;
}

int total_days(const char *month_name)
{
   int total = 0;
   int i;
   for(i=0; strcmp(months[i].name,month_name) && i<MTHS_IN_YEAR; ++i)
      total += months[i].days;
   total += months[i].days;

   return total;
}

char *s_gets(char *st, int n)
{
   char *ret_val, *find;

   if((ret_val=fgets(st, n, stdin))){
      if((find=strchr(st,'\n')))
         *find='\0';
      else
         while(getchar()!='\n')
            continue;
   }
 
   return ret_val;
}