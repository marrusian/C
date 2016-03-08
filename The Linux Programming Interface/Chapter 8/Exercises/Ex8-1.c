/*
*   8-1. When we execute the following code, which attempts to display the usernames
*  for two different user IDs, we find that it displays the same username twice.
*  Why is this 
*
*       printf("%s %s\n", getpwuid(uid1)->pw_name,
*                         getpwuid(uid2)->pw_name);
*/

#define _XOPEN_SOURCE 600
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
   if(argc!=3 || !strcmp(argv[1], "--help")){
      fprintf(stderr, "Usage: %s uid1 uid2\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   uid_t ud1, ud2;
   char *endptr;

   ud1 = strtol(argv[1], &endptr, 10);
   if(*endptr){
      fprintf(stderr, "\"%s\" is not a valid UID\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   ud2 = strtol(argv[2], &endptr, 10);
   if(*endptr){
      fprintf(stderr, "\"%s\" is not a valid UID\n", argv[2]);
      exit(EXIT_FAILURE)
   }
   printf("%s %s\n", getpwuid(ud1)->pw_name,
                     getpwuid(ud2)->pw_name);

   exit(EXIT_SUCCESS);
}
