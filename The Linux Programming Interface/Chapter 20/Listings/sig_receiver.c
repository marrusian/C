#define _GNU_SOURCE
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/signal_functions.h"

static int sigCnt[NSIG];
static volatile sig_atomic_t gotSigInt = 0;

static void handler(int sig)
{
	if(sig == SIGINT)
		gotSigInt = 1;
	else
		++sigCnt[sig];
}

int main(int argc, char *argv[])
{
	int numSecs;
	sigset_t pendingMask, blockingMask, emptyMask;

	printf("%s: PID is %jd\n", argv[0], (intmax_t) getpid());

	for(int n=1; n<NSIG; ++n)
		signal(n, handler);

	if(argc>1){
		numSecs = getInt(argv[1], GN_GT_0, NULL);

		sigfillset(&blockingMask);
		if(sigprocmask(SIG_SETMASK, &blockingMask, NULL) == -1)
			errExit("sigprocmask()");

		printf("%s: sleeping for %d seconds\n", argv[0], numSecs);
		sleep(numSecs);

		if(sigpending(&pendingMask) == -1)
			errExit("sigpending()");

		printf("%s: pending signal are: \n", argv[0]);
		printSigset(stdout, "\t\t", &pendingMask);

		sigemptyset(&emptyMask);
		if(sigprocmask(SIG_SETMASK, &emptyMask, NULL) == -1)
			errExit("sigprocmask()");
	}

	while(!gotSigInt)
		pause();

	puts("");
	for(int n=1; n<NSIG; ++n)
		if(sigCnt[n])
			printf("%s: signal %d[%s] caught %d time%s\n", argv[0], n,
				     strsignal(n), sigCnt[n], (sigCnt[n] == 1)? "" : "s");

	exit(EXIT_SUCCESS);
}