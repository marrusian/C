#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

#define FALSE 0
#define TRUE  1

static uid_t
userIdFromName(const char *name)
{
   struct passwd *pwd;
   uid_t u;
   char *endptr;

   if(!name || !(*name))
      return -1;

   u = strtol(name, &endptr, 10);
   if(!(*endptr))
      return u;

   return (pwd=getpwnam(name))? pwd->pw_uid : (uid_t)-1;
}

static gid_t
groupIdFromName(const char *name)
{
   struct group *grp;
   gid_t g;
   char *endptr;

   if(!name || !(*name))
      return -1;

   g = strtol(name, &endptr, 10);
   if(!(*endptr))
      return g;

   return (grp=getgrnam(name))? grp->gr_gid : (gid_t)-1;
}

int
main(int argc, char *argv[])
{
   uid_t uid;
   gid_t gid;
   int b_errFnd;

   if(argc<3 || !strcmp(argv[1], "--help"))
      usageErr("%s owner group [file...]\n"
               "      owner or group can be '-', "
               "meaning leave unchanged\n", argv[0]);

   if(!strcmp(argv[1], "-"))
      uid = -1;
   else{
      uid = userIdFromName(argv[1]);
      if(uid == (uid_t)-1)
         fatal("No such user (%s)", argv[1]);
   }

   if(!strcmp(argv[2], "-"))
      gid = -1;
   else{
      gid = groupIdFromName(argv[2]);
      if(gid == (gid_t)-1)
         fatal("No group user (%s)", argv[1]);
   }

   /* Change ownership of all files named in remaining arguments */

   b_errFnd = FALSE;
   for(int j=3; j<argc; ++j){
      if(chown(argv[j], uid, gid) == -1){
         errMsg("chown: %s", argv[j]);
         b_errFnd = TRUE;
      }
   }

   exit(b_errFnd? EXIT_FAILURE : EXIT_SUCCESS);
}