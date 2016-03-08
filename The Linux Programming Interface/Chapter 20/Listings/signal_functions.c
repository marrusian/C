#define _BSD_SOURCE
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSigSet(FILE *of, const char *prefix, const siget_t *sigset)
{
	int cnt = 0;

	for(int sig = 1; sig < NSIG; ++sig){
		if(sigismember(sigset, sig)){
			++cnt;
			fprintf(of, "%s%d (%s)\n", prefix, sig, strsignal(sig));
		}
	}

	if(!cnt)
		fprintf(of, "%s<empty signal set>\n", prefix);
}

int printSigMask(FILE *of, const char *msg)
{
	sigset_t currMask;

	if(msg)
		fprintf(of, "%s", msg);

	if(sigprocmask(SIG_BLOCK, NULL, &currMask) == -1)
		return -1;

	printSigSet(of, "\t\t", &currMask);

	return 0;
}

int printPendingSigs(FILE *of, const char *msg)
{
	sigset_t pendingSigs;

	if(msg)
		fprintf(of, "%s", msg);

	if(sigpending(&pendingSigs) == -1)
		return -1;

	printSigSet(of, "\t\t", &pendingSigs);

	return 0;
}