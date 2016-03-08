#define _XOPEN_SOURCE 500
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	int numSigs, sig;
	pid_t pid;

	if(argc<4 || !strcmp(argv[1], "--help"))
		usageErr("%s pid num-sigs sig-num [sig-num-2]\n", argv[0]);

	pid = getLong(argv[1], 0, "PID");
	numSigs = getInt(argv[2], GN_GT_0, "num-sigs");
	sig = getInt(argv[3], 0, "sig-num");

	/* Send signals to receiver */

	printf("%s: sending signal %d to process %jd %d times\n",
		    argv[0], sig, (intmax_t) pid, numSigs);

	for(int j=0; j<numSigs; ++j)
		if(kill(pid, sig) == -1)
			errExit("kill");

	/* If a fourth CLA was specified, send that signal */

	if(argc>4)
		if(kill(pid, getInt(argv[4], 0, "sig-num-2")) == -1)
			errExit("kill");

	printf("%s: exiting\n", argv[0]);
	exit(EXIT_SUCCESS);
}