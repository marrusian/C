#define _XOPEN_SOURCE 500
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
   struct stat statbuf;
   char buf[PATH_MAX];
   ssize_t numBytes;

   if(argc!=2 || !strcmp(argv[1], "--help"))
      usageErr("%s pathname\n", argv[0]);

   if(lstat(argv[1], &statbuf) == -1)
      errExit("lstat()");

   if(!S_ISLNK(statbuf.st_mode))
      fatal("%s it not a symbolic link", argv[1]);

   numBytes = readlink(argv[1], buf, PATH_MAX-1);
   if(numBytes == -1)
      errExit("readlink()");
   buf[numBytes] = '\0';         /* Add terminating null-byte */
   printf("readlink: %s --> %s\n", argv[1], buf);

   if(!realpath(argv[1], buf))
      errExit("realpath()");
   printf("realpath: %s --> %s\n", argv[1], buf);

   exit(EXIT_SUCCESS);
}

