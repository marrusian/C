#define _XOPEN_SOURCE 600
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

uid_t userIdFromName(const char *name);
extern struct passwd *my_getpwnam(const char *name);

int main(int argc, char *argv[])
{
   char *endptr;
   id_t nid;

   if(argc<2)
      usageErr("%s usage: uid/gid/name\n", argv[0]);
 
   for(char **cma = argv+1; *cma; ++cma){
      nid = strtol(*cma, &endptr, 10);

      if(*endptr){
         errno = 0;
         if((nid=userIdFromName(*cma)) == (id_t)-1){
            switch(errno){
               case 0:
               case ENOENT:
               case ESRCH:
               case EBADF:
               case EPERM: printf("Name: %s\t UID: %s\n", *cma, "Not Found");
                           break;
               default: errExit("Line %d: my_getpwnam()", __LINE__);
            }
         }
         else printf("Name: %s\t UID: %ld\n", *cma, (long) nid);
      }
   }

   exit(EXIT_SUCCESS);
}

uid_t userIdFromName(const char *name)
{
   struct passwd *pwd;
   uid_t u;
   char *endptr;

   if(!name || !(*name))
      return -1;

   u = strtol(name, &endptr, 10);
   if(!(*endptr))
      return u;

   if(!(pwd=my_getpwnam(name)))
      return -1;

   return pwd->pw_uid;
}