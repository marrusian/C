/*
*   D7. (8 puncte) Program care primeste ca argumente in linia de comanda doua
*  directoare d1 si d2 (d1 exista, d2 nu) si copiaza recursiv toata
*  arborescenta cu originea in d1 intr-o arborescenta cu originea in d2
*  (intre cele doua arborescente difera doar numele directorului origine).
*/

#define _XOPEN_SOURCE 500
#include <sys/types.h>
#include <sys/stat.h>
#include <alloca.h>
#include <limits.h>
#include <ftw.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *dirPath1, *dirPath2;

int copyFile(const char *dest, const char *source, mode_t mode)
{
   int fd_dest, fd_src;
   off_t length;

   if((fd_dest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, mode)) == -1)
      return -1;
   if((fd_src = open(source, O_RDONLY)) == -1)
      return -1;

   if((length = lseek(fd_src, 0, SEEK_END)) == -1)
      return -1;
   lseek(fd_src, 0, SEEK_SET);

   char *buffer = (char*) malloc(length*sizeof(char));
   if(!buffer)
      return -1;

   if(read(fd_src, buffer, length) == -1)
      return -1;
   if(write(fd_dest, buffer, length) != length)
      return -1;

   if(close(fd_dest) == -1 || close(fd_src) == -1)
      return -1;

   free(buffer);
   return 0;
}

int copyDir(const char *pathname, const struct stat *sbuf,
            int type, struct FTW *ftwbuf)
{
   mode_t umk = umask(0);
#ifdef PATH_MAX
   char pathBuf[PATH_MAX];
#else
   char *pathBuf = alloca(pathconf(pathname, _PC_PATH_MAX));
#endif

   strcpy(pathBuf, dirPath2);
   strcat(pathBuf, strchr(pathname, '/')? strchr(pathname, '/') : "\0");

   if(type == FTW_D){
      if(mkdir(pathBuf, sbuf->st_mode) == -1){
         fprintf(stderr, "Failed to create directory \'%s\'\n", pathBuf);
         perror("Reason");
         return -1;
      }
   }
   else{
      if(copyFile(pathBuf, pathname, sbuf->st_mode) == -1){
         fprintf(stderr, "Failed to copy file \'%s\'\n", pathname);
         perror("Reason");
         return -1;
      }
   }

   umask(umk);
   return 0;
}

int main(int argc, char *argv[])
{
   if(argc!=3){
      fprintf(stderr, "Usage: %s dirpath1 dirpath2\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   dirPath1 = argv[1];
   dirPath2 = argv[2];

   if(nftw(argv[1], copyDir, sysconf(_SC_OPEN_MAX)*0.02, 0) == -1){
      fprintf(stderr, "%s: nftw() failed\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   exit(EXIT_SUCCESS);
}
