#define _GNU_SOURCE
#define _BSD_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include <sys/fsuid.h>
#include <grp.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../tlpi-dist/lib/ugid_functions.h"
#include "../../tlpi-dist/lib/tlpi_hdr.h"

#define SG_SIZE (NGROUPS_MAX+1)

int main(int argc, char *argv[])
{
   uid_t ruid, euid, suid, fsuid;
   gid_t rgid, egid, sgid, fsgid;
   gid_t suppGroups[SG_SIZE];
   int numGroups;
   char *p;

   if(getresuid(&ruid, &euid, &suid) == -1)
      errExit("getresuid()");
   if(getresgid(&rgid, &egid, &sgid) == -1)
      errExit("getresgid()");

   /*
    * Attempts to change the FSIDs are always ignored
    * for unprivileged processes, but even so, the
    * following calls return the current FSIDs
   */

   fsuid = setfsuid(0);
   fsgid = setfsgid(0);

   printf("UID: ");
   p = userNameFromId(ruid);
   printf("real=%s (%ld); ", !p? "???" : p, (long) ruid);
   p = userNameFromId(euid);
   printf("eff=%s (%ld); ", !p? "???" : p, (long) euid);
   p = userNameFromId(suid);
   printf("saved=%s (%ld); ", !p? "???" : p, (long) suid);
   p = userNameFromId(fsuid);
   printf("fs=%s (%ld); ", !p? "???" : p, (long) fsuid);
   printf("\n");

   printf("GID: ");
   p = groupNameFromId(rgid);
   printf("real=%s (%ld); ", !p? "???" : p, (long) rgid);
   p = groupNameFromId(egid);
   printf("eff=%s (%ld); ", !p? "???" : p, (long) egid);
   p = groupNameFromId(sgid);
   printf("saved=%s (%ld); ", !p? "???" : p, (long) sgid);
   p = groupNameFromId(fsgid);
   printf("fs=%s (%ld); ", !p? "???" : p, (long) fsgid);
   printf("\n\n");

   numGroups = getgroups(SG_SIZE, suppGroups);
   if(numGroups == -1)
      errExit("getgroups");

   printf("Supplementary groups (%d): \n", numGroups);
   for(int j=0; j<numGroups; ++j){
      p = groupNameFromId(suppGroups[j]);
      printf("%s (%ld) ", !p? "???" : p, (long) suppGroups[j]);
   }
   printf("\n\n");

   exit(EXIT_SUCCESS);
}
