#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

static int idata = 111;

int main(int argc, char *argv[])
{
    int istack = 222;
    pid_t childPid;

    switch((childPid = fork())){
        case -1:
                 errExit("fork");
        case  0: 
                 idata *= 3;
                 istack *= 3;
                 break;
        default: 
                 sleep(3);
                 break;
    }

    printf("PID=%jd %s idata=%d istack=%d\n", (intmax_t) getpid(),
            !childPid? "(child) " : "(parent)", idata, istack);

    exit(EXIT_SUCCESS);
}