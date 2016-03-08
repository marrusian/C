/*
*  5. Write a program that fits the following recipe:
*
*       a. Externally define a name structure template with two members: a string to hold the
*          first name and a string to hold the second name.
*
*       b. Externally define a student structure template with three members: a name
*          structure, a grade array to hold three floating-point scores, and a variable to hold
*          the average of those three scores.
*
*       c. Have the main() function declare an array of CSIZE (with CSIZE = 4) student
*          structures and initialize the name portions to names of your choice. Use functions
*          to perform the tasks described in parts d., e., f., and g.
*
*       d. Interactively acquire scores for each student by prompting the user with a student
*          name and a request for scores. Place the scores in the grade array portion of the
*          appropriate structure. The required looping can be done in main() or in the
*          function, as you prefer.
*
*       e. Calculate the average score value for each structure and assign it to the proper
*          member.
*
*       f. Print the information in each structure.
*
*       g. Print the class average for each of the numeric structure members.
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include "Ex5.h"

#define DIMENSION_OF(a) (sizeof(a)/sizeof((a)[0]))
#define CSIZE 4

void get_stud_scores(Student sarr[], size_t n);
void calc_stud_avg(Student sarr[], size_t n);
void print_class(Student sarr[const], size_t n);
double calc_class_avg(Student sarr[const], size_t n);

void eat_line(FILE *stream);
float get_float(void);

int main(void)
{
   Student students[CSIZE] =
   {
      {.names = {"Bald", "Dick"}},
      {.names = {"Balooney", "Hork"}},
      {.names = {"Dickinson", "Magena"}},
      {.names = {"Stephen", "Prata"}}
   };

   get_stud_scores(students, CSIZE);
   calc_stud_avg(students, CSIZE);
   print_class(students, CSIZE);

   printf("\nThe class' average score is: %g\n", calc_class_avg(students, CSIZE));
      
   return 0;
}

double calc_class_avg(Student sarr[const], size_t n)
{
   double class_avg = 0.0;
   for(size_t i=0; i<n; ++i)
      class_avg += sarr[i].avg_score;
   
   return class_avg/n;
}

void print_class(Student sarr[], size_t n)
{
   for(size_t i=0; i<n; ++i){
      printf("\nStudent's name: %s %s\n", sarr[i].names.fname,
             sarr[i].names.lname);

      printf("Student's scores: ");
      for(size_t j=0; j<DIMENSION_OF(sarr[i].score); ++j)
         printf("%g ", sarr[i].score[j]);

      printf("\nStudent's average score: %g\n", sarr[i].avg_score);
   }
}

void get_stud_scores(Student sarr[], size_t n)
{
   puts("Enter the scores of the following students:");
   for(size_t i=0; i<n; ++i){
      printf("\n%s %s:\n", sarr[i].names.fname, sarr[i].names.lname);
      for(size_t j=0; j<DIMENSION_OF(sarr[i].score); ++j){
         printf("Score #%zd:\n", j+1);
         sarr[i].score[j] = get_float();
      }
   }
}

void calc_stud_avg(Student sarr[], size_t n)
{
   double average;

   for(size_t i=0; i<n; ++i){
      average = 0.0;
      for(size_t j=0; j<DIMENSION_OF(sarr[i].score); ++j)
         average += sarr[i].score[j];

      sarr[i].avg_score = average/DIMENSION_OF(sarr[i].score);
   }
}

void eat_line(FILE *stream)
{
   while(getc(stream)!='\n')
      continue;
}

float get_float(void)
{
   char *endptr;
   char buffer[20] = {0};
   float val = 0.0f;

   printf("Enter a floating-point value: ");
   do{
      if(buffer[0])
         printf("Please enter a floating-point value: ");

      if(scanf("%20s", buffer)!=EOF)
         eat_line(stdin);

      errno = 0;
      val = strtod(buffer, &endptr);
      if(errno)
         perror("");
   }while(!feof(stdin) && (*endptr || errno));

   return val;
}