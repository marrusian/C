#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

static void sysconfPrint(const char *msg, int name)  /* Print 'msg' plus sysconf() value for 'name' */
{
   long lim;

   errno = 0;
   if((lim = sysconf(name)) == -1){
      if(errno)
         errExit("sysconf %s", msg);

      printf("%s (indetermindate)\n", msg);      
   }
   else
      printf("%s %ld\n", msg, lim);
}

int main(int argc, char *argv[])
{
   sysconfPrint("_SC_ARG_MAX:        ", _SC_ARG_MAX);
   sysconfPrint("_SC_LOGIN_NAME_MAX: ", _SC_LOGIN_NAME_MAX);
   sysconfPrint("_SC_OPEN_MAX:       ", _SC_OPEN_MAX);
   sysconfPrint("_SC_NGROUPS_MAX:    ", _SC_NGROUPS_MAX);
   sysconfPrint("_SC_PAGESIZE:       ", _SC_PAGESIZE);
   sysconfPrint("_SC_RTSIG_MAX:      ", _SC_RTSIG_MAX);

   exit(EXIT_SUCCESS);
}