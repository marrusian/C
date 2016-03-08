/*
*  6-3. Implement setenv() and unsetenv() using getenv(), putenv(), and, where necessary,
* code that directly modifies environ. Your version of unsetenv() should check to see
* whether there are multiple definitions of an environment variable, and remove
* them all (which is what the glibc version of unsetenv() does).
*/

#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

extern char **environ;

int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);

int main(int argc, char *argv[])
{
   for(char **ep = environ; *ep; ++ep)
      puts(*ep);
   puts("");
   if(putenv("HOME=/usr/home")){
      perror("putenv()"); exit(EXIT_FAILURE);}
   if(my_setenv("HOME", "cacat", 1) == -1)
      {perror("my_setenv()"); exit(EXIT_FAILURE);}

   my_unsetenv("HOME");
   my_unsetenv("PATH");
   for(char **ep = environ; *ep; ++ep)
      puts(*ep);

   exit(EXIT_SUCCESS);
}

int my_setenv(const char *name, const char *value, int overwrite)
{
   if(!name || !(*name) || strchr(name, '=')){
      errno = EINVAL;
      return -1;
   }

   if(getenv(name) && !overwrite)
      return 0;

   char *buffer = (char*) malloc(strlen(name)+strlen(value)+2);

   if(!buffer)
      return -1;

   strcpy(buffer, name);
   strcat(buffer, "=");
   strcat(buffer, value);

   if(putenv(buffer))
      return -1;

   return 0;
}

int my_unsetenv(const char *name)
{
   if(!name || !(*name) || strchr(name, '=')){
      errno = EINVAL;
      return -1;
   }

   size_t len = strlen(name);

   for(char **ep = environ, **temp; *ep; )
      if(!strncmp(*ep, name, len) && (*ep)[len] == '='){
         temp = ep;
         while(*temp){
           *temp = *(temp+1);
           ++temp;
         }
      }
      else
         ++ep;

   return 0;
}
