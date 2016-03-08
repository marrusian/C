#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	printf("Initial value of USER: %s\n", getenv("USER"));
	if(putenv("USER=britta"))
		errExit("putenv()");

	execl("/usr/bin/printenv", "printenv", "USER", "SHELL", (char*) NULL);
	errExit("execl()");
}