#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	int flags;

	if(argc>1){
		if((flags = fcntl(STDOUT_FILENO, F_GETFD)) == -1)
			errExit("fcntl() - F_GETFD");

		flags |= FD_CLOEXEC;

		if(fcntl(STDOUT_FILENO, F_SETFD, flags) == -1)
			errExit("fcntl() - F_SETFD");
	}

	execlp("ls", "ls", "-l", argv[0], (char*) NULL);
	errExit("execlp()");
}