/*
*  6. Write a program that requests the user’s first name and then the user’s last name. Have
*  it print the entered names on one line and the number of letters in each name on the
*  following line. Align each letter count with the end of the corresponding name, as in the
*  following:
*
*      Melissa Honeybee
*            7        8
*
*   Next, have it print the same information, but with the counts aligned with the beginning
*  of each name.
*
*      Melissa Honeybee
*      7       8
*/

#include<stdio.h>
#include<string.h>

int main(void)
{
  char fname[15] = {}, lname[15] = {};
  int fname_length = 0, lname_length = 0;

  printf("Enter your first name: ");
  scanf("%s",fname);
  fname_length = strlen(fname);

  printf("Enter your last name: ");
  scanf("%s",lname);
  lname_length = strlen(lname);

  printf("%s %s\n", fname, lname);
  printf("%*d %*d\n", fname_length, fname_length,
         lname_length, lname_length); 

  printf("%s %s\n", fname, lname);
  printf("%-*d %-*d\n", fname_length, fname_length,
         lname_length, lname_length); 
  
  return 0;
}