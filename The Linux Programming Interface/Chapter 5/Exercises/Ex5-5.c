/*
*  5-5. Write a program to verify that duplicated file descriptors share a file offset value
* and open file status flags.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

_Bool is_OFD_shared(int fd_l, int fd_r);

int main(int argc, char *argv[])
{
   int file, fd;

   if(argc!=2)
      usageErr("%s filename\n", argv[0]);

   file = open(argv[1], O_RDONLY);
   if(file == -1)
      errExit("open");

   fd = dup2(file, 4);
   if(fd == -1)
      errExit("dup2");

   if(is_OFD_shared(fd, file))
      printf("The descriptors share the file offset value and open file status flags\n");

   fcntl(fd, F_SETFL, fcntl(fd, F_GETFL)|O_NONBLOCK);
   lseek(fd, 500, SEEK_SET);

   if(is_OFD_shared(fd, file))
      printf("The descriptors share the file offset value and open file status flags\n");

   exit(EXIT_SUCCESS);
}

_Bool is_OFD_shared(int fd_l, int fd_r)
{
   if(fcntl(fd_l, F_GETFL) == fcntl(fd_r, F_GETFL))
      if(lseek(fd_l, 0, SEEK_CUR) == lseek(fd_r, 0, SEEK_CUR))
         return true;

   return false;
}