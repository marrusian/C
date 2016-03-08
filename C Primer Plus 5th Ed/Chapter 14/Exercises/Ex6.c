/*
*   6. A text file holds information about a softball team. Each line has data arranged as
*  follows:
*
*      4 Jessie Joybat 5 2 1 1
*
*   The first item is the player’s number, conveniently in the range 0–18. The second item
*   is the player’s first name, and the third is the player’s last name. Each name is a single
*   word. The next item is the player’s official times at bat, followed by the number of hits,
*   walks, and runs batted in (RBIs). The file may contain data for more than one game,
*   so the same player may have more than one line of data, and there may be data for
*   other players between those lines. Write a program that stores the data into an array of
*   structures. The structure should have members to represent the first and last names, the
*   at bats, hits, walks, and RBIs (runs batted in), and the batting average (to be calculated
*   later). You can use the player number as an array index. The program should read to end-
*   of-file, and it should keep cumulative totals for each player.
*
*   The world of baseball statistics is an involved one. For example, a walk or reaching base
*   on an error doesn’t count as an at-bat but could possibly produce an RBI. But all this
*   program has to do is read and process the data file, as described next, without worrying
*   about how realistic the data is.
*
*   The simplest way for the program to proceed is to initialize the structure contents to
*   zeros, read the file data into temporary variables, and then add them to the contents of
*   the corresponding structure. After the program has finished reading the file, it should
*   then calculate the batting average for each player and store it in the corresponding
*   structure member. The batting average is calculated by dividing the cumulative number
*   of hits for a player by the cumulative number of at-bats; it should be a floating-point
*   calculation. The program should then display the cumulative data for each player along
*   with a line showing the combined statistics for the entire team.
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define DIMENSION_OF(a) (sizeof(a)/sizeof((a)[0]))

#define TM_SZ 18

typedef struct baseball_player{
   int num;
   struct {char fname[15+1]; char lname[15+1];};
   int at_bat;
   int hits;
   int walks;
   int RBI;
   double bat_avg;
} BSB_Player;

void fetch_data(const char *file_name, BSB_Player plrs[]);
void calc_bat_avg(BSB_Player plrs[], size_t n);
void print_team(BSB_Player plrs[const], size_t n);

int main(void)
{
   BSB_Player players[TM_SZ] = {{0}};

   errno = 0;
   fetch_data("baseball.txt", players);
   if(errno)
      exit(EXIT_FAILURE);

   calc_bat_avg(players, DIMENSION_OF(players));

   print_team(players, DIMENSION_OF(players));

   return 0;
}

void print_team(BSB_Player plrs[const], size_t n)
{
   printf("%-19s %9s %6s %6s %6s %10s\n", "Name", "At Bat", "Hits", "Walks", "RBI", "Bat Avg");
   for(size_t i=0; i<n; ++i){
      if(plrs[i].num)   
         printf("%-8s %-8s %6d %8d %5d %8d %11.4f\n", plrs[i].fname, plrs[i].lname,
                 plrs[i].at_bat, plrs[i].hits, plrs[i].walks, plrs[i].RBI, plrs[i].bat_avg);
   }
}

void calc_bat_avg(BSB_Player plrs[], size_t n)
{
   for(size_t i=0; i<n; ++i)
      if(plrs[i].num)
         plrs[i].bat_avg = (double)plrs[i].hits/plrs[i].at_bat;
}

void fetch_data(const char *file_name, BSB_Player plrs[])
{
   FILE *fp;
   int index;
   int temp;

   if(!(fp=fopen(file_name,"r"))){
      fprintf(stderr, "Can't open input file \"%s\"\n", file_name);
      perror("Reason");
      return;
   }

   while(fscanf(fp, "%d", &index)!=EOF){
      if(!plrs[index-1].num){
         plrs[index-1].num = index;
         fscanf(fp, "%15s %15s", plrs[index-1].fname, plrs[index-1].lname);
      }
      else
         fscanf(fp, "%*s%*s");

      fscanf(fp, "%d", &temp);
      plrs[index-1].at_bat += temp;

      fscanf(fp, "%d", &temp);
      plrs[index-1].hits += temp;

      fscanf(fp, "%d", &temp);
      plrs[index-1].walks += temp;

      fscanf(fp, "%d", &temp);
      plrs[index-1].RBI += temp;     
   }

   if(ferror(fp)){
      fprintf(stderr, "Error in reading file \"%s\"\n", file_name);
      perror("Reason");
   }

   if(fclose(fp)){
      fprintf(stderr, "Error in closing file \"%s\"\n", file_name);
      perror("Reason");
   }
}