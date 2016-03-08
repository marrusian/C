#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

static void             /* Print 'msg' plus value of fpathconf(fd, name) */
fpathconfPrint(const char *msg, int fd, int name)
{
   long lim;

   errno = 0;
   if((lim = fpathconf(fd, name)) == -1){
      if(errno)
         errExit("fpathconf %s", msg);

      printf("%s (indeterminate)\n", msg);
   }
   else
      printf("%s %ld\n", msg, lim);
}

int main(int argc, char *argv[])
{
   fpathconfPrint("_PC_NAME_MAX:  ", STDIN_FILENO, _PC_NAME_MAX);
   fpathconfPrint("_PC_PATH_MAX:  ", STDIN_FILENO, _PC_PATH_MAX);
   fpathconfPrint("_PC_PIPE_BUF:  ", STDIN_FILENO, _PC_PIPE_BUF);

   exit(EXIT_SUCCESS);
}