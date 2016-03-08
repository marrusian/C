/*
*   9-3. Implement initgroups() using setgroups() and library functions for retrieving
*  information from the password and group files (Section 8.4). Remember that a
*  process must be privileged in order to be able to call setgroups().
*/

#define _BSD_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_initgroups(const char *user, gid_t group);

int main(int argc, char *argv[])
{
  
   exit(EXIT_SUCCESS);
}

int my_initgroups(const char *user, gid_t group)
{
   struct passwd *pw;
   struct group *grp;
   size_t gidsetsize = 0;
   gid_t grouplist[sysconf(_SC_NGROUPS_MAX)+1];

   if((pw = getpwnam(user))){   /* Original initgroups() behaviour */
      setgrent();
      while((grp = getgrent())){
         for(char **mem = grp->gr_mem; *mem; ++mem)
            if(!strcmp(*mem, user)){
               grouplist[gidsetsize] = grp->gr_gid;
               ++gidsetsize;
               break;
            }
      }
      endgrent();
   }
   
   grouplist[gidsetsize++] = group;
   if(setgroups(gidsetsize, grouplist) == -1)
      return -1;

   return 0;   
}