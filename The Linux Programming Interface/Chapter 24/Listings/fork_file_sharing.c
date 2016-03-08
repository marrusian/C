#define _XOPEN_SOURCE 500 // mkstemp()
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
    int fd, flags;
    char template[] = "/tmp/testXXXXXX";

    setbuf(stdout, NULL);

    if((fd = mkstemp(template)) == -1)
        errExit("mkstemp()");

    printf("File offset before fork(): %jd\n",
             (intmax_t) lseek(fd, 0, SEEK_CUR));

    if((flags = fcntl(fd, F_GETFL)) == -1)
        errExit("fcntl()");

    printf("O_APPEND flag before fork() is: %s\n",
            (flags & O_APPEND)? "on" : "off");

    switch(fork()){
        case 0:
                if(lseek(fd, 1000, SEEK_SET) == -1)
                    errExit("lseek()");

                if((flags = fcntl(fd, F_GETFL)) == -1)
                    errExit("fcntl()");
                flags |= O_APPEND;

                if(fcntl(fd, F_SETFL, flags) == -1)
                    errExit("fcntl()");
                _exit(EXIT_SUCCESS);

        default: 
                 if(wait(NULL) == -1)
                    errExit("wait()");

                 printf("Child has exited\n");
                 printf("File offset in parent: %jd\n",
                          (intmax_t) lseek(fd, 0, SEEK_CUR));

                 if((flags = fcntl(fd, F_GETFL)) == -1)
                    errExit("fcntl()");
                 printf("O_APPEND flag in parent is: %s\n",
                         (flags & O_APPEND)? "on" : "off");
    }

	exit(EXIT_SUCCESS);
}