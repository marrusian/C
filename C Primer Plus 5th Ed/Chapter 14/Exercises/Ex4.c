/*
*  4. Write a program that creates a structure template with two members according to the
* following criteria:
*
*    a. The first member is a social security number. The second member is a structure
*       with three members. Its first member contains a first name, its second member
*       contains a middle name, and its final member contains a last name. Create and
*       initialize an array of five such structures. Have the program print the data in this
*       format:
*
*         Dribble, Flossie M. –– 302039823
*
*  Only the initial letter of the middle name is printed, and a period is added. Neither the
*  initial (of course) nor the period should be printed if the middle name member is empty.
*  Write a function to do the printing; pass the structure array to the function.
*
*    b. Modify part a. by passing the structure value instead of the address.
*/

#include<stdio.h>

typedef struct person{
   char socsecurity[15+1];
   struct {char fname[15+1]; char mname[15+1]; char lname[15+1];};
} Person;

void print_prsarr(Person *start, Person *end);

int main(void)
{
   Person parr[5] =
   {
      {"302039823", {"Flossie", "Mell", "Dribble"}},
      {"391845321", {"Fitzgerald", "Mac", "Walter"}},
      {"421394853", {"Mickey", "Donald", "Mouse"}},
      {"401938411", {"Stephen", "Buvan", "Prata"}},
      {"352134569", {"Howard", "Kruth", "Dickson"}}
   };

   print_prsarr(parr, parr+sizeof(parr)/sizeof(parr[0]));

   return 0;
}

void print_prsarr(Person *start, Person *end)
{
   while(start<end){
      printf("%10s, %12s %c%c –– %9s\n", start->lname, start->fname,
             start->mname[0], start->mname[0]? '.' : '\0',
             start->socsecurity);
      ++start;
   }
}