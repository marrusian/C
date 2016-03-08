/*
 * 15-7.
 * Write a simple version of the chattr(1) command, which modifies
 * file i-node flags.
 * See the chattr(1) man page for details of the chattr command-line
 * interface. (You don’t need to implement the –R, –V, and –v options.)
*/

#include <linux/fs.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int parse_mode(const char *mode_str)
{
   int attr = 0;

   for(int i=1; mode_str[i]; ++i)
      switch(mode_str[i]){
         case 'a': attr |= FS_APPEND_FL;       break;
         case 'A': attr |= FS_NOATIME_FL;      break;
         case 'c': attr |= FS_COMPR_FL;        break;
         case 'd': attr |= FS_NODUMP_FL;       break;
         case 'D': attr |= FS_DIRSYNC_FL;      break;
         case 'i': attr |= FS_IMMUTABLE_FL;    break;
         case 'j': attr |= FS_JOURNAL_DATA_FL; break;
         case 's': attr |= FS_SECRM_FL;        break;
         case 'S': attr |= FS_SYNC_FL;         break;
         case 't': attr |= FS_NOTAIL_FL;       break;
         case 'T': attr |= FS_TOPDIR_FL;       break;
         case 'u': attr |= FS_UNRM_FL;         break;
         default : return -1; 
      } 

   return attr;
}

int main(int argc, char *argv[])
{
   int fd;
   int attr_mode, attr_file;

   /* We assume that no options are specified */
   if(argc<3 || !strcmp(argv[1], "--help"))
      usageErr("%s [-+=AacDdijSsTtu] files...\n", argv[0]);

   if(!strchr("-+=", argv[1][0]))
      usageErr("Must use =, - or +\n");  

   if((attr_mode = parse_mode(argv[1])) == -1)
      usageErr("%s [-+=AacDdijSsTtu] files...\n", argv[0]);

   for(int i=2; argv[i]; ++i){
      fd = open(argv[i], O_RDONLY);

      if((ioctl(fd, FS_IOC_GETFLAGS, &attr_file) == -1))
         errExit("ioctl()");
      
      switch(argv[1][0]){
         case '-': attr_file &= ~attr_mode; break; 
         case '+': attr_file |= attr_mode;  break;
         case '=': attr_file = attr_mode;   break;
      }

      if((ioctl(fd, FS_IOC_SETFLAGS, &attr_file) == -1))
         errExit("ioctl()");

      close(fd); 
   } 
   
   exit(EXIT_SUCCESS);
}
