/*
*  5-4. Implement dup() and dup2() using fcntl() and, where necessary, close(). (You may
* ignore the fact that dup2() and fcntl() return different errno values for some error
* cases.) For dup2(), remember to handle the special case where oldfd equals newfd. In
* this case, you should check whether oldfd is valid, which can be done by, for example,
* checking if fcntl(oldfd, F_GETFL) succeeds. If oldfd is not valid, then the function
* should return –1 with errno set to EBADF.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int my_dup(int oldfd);
int my_dup2(int oldfd, int newfd);

int main(int argc, char *argv[])
{
   int fd;

   fd = my_dup2(2, 3);
   if(fd == -1)
      errExit("my_dup2()");

   if(write(fd, "Success!\n", sizeof("Success!\n")) != sizeof("Success!\n"))
      errExit("write()");

   exit(EXIT_SUCCESS);
}

int my_dup(int oldfd) {return fcntl(oldfd, F_DUPFD, 0);}

int my_dup2(int oldfd, int newfd)
{
   if(fcntl(oldfd, F_GETFL) == -1)
      return -1;

   if(newfd<0 || newfd>=sysconf(_SC_OPEN_MAX)){
      errno = EBADF;
      return -1;
   }

   if(oldfd != newfd){
      register int err = errno;
      if(close(newfd)==-1 && errno!=EBADF)
         return -1;
      errno = err;

      if(fcntl(oldfd, F_DUPFD, newfd) == -1)
         return -1;

      fcntl(newfd, F_SETFL, fcntl(newfd, F_GETFL)&(~FD_CLOEXEC));
   }

   return newfd;
}
