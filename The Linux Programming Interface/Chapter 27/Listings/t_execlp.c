#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
    if(argc!=2 || !strcmp(argv[1], "--help"))
       usageErr("%s pathname\n", argv[0]);

    execlp(argv[1], argv[1], "hello world", (char*) NULL);
	errExit("execlp()");
}