#define _BSD_SOURCE
#define _XOPEN_SOURCE 600
#include <unistd.h>
#include <pwd.h>
#include <shadow.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

char *fget_s(char *buffer, size_t len);

int main(int argc, char *argv[])
{
   char *username, *password, *encrypted;
   struct passwd *pwd;
   struct spwd *spwd;
   long lnmax;

   lnmax = sysconf(_SC_LOGIN_NAME_MAX);
   if(lnmax == -1)
      lnmax = 256;

   username = (char*) malloc(lnmax);
   if(!username)
      errExit("malloc()");

   printf("Username: ");
   fflush(stdout);
   if(!(fget_s(username, lnmax)))
      exit(EXIT_FAILURE);

   if(!(pwd = getpwnam(username)))
      fatal("Couldn't get password record");
 
   if(!(spwd = getspnam(username)) && errno == EACCES)
      fatal("No permission to read shadow password file");

   if(spwd)
      pwd->pw_passwd = spwd->sp_pwdp;

   password = getpass("Password: ");

   encrypted = crypt(password, pwd->pw_passwd);
   for(char *p = password; *p; ++p)
      *p = '\0';
   
   if(!encrypted)
      errExit("crypt()");

   if(strcmp(encrypted, pwd->pw_passwd)){
      fprintf(stderr, "Incorrect password\n");
      exit(EXIT_FAILURE);
   }

   printf("Successfully authenticated: UID=%ld\n", (long) pwd->pw_uid);

   exit(EXIT_SUCCESS);
}

char *fget_s(char *buffer, size_t len)
{
   char *ret_val, *found;

   if((ret_val = fgets(buffer, len, stdin))){
      if((found=strchr(buffer, '\n')))
         *found = '\0';
      else
         while(getchar() != '\n')
            continue;
   }

   return ret_val;
}