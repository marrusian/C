#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

#ifndef BUF_SIZE       /* Allow "cc -D" to override definition */
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[])
{
   int inputFD, outputFD, openFlags;
   mode_t filePerms;
   ssize_t numRead;
   char buf[BUF_SIZE];

   if(argc!=3 || !strcmp(argv[1], "--help"))
      usageErr("%s old-file new-file\n", argv[0]);

   inputFD = open(argv[1], O_RDONLY);
   if(inputFD == -1)
      errExit("Opening file %s", argv[1]);

   openFlags = O_CREAT | O_WRONLY | O_TRUNC;
   filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
               S_IROTH | S_IWOTH;    /* rw-rw-rw- */
   outputFD = open(argv[2], openFlags, filePerms);
   if(outputFD == -1)
      errExit("Opening file %s", argv[2]);

   while((numRead = read(inputFD, buf, BUF_SIZE)) > 0)
      if(write(outputFD, buf, numRead) != numRead)
         fatal("Couldn't write whole buffer");
   if(numRead == -1)
      errExit("read");

   if(close(inputFD) == -1)
      errExit("Close input");
   if(close(outputFD) == -1)
      errExit("Close output");

   exit(EXIT_SUCCESS);
}
