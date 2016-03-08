#define _XOPEN_SOURCE 500
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void sigHandler(int sig)
{
    static int count = 0;

    /* UNSAFE: This handler uses NON-ASYNC-SIGNAL-SAFE functions
               (printf(), exit()); */

    if(sig == SIGINT){
        ++count;
        printf("Caught SIGINT (%d)\n", count);
        return;
    }

    /* Must be SIGQUIT - print a message and TERMINATE the process */

    printf("Caught SIGQUIT - that's all folks!\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    /* Establish SAME HANDLER for SIGINT and SIGQUIT */
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sigHandler;

    if(sigaction(SIGINT, &sa, NULL) == -1){
        fprintf(stderr, "sigction()");
        exit(EXIT_FAILURE);
    }

    if(sigaction(SIGQUIT, &sa, NULL) == -1){
        fprintf(stderr, "signal()");
        exit(EXIT_FAILURE);
    }
/*
    if(signal(SIGINT, sigHandler) == SIG_ERR){
        fprintf(stderr, "signal()");
        exit(EXIT_FAILURE);
    }

    if(signal(SIGQUIT, sigHandler) == SIG_ERR){
        fprintf(stderr, "signal()");
        exit(EXIT_FAILURE);
    }
*/
    while(1)
        pause();
}