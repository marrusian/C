#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "Ex8.h"

/* Utility Functions */
char get_letter(const char *err_msg, bool (*pfrange)(int))
{
   int ch = '\0';

   do{
      if(ch)
         printf("%s", err_msg);
      s_gets((char*)&ch, sizeof(ch));
   }while(!feof(stdin) && pfrange(ch));
   putchar('\n');

   return ch;
}

int get_int(const char *err_msg, bool (*pfrange)(int))
{
   char buffer[20] = {0};
   char *endptr;
   int val;

   do{
      if(buffer[0])
         printf("%s", err_msg);
      s_gets(buffer, sizeof(buffer));
      val = strtol(buffer, &endptr, 10);
   }while(!feof(stdin) && (*endptr || pfrange(val)));
   putchar('\n');

   return val;
}

char *s_gets(char *st, size_t n)
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

double uniform_deviate(void){return rand()*(1.0/(RAND_MAX+1.0));}

/* Load Data */
void fetch_data(Seat seats[], const char *file_name, size_t cap)
{
   FILE *fp;
   size_t index = 0;
   int bool_temp = 0;
   char width_id[5], width_fname[5], width_lname[5];

   if(!(fp=fopen(file_name, "r"))){
      fprintf(stderr, "Cannot open input file \"%s\"\n", file_name);
      perror("Reason");
      return;
   }

   sprintf(width_id, "%%%zds", sizeof(seats[index].id));
   sprintf(width_fname, "%%%zds", sizeof(seats[index].holder.fname));
   sprintf(width_lname, "%%%zds", sizeof(seats[index].holder.lname));

   while(fscanf(fp, width_id, &seats[index].id)!=EOF && index<cap){

      fscanf(fp, "%d", &bool_temp);
      seats[index].assigned = (_Bool)bool_temp;

      fscanf(fp, width_fname, &seats[index].holder.fname);
      fscanf(fp, width_lname, &seats[index].holder.lname);
      ++index;
   }

   if(ferror(fp)){
      fprintf(stderr, "Error in reading file \"%s\"\n", file_name);
      perror("Reason");
   }

   if(fclose(fp)){
      fprintf(stderr, "Cannot close input file \"%s\"\n", file_name);
      perror("Reason");
   }
}

void generate_id(Seat seats[], size_t n)
{
   for(size_t i=0; i<n; ++i)
      if(strlen(seats[i].id)<sizeof(seats[i].id)-1)
         for(size_t j=0; j<sizeof(seats[i].id)-1; ++j)
            seats[i].id[j] = (char)(uniform_deviate()*('9'-'0'+1))+'0';// Generate number in range['0'-'9']
}

/* Save data */
void save_data(Seat seats[], const char *file_name, size_t cap)
{
   FILE *fp;

   if(!(fp=fopen(file_name,"w"))){
      fprintf(stderr, "Cannot open output file \"%s\"\n", file_name);
      perror("Reason");
      return;
   }

   for(size_t i=0; i<cap; ++i)
      fprintf(fp, "%s %d %s %s\n", seats[i].id, seats[i].assigned,
              seats[i].holder.fname, seats[i].holder.lname);
   
   if(ferror(fp)){
      fprintf(stderr, "Error in writing to file \"%s\"\n", file_name);
      perror("Reason");
   }

   if(fclose(fp)){
      fprintf(stderr, "Cannot close output file \"%s\"\n", file_name);
      perror("Reason");
   }   
}

/* Menus */
void show_menu(void)
{
   printf("\nTo choose a function, enter its letter label:\n");
   printf("a) Show number of empty seats\n"
          "b) Show list of empty seats\n"
          "c) Show alphabetical list of seats\n"
          "d) Assign a customer to a seat assignment\n"
          "e) Delete a seat assignment\n"
          "f) Quit\n");
}

void show_del_options(void)
{
   printf("\nTo choose a function, enter its number label:\n");
   printf("1) Delete by ID\n"
          "2) Delete by name\n");
}

bool main_menu_range(int ch){return (ch<'a' || ch >'f');}
bool del_seat_range(int ch) {return (ch<1 || ch>2);}

/* Principal Features */
int ct_empty_seats(const Seat seats[], size_t n)
{
   int count = 0;
   for(size_t i=0; i<n; ++i)
      if(!seats[i].assigned)
         ++count;

   return count;
}

bool empty(const Seat *ps)   {return !ps->assigned;}
bool occupied(const Seat *ps){return ps->assigned;}
void print_byID(const Seat *ps)    {printf("ID: %s\n", ps->id);}
void print_byHolder(const Seat *ps){printf("Name: %s %s\n", ps->holder.fname, ps->holder.lname);} 

void print_seats(const Seat seats[], size_t n, bool (*ptype)(const Seat *ps), void (*pmode)(const Seat*))
{
   for(size_t i=0; i<n; ++i)
      if(ptype(&seats[i]))
         pmode(&seats[i]); 
}

void print_pseats(const Seat *seats[], size_t n, bool (*ptype)(const Seat *ps), void (*pmode)(const Seat*))
{
   for(size_t i=0; i<n; ++i)  
      if(ptype(seats[i]))
         pmode(seats[i]);
}

void assign_seat(Seat seats[], size_t n)
{
   size_t i=0;
   while(i<n && seats[i].assigned)
      ++i;

   if(i==n)
      printf("All seats are occupied at the moment.\n"
             "Please try again later!\n");
   else{
      char *temp_fname = (char*) malloc(sizeof(seats[i].holder.fname));
      char *temp_lname = (char*) malloc(sizeof(seats[i].holder.lname));
     
      printf("Enter your first name (EOF to quit): "); 
      s_gets(temp_fname, sizeof(seats[i].holder.fname));
      printf("Enter your last name (EOF to quit): ");
      s_gets(temp_lname, sizeof(seats[i].holder.lname));

      if(!feof(stdin)){
         seats[i].assigned = true;
         strcpy(seats[i].holder.fname, temp_fname);
         strcpy(seats[i].holder.lname, temp_lname);
         printf("Here is your seat ID: %s\n", seats[i].id);
      }

      free(temp_fname);
      free(temp_lname);
   }
}

size_t is_seatID(Seat seats[], size_t n, const char *id)
{
   for(size_t i=0; i<n; ++i)
      if(!strcmp(seats[i].id, id))
         return i;

   return n;
}

size_t is_seatName(Seat seats[], size_t n, const char *fname, const char *lname)
{
   for(size_t i=0; i<n; ++i)
      if(!strcmp(seats[i].holder.fname, fname) && !strcmp(seats[i].holder.lname, lname))
         return i;

   return n;
}

void delete_seat(Seat seats[], size_t n, int option)
{
   #define ID   1
   #define NAME 2
   
   size_t index=0;

   if(option==ID){
      char *temp_id = (char*) malloc(sizeof(seats[0].id));
      printf("Enter your seat ID: ");
      s_gets(temp_id, sizeof(seats[0].id));

      if(!feof(stdin)){
         if((index=is_seatID(seats, n, temp_id))==n)
            printf("The ID \"%s\" is invalid.\n", temp_id);
         else{
            seats[index].assigned = false;
            seats[index].holder.fname[0] = '\0';
            seats[index].holder.lname[0] = '\0';
         }
      }
      free(temp_id);
   }
   else if(option==NAME){
      char *temp_fname = (char*) malloc(sizeof(seats[0].holder.fname));
      char *temp_lname = (char*) malloc(sizeof(seats[0].holder.lname));

      printf("Enter your first name (EOF to quit): "); 
      s_gets(temp_fname, sizeof(seats[0].holder.fname));
      printf("Enter your last name (EOF to quit): ");
      s_gets(temp_lname, sizeof(seats[0].holder.lname));

      if(!feof(stdin)){
         if((index=is_seatName(seats, n, temp_fname, temp_lname))==n)
            printf("The name \"%s %s\" is invalid.\n",
                   temp_fname, temp_lname);
         else{
            seats[index].assigned = false;
            seats[index].holder.fname[0] = '\0';
            seats[index].holder.lname[0] = '\0';
         }
      }

      free(temp_fname);
      free(temp_lname);
   }   
}

/* Sort Functions */
void sort(const Seat *pseats[], size_t n, int (*pcomp)(const Seat*, const Seat*))
{
   const Seat *temp;

   for(size_t i=0; i<n; ++i)
      for(size_t j=i+1; j<n; ++j)
         if(pcomp(pseats[i], pseats[j])>0){
            temp = pseats[i];
            pseats[i] = pseats[j];
            pseats[j] = temp;
         }
}

int sort_byHolder(const Seat *a, const Seat *b)
{
  int cmp = strcmp(a->holder.fname, b->holder.fname);
  if(!cmp)
     cmp = strcmp(a->holder.lname, b->holder.lname);

  return cmp;
}