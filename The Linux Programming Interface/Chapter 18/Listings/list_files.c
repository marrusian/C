#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

void listFiles(const char *dirpath)
{
   DIR *dirp;
   struct dirent *dp;
   int b_isCurrent;    /* True if 'dirpath' is "." */

   b_isCurrent = !strcmp(dirpath, ".");

   if(!(dirp = opendir(dirpath))){
      errMsg("opendir failed on \'%s\'", dirpath);
      return;
   }
  
   errno = 0;
   while((dp = readdir(dirp))){
      if(!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
         continue;      /* Skip "." and ".." */
 
      if(!b_isCurrent)
         printf("%s/", dirpath);
      printf("%s\n", dp->d_name);

      errno = 0;
   } 

   if(errno)
      errExit("readdir()");

   if(closedir(dirp) == -1)
      errMsg("closedir()");
}

int main(int argc, char *argv[])
{
   if(argc>1 && !strcmp(argv[1], "--help"))
      usageErr("%s [dir...]\n", argv[0]);

   if(argc==1)    /* No arguments - use current directory */
      listFiles(".");
   else
      for(char **arg=(argv+1); *arg; ++arg)
         listFiles(*arg);

   exit(EXIT_SUCCESS);
}
