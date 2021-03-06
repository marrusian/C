#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printWaitStatus(const char *msg, int status)
{
	if(msg != NULL)
		printf("%s", msg);

	if(WIFEXITED(status))
		printf("Child exited, status = %d\n", WEXITSTATUS(status));
	else if(WIFSIGNALED(status)){
		printf("Child killed by signal %d (%s)",
			    WTERMSIG(status), strsignal(WTERMSIG(status)));

#ifdef WCOREDUMP
		if(WCOREDUMP(status))
			printf(" (core dumped)");
#endif
	    printf("\n");
	}
	else if(WIFSTOPPED(status)){
		printf("Child stopped by signal %d (%s)\n",
			    WSTOPSIG(status), strsignal(WSTOPSIG(status)));
	}
#ifdef WIFCONTINUED
	else if(WIFCONTINUED(status))
		printf("Child continued\n");
#endif
	else{
		printf("What happened to this child? (status = %x)\n",
			    (unsigned int) status);
	}
}