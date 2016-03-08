#define _FILE_OFFSET_BITS 64
#define _GNU_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <malloc.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
   int fd, fo;
   ssize_t numRead;
   size_t length, alignment;
   off_t offset;
   void * buf;

   if(argc < 3 || !strcmp(argv[1], "--help"))
      usageErr("%s file length [offset [alignment]]\n", argv[0]);

   length = getLong(argv[2], GN_ANY_BASE, "length");
   offset = (argc>3)? getLong(argv[3], GN_ANY_BASE, "offset") : 0;
   alignment = (argc>4)? getLong(argv[4], GN_ANY_BASE, "alignment") : 4096;

   if((fd = open(argv[1], O_RDONLY | O_DIRECT)) == -1)
      errExit("open()");
   if((fo = open("output.txt", O_WRONLY | O_CREAT | O_DIRECT)) == -1)
      errExit("open()");

   buf = (char*) memalign(alignment*2, length+alignment) + alignment;
   if(!buf)
      errExit("memalign()");

   if(lseek(fd, offset, SEEK_SET) == -1)
      errExit("lseek()");

   if((numRead = read(fd, buf, length)) == -1)
      errExit("read()");


   printf("Read %jd bytes \n", (intmax_t) numRead);

   if(write(fo, buf, numRead) != numRead)
      errExit("write()");

   printf("Wrote %jd bytes \n", (intmax_t) numRead); 

   exit(EXIT_SUCCESS);
}
