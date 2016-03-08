#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/curr_time.h"

int main(int argc, char *argv[])
{
	int numDead; /* Number of children so far waited for */
	pid_t childPid;

	if(argc<2 || !strcmp(argv[1], "--help"))
		usageErr("%s sleep-time...\n", argv[0]);

	setvbuf(stdout, NULL, _IONBF, 0);

	for(int j=1; j<argc; ++j){
		switch(fork()){
			case -1:
			         errExit("fork()");
			case  0:
			         printf("[%s] child %d started with PID %jd, sleeping %s "
			         	    "seconds\n", currTime("%T"), j, (intmax_t) getpid(), argv[j]);
			         sleep(getInt(argv[j], GN_NONNEG, "sleep-time"));
			         _exit(EXIT_SUCCESS);
			default:
			         break;
		}
	}

	numDead = 0;
	while((childPid = wait(NULL)) != -1){
		++numDead;
		printf("[%s] wait() returned child PID %jd (numDead=%d)\n",
			    currTime("%T"), (intmax_t) childPid, numDead);
	}

	if(errno == ECHILD)
		printf("No more children - bye!\n");
	else
		errExit("wait()");

	exit(EXIT_SUCCESS);
}