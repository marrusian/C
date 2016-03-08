#define _XOPEN_SOURCE 500
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

#define CMD_SIZE 256

int main(int argc, char *argv[])
{
	char cmd[CMD_SIZE];
	pid_t childPid;

	setvbuf(stdout, NULL, _IONBF, 0);

	printf("Parent PID = %jd\n", (intmax_t) getpid());

	switch((childPid = fork())){
		case -1:
		         errExit("fork()");
		case  0:
		         printf("Child (PID = %jd) exiting\n", (intmax_t) getpid());
		         _exit(EXIT_SUCCESS);
		default:
		         sleep(3);
		         snprintf(cmd, CMD_SIZE, "ps | grep %s", basename(argv[0]));
		         cmd[CMD_SIZE-1] = '\0';
		         system(cmd);

		         if(kill(childPid, SIGKILL) == -1)
		         	errMsg("kill()");
		         sleep(3);
		         printf("After sending SIGKILL to zombie (PID = %jd):\n", (intmax_t) childPid);
		         system(cmd);
	}

	exit(EXIT_SUCCESS);
}