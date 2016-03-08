#ifndef _EX8H
#define _EX8H

/* Structures */
typedef struct person{
   char fname[15+1];
   char lname[15+1];
} Person;

typedef struct seat{
   char id[9+1];
   _Bool assigned;
   Person holder;
} Seat;

/* Utility Functions */
char get_letter(const char *err_msg, _Bool (*pfrange)(int));
int get_int(const char *err_msg, _Bool (*pfrange)(int));
char *s_gets(char *st, size_t n);
double uniform_deviate(void);   // For rand();

/* Load data */
void fetch_data(Seat seats[], const char *file_name, size_t cap);
void generate_id(Seat seats[], size_t n);

/* Save data */
void save_data(Seat seats[], const char *file_name, size_t cap);

/* Menus */
void show_menu(void);
void show_del_options(void);
_Bool main_menu_range(int ch);
_Bool del_seat_range(int ch);

/* Principal Features */
int ct_empty_seats(const Seat seats[], size_t n);
void print_seats(const Seat seats[], size_t n, _Bool (*ptype)(const Seat *ps), 
                 void (*pmode)(const Seat*));
void print_pseats(const Seat *seats[], size_t n, _Bool (*ptype)(const Seat *ps), 
                 void (*pmode)(const Seat*));
void assign_seat(Seat seats[], size_t n);
void delete_seat(Seat seats[], size_t n, int option);

_Bool empty(const Seat *ps);
_Bool occupied(const Seat *ps);
void print_byID(const Seat *ps);
void print_byHolder(const Seat *ps);

size_t is_seatID(Seat seats[], size_t n, const char *id);    // returns seat's index number
size_t is_seatName(Seat seats[], size_t n, const char *fname,
                   const char *lname);                       // returns seat's index number

/* Sort Functions */
void sort(const Seat *pseats[], size_t n, int (*pcomp)(const Seat*, const Seat*));
int sort_byHolder(const Seat *a, const Seat *b);

#endif