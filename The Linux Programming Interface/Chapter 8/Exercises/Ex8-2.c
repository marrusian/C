/*
*  8-2. Implement getpwnam() using setpwent(), getpwent(), and endpwent().
*/

#define _XOPEN_SOURCE 600
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

struct passwd *my_getpwnam(const char *name);

struct passwd *my_getpwnam(const char *name)
{
   struct passwd *pwd;

   register int err = errno;      /* Save errno value */
   errno = 0;

   setpwent();       /* Rewind back to the beginning, just in case */
   while((pwd = getpwent()) && strcmp(pwd->pw_name, name))
      continue;

   endpwent();

   if(!pwd){         /* SUSv3-conforming return value */
      if(!errno)     /* If "name" not found, leave errno unchanged */
         errno = err;

      return NULL;
   }
   
   return pwd;
}
