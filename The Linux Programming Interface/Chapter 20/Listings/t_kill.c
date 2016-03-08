#define _GNU_SOURCE
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	int s, sig;

	if(argc!=3 || !strcmp(argv[1], "--help"))
		usageErr("%s sig-num pid\n", argv[0]);

	sig = getInt(argv[2], 0, "sig-num");

	s = kill(getLong(argv[1], 0, "pid"), sig);

	if(sig){
		if(s == -1)
			errExit("kill");
	}
	else{
		if(s == 0)
			printf("Process exists and we can sent it a signal\n");
		else{
			if(errno == EPERM)
				printf("Process exists, but we don't have "
					   "permission to send it a signal\n");
			else if(errno == ESRCH)
				printf("Process does not exist\n");
			else
				errExit("kill");
		}
	} 

	exit(EXIT_SUCCESS);
}