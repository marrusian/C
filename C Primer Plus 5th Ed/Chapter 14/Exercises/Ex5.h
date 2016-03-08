#ifndef _EX5H
#define _EX5H

typedef struct name{
   char fname[15+1];
   char lname[15+1];
} Name;

typedef struct student{
   struct name names;
   float score[3];
   double avg_score;
} Student;

#endif