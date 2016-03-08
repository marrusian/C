/*
*  5-6. After each of the calls to write() in the following code, explain what the content of
* the output file would be, and why:
*
*     fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
*     fd2 = dup(fd1);
*     fd3 = open(file, O_RDWR);
*     write(fd1, "Hello,", 6);
*     write(fd2, "world", 6);
*     lseek(fd2, 0, SEEK_SET);
*     write(fd1, "HELLO,", 6);
*     write(fd3, "Gidday", 6);
*/


/*
 a) Hello,
 b) Hello,world
 c) HELLO,world
 d) Giddayworld

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{ 
   int fd1, fd2, fd3;

   if(argc!=2)
      usageErr("%s filename\n", argv[0]);

   fd1 = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
   fd2 = dup(fd1);
   fd3 = open(argv[1], O_RDWR);
   write(fd1, "Hello,", 6);
   write(fd2, "world", 6);
   lseek(fd2, 0, SEEK_SET);
   write(fd1, "HELLO,", 6);
   write(fd3, "Gidday", 6);

   exit(EXIT_SUCCESS);
}