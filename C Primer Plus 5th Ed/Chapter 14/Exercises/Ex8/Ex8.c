/*
*   8. The Colossus Airlines fleet consists of one plane with a seating capacity of 12. It makes
* one flight daily. Write a seating reservation program with the following features:
*
*   a. The program uses an array of 12 structures. Each structure should hold a seat
*      identification number, a marker that indicates whether the seat is assigned, the last
*      name of the seat holder, and the first name of the seat holder.
*
*   b. The program displays the following menu:
*
*      To choose a function, enter its letter label:
*      a) Show number of empty seats
*      b) Show list of empty seats
*      c) Show alphabetical list of seats
*      d) Assign a customer to a seat assignment
*      e) Delete a seat assignment
*      f) Quit
*
*   c. The program successfully executes the promises of its menu. Choices d) and e)
*      require additional input, and each should enable the user to abort an entry.
*
*   d. After executing a particular function, the program shows the menu again, except
*      for choice f).
*
*   e. Data is saved in a file between runs. When the program is restarted, it first loads in
*      the data, if any, from the file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<time.h>
#include "Ex8.h"

#define CAPACITY 12
#define FILE_NAME "colair.txt"

int main(void)
{
   #define ERR_MSG_MAIN "Please enter the letters a, b, c, d, e or f: "
   #define ERR_MSG_DELSEAT "Please enter 1 or 2: "
   #define QUIT 'f'

   int choice;
   Seat seats[CAPACITY] = {[1]={.id={0}}};    
   const Seat *pseats[CAPACITY];
   for(int i=0; i<CAPACITY; ++i)
      pseats[i] = &seats[i];

   errno = 0;
   fetch_data(seats, FILE_NAME, CAPACITY);
   if(errno)
      exit(EXIT_FAILURE);

   srand((unsigned int)time(0));
   generate_id(seats, CAPACITY);

   show_menu();
   while((choice=get_letter(ERR_MSG_MAIN, main_menu_range))!=QUIT && !feof(stdin)){
      switch(choice){
         case 'a': printf("Total number of empty seats: %d\n",
                          ct_empty_seats(seats, CAPACITY));
                   break;
         case 'b': print_seats(seats, CAPACITY, empty, print_byID);
                   break;
         case 'c': sort(pseats, CAPACITY, sort_byHolder);
                   print_pseats(pseats, CAPACITY, occupied, print_byHolder);
                   break;
         case 'd': assign_seat(seats, CAPACITY);
                   break;
         case 'e': show_del_options();
                   choice = get_int(ERR_MSG_DELSEAT, del_seat_range);
                   delete_seat(seats, CAPACITY, choice);
                   break;
      }
      show_menu();
      clearerr(stdin);
   }

   errno = 0;
   save_data(seats, FILE_NAME, CAPACITY);
   if(errno)
      exit(EXIT_FAILURE);

   return 0;
}