#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	char *argVec[10];
	char *envVec[] = {"GREET=salut", "BYE=adieu", NULL};

	if(argc!=2 || !strcmp(argv[1], "--help"))
		usageErr("%s pathname\n", argv[0]);

	argVec[0] = strrchr(argv[1], '/');
	if(argVec[0] != NULL)
		++argVec[0];
	else
		argVec[0] = argv[1];
	argVec[1] = "hello word";
	argVec[2] = "goodbye";
	argVec[3] = NULL;

	execve(argv[1], argVec, envVec);
	errExit("execve()");
}