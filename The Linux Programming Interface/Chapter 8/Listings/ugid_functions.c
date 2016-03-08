#define _XOPEN_SOURCE 600
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

char *userNameFromID(uid_t uid);
uid_t userIdFromName(const char *name);
char *groupNameFromId(gid_t gid);
gid_t groupIdFromName(const char *name);

void UG_Scan(const char *msg, const char *exit_msg);

char *userNameFromId(uid_t uid)
{
   struct passwd *pwd;

   return !(pwd=getpwuid(uid))? NULL : pwd->pw_name;
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

   if(!(pwd=getpwnam(name)))
      return -1;

   return pwd->pw_uid;
}

char *groupNameFromId(gid_t gid)
{
   struct group *grp;

   return !(grp=getgrgid(gid))? NULL : grp->gr_name;
}

gid_t groupIdFromName(const char *name)
{
   struct group *grp;
   gid_t g;
   char *endptr;

   if(!name || !(*name))
      return -1;

   g = strtol(name, &endptr, 10);
   if(!(*endptr))
      return g;

   if(!(grp=getgrnam(name)))
      return -1;

   return grp->gr_gid;
}

int main(int argc, char *argv[])
{
   char *endptr;
   char *name;
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
               default: errExit("Line %d: getpwnam()", __LINE__);
            }
         }
         else printf("Name: %s\t UID: %ld\n", *cma, (long) nid);

         errno = 0;
         if((nid=groupIdFromName(*cma)) == (id_t)-1){
            switch(errno){
               case 0:
               case ENOENT:
               case ESRCH:
               case EBADF:
               case EPERM: printf("Name: %s\t GID: %s\n", *cma, "Not Found");
                           break;
               default: errExit("Line %d: getgrnam()", __LINE__);
            }
         }
         else printf("Name: %s\t GID: %ld\n", *cma, (long) nid);
      }
      else{
         errno = 0;
         if(!(name=userNameFromId(nid))){
            switch(errno){
               case 0:
               case ENOENT:
               case ESRCH:
               case EBADF:
               case EPERM: printf("UID: %ld\t Name: %s\n", (long) nid, "Not Found");
                           break;
               default: errExit("Line %d: getpwuid()", __LINE__);
            }
         }
         else printf("UID: %ld\t Name: %s\n", (long) nid, name);

         errno = 0;
         if(!(name=groupNameFromId(nid))){
            switch(errno){
               case 0:
               case ENOENT:
               case ESRCH:
               case EBADF:
               case EPERM: printf("GID: %ld\t Name: %s\n", (long) nid, "Not Found");
                           break;
               default: errExit("Line %d: getgruid()", __LINE__);
            }
         }
         else printf("GID: %ld\t Name: %s\n", (long) nid, name);
      }
     
      printf("\n");
   }

   exit(EXIT_SUCCESS);
}