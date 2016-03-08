/*
*  2. Write a program that prompts the user to enter the day, month, and year. The month
* can be a month number, a month name, or a month abbreviation. The program then
* should return the total number of days in the year up through the given day. (Do take
* leap years into account.)
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MTHS_IN_YEAR 12

typedef struct month{
   char name[10];
   char abrv[3+1];
   int days;
   int mtnum;
} Month;

Month months[MTHS_IN_YEAR] =
   {
     {"january", "jan", 31, 1},
     {"february", "feb", 28, 2},
     {"march", "mar", 31, 3},
     {"april", "apr", 30, 4},
     {"may", "may", 31, 5},
     {"june", "jun", 30, 6},
     {"july", "jul", 31, 7},
     {"august", "aug", 31, 8},
     {"september", "sep", 30, 9},
     {"october", "oct", 31, 10},
     {"november", "nov", 30, 11},
     {"december", "dec", 31, 12}
   };

void eat_line(FILE *stream);
int get_int(const char *prompt_msg, const char *err_msg);
int get_month(const char *prompt_msg, const char *err_msg);
char *s_gets (char *st, int n);

bool leap_year(int year);
int is_month(const char *month);             // returns 0 if month is invalid
                                             // returns month's number if month is valid
bool is_date(int year, int month, int day);
void ToLower(char *str);
int total_days(int year, int month, int day);

int main(void)
{
   int year = 0, month = 0, day = 0;

   while(!feof(stdin)){
      day = get_int("Enter the number of days: ",
                    "Please enter an integer: ");

      month = get_month("Enter the desired month: ",
                        "Please enter the month's name or number: ");

      year = get_int("Enter the year: ",
                     "Please enter an integer: ");

      if(is_date(year, month, day))
         printf("The total number of days in the year %d up\n"
                "through the %d of %s is: %d\n\n",
                year, day, months[month-1].name,
                total_days(year, month, day));
      else
         puts("That's not a valid date. Try again!\n");
   }

   return 0;
}

int get_month(const char *prompt_msg, const char *err_msg)
{
   char buffer[20];
   int mth_num = 0;

   fputs(prompt_msg, stdout);
   while(s_gets(buffer, 20) && buffer[0]){
      if((mth_num = is_month(buffer)))
         break;

      mth_num = strtol(buffer, NULL, 10);
      if(mth_num>0 && mth_num<=12)
         break;

      fputs(err_msg, stdout);
   }

   return mth_num;
}

void eat_line(FILE *stream)
{
   while(getc(stream)!='\n')
      continue;
}

char *s_gets (char *st, int n)
{
   char *ret_val, *find;

   if((ret_val=fgets(st, n, stdin))){
      if((find=strchr(st,'\n')))
         *find = '\0';
      else
         while(getchar()!='\n')
            continue;
   }

   return ret_val;
}

int get_int(const char *prompt_msg, const char *err_msg)
{
   int num;
 
   fputs(prompt_msg, stdout);
   while(!scanf("%d", &num) && !feof(stdin)){
      fputs(err_msg, stdout);
      eat_line(stdin);
   }
   if(!feof(stdin))
      eat_line(stdin);

   return num;
}

int total_days(int year, int month, int day)
{
   #define FEB 2

   int total=0;
   int i;

   (month>months[FEB-1].mtnum && leap_year(year))? (total=1) : (total=0);

   for(i=0; i<months[month-1].mtnum; ++i)
      total += months[i].days;
   total -= months[i-1].days-day;

   return total;      
}

void ToLower(char *str)
{
   while(*str){
      *str = tolower(*str);
      ++str;
   }
}

bool is_date(int year, int month, int day)
{
   #define FEB 2

   if(year>0 && month>0 && day>0)
      if(month<=MTHS_IN_YEAR){
         if(day<=months[month-1].days)
            return true;
         else if(month==FEB && leap_year(year) && day<=months[FEB-1].days+1)
            return true;
      }

   return false;
}

int is_month(const char *month)
{
   if(strlen(month)>=3){
      int i;
      char *pstr = (char*) malloc(strlen(month)+1);
      strcpy(pstr, month);
      ToLower(pstr);

      if(strlen(month)>3){
         for(i=0; i<MTHS_IN_YEAR; ++i)
            if(!strcmp(months[i].name, pstr))
               break;
      }
      else
         for(i=0; i<MTHS_IN_YEAR; ++i)
            if(!strcmp(months[i].abrv, pstr))
               break;  

      free(pstr); 
      if(i!=MTHS_IN_YEAR)
         return months[i].mtnum;         
   }

   return 0;
}

bool leap_year(int year)
{
   if((!(year%4) && year%100) || !(year%400))
      return true;

   return false;
}