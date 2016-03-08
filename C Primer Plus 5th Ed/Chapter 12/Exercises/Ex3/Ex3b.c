/*
*  3. Redesign the program described in Programming Exercise 2 so that it uses only automatic
* variables. Have the program offer the same user interface—that is, it should prompt the
* user to enter a mode, and so on. You’ll have to come up with a different set of function
* calls, however.
*/

// Ex3b.c compile with Ex3a.c

#include<stdio.h>
#include"Ex3h.h"

int main(void)
{
   int mode;
   int prev_mode = 0;
   float distance;
   float fuel_consumed;

   printf("Enter 0 for metric mode, 1 for US mode: ");
   scanf("%d", &mode);
   while(mode>=0){
      mode = set_mode(prev_mode, mode);

      distance = get_distance(mode);
      fuel_consumed = get_fuel(mode);

      show_consumption(distance, fuel_consumed, mode);

      printf("Enter 0 for metric mode, 1 for US mode "
             "(-1 to quit): ");
      prev_mode = mode;
      scanf("%d", &mode);
   }
   puts("Done!");

   return 0;
}