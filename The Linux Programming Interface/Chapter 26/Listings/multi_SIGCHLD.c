#define _XOPEN_SOURCE 500
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/print_wait_status.h"
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/curr_time.h"
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

static volatile int numLiveChildren = 0;

static void sigChldHandler(int sig)
{
    int status, savedErrno;
    pid_t childPid;

    savedErrno = errno;
    printf("%s handler: Caught SIGCHLD\n", currTime("%T"));

    while((childPid = waitpid(-1, &status, WNOHANG)) > 0){
        printf("%s handler: Reaped child %jd - ", currTime("%T"),
                (intmax_t) childPid);
        printWaitStatus(NULL, status);
        --numLiveChildren;
    }

    if(childPid == -1 && errno != ECHILD)
        errMsg("waitpid()");

    printf("%s handler: returning\n", currTime("%T"));

    errno = savedErrno;
}

int main(int argc, char *argv[])
{
    int sigCnt;
    struct sigaction sa;

    if(argc<2 || !strcmp(argv[1], "--help"))
        usageErr("%s child-sleep-time...\n", argv[0]);

    setvbuf(stdout, NULL, _IONBF, 0);

    sigCnt = 0;
    numLiveChildren = argc-1;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = sigChldHandler;
    if(sigaction(SIGCHLD, &sa, NULL) == -1)
        errExit("sigaction");

    for(int j=1; j<argc; ++j){
        switch(fork()){
            case -1:
                     errExit("fork()");
            case  0:
                     sleep(getInt(argv[j], GN_NONNEG, "child-sleep-time"));
                     printf("%s Child %d (PID = %jd) exiting\n", currTime("%T"),
                              j, (intmax_t) getpid());
                     _exit(EXIT_SUCCESS);
            default:
                     break;
        }
    }

    while(numLiveChildren > 0){
        pause();
        ++sigCnt;
   }

    printf("%s All %d children have terminated; SIGCHDL was caught "
           "%d times\n", currTime("%T"), argc-1, sigCnt);


    exit(EXIT_SUCCESS);
}