/*
*  5-3. This exercise is designed to demonstrate why the atomicity guaranteed by opening
* a file with the O_APPEND flag is necessary. Write a program that takes up to three
* command-line arguments:
*
*         $ atomic_append filename num-bytes [x]
*
*  This file should open the specified filename (creating it if necessary) and append
* num-bytes bytes to the file by using write() to write a byte at a time. By default, the
* program should open the file with the O_APPEND flag, but if a third command-line
* argument (x) is supplied, then the O_APPEND flag should be omitted, and instead the
* program should perform an lseek(fd, 0, SEEK_END) call before each write(). Run
* two instances of this program at the same time without the x argument to write
* 1 million bytes to the same file:
*
*         $ atomic_append f1 1000000 & atomic_append f1 1000000
*
*  Repeat the same steps, writing to a different file, but this time specifying the x
* argument:
*
*         $ atomic_append f2 1000000 x & atomic_append f2 1000000 x
*
*  List the sizes of the files f1 and f2 using ls –l and explain the difference.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
   int fd;
   size_t numBytes = 0;
   mode_t filePerm = S_IRUSR | S_IWUSR | S_IRGRP |
                     S_IWGRP | S_IROTH | S_IWOTH;
   int flags = O_WRONLY | O_CREAT;

   if((argc<3 || argc>4) || !strcmp(argv[1], "--help"))
      usageErr("%s filename num-bytes [x]\n", argv[0]);

   if(!argv[3])
      flags |= O_APPEND;
   else if(strcmp(argv[3], "x"))
      errExit("Invalid argument -- \"%s\"\n", argv[3]);

   char *endptr;
   numBytes = strtoul(argv[2], &endptr, 10);
   if(*endptr || (numBytes==ULONG_MAX && errno==ERANGE))
      errExit("strtol");

   fd = open(argv[1], flags, filePerm);
   if(fd == -1)
      errExit("open");

   switch(!argv[3]){
      case 1:
              while(numBytes--){
                 if(write(fd, "", sizeof("")) != sizeof(""))
                    fatal("Couldn't write whole buffer");
              }
              break;
      case 0: 
              while(numBytes--){
                 if(argv[3])
                    if(lseek(fd, 0, SEEK_END) == -1)
                       errExit("lseek");
                 if(write(fd, "", sizeof("")) != sizeof(""))
                    fatal("Couldn't write whole buffer");
              }    
              break;                        
   }

   exit(EXIT_SUCCESS);
}