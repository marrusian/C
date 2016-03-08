#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

extern char **environ;

int port_clearenv(void);

int main(int argc, char *argv[])
{
   if(port_clearenv() == -1)
      errExit("port_clearenv()");

   for(char **ep=environ; *ep; ++ep)
      puts(*ep);

   for(int j=1; j<argc; ++j)
      if(putenv(argv[j]))
         errExit("putenv: %s", argv[j]);

   if(setenv("GREET", "Hello world", 0) == -1)
      errExit("setenv()");

   unsetenv("BYE");
   for(char **ep = environ; *ep; ++ep)
      puts(*ep);

   exit(EXIT_SUCCESS);
}

int port_clearenv(void)
{
// SUSv3-conforming function for clearing a process's environment

   char buffer[128];
   char *pos;

   for(char **ep = environ; *ep; ){
      pos = strchr(*ep, '=');

      memcpy(buffer, *ep, (size_t)(pos-*ep));
      buffer[pos-*ep] = '\0';

      if(unsetenv(buffer) == -1)
         return -1;
   }

   return 0;
}
