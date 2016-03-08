#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
   int fd;

   fd = open(argv[1], O_WRONLY);  /* Check if file exists */

   if(fd != -1){
      printf("[PID %ld] File \"%s\" already exists\n",
              (long) getpid(), argv[1]);
      close(fd);
   }
   else{
      if(errno != ENOENT)     /* Failed for unexpected reason */
         errExit("open");
      else{
         /* WARNING: WINDOW FOR FAILURE */
          printf("[PID %ld] File \"%s\" doesn't exist yet\n",
                 (long) getpid(), argv[1]);
         if(argc>2){
            sleep(5);
            printf("[PID %ld] Done sleeping\n", (long) getpid());
         }
         
         fd = open(argv[1], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
         if(fd == -1)
            errExit("open");

         printf("[PID %ld] Created file \"%s\" exclusively\n",
                (long) getpid(), argv[1]);         /* MAY NOT BE TRUE! */
      }
 
   }

   exit(EXIT_SUCCESS);
}