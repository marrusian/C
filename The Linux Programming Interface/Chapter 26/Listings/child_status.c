#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/print_wait_status.h"

int main(int argc, char *argv[])
{
	int status;
	pid_t childPid;

	if(argc>1 && !strcmp(argv[1], "--help"))
		usageErr("%s [exit-status]\n", argv[0]);

	switch(fork()){
		case -1:
		         errExit("fork()");
		case  0:
		         printf("Child started with PID = %jd\n", (intmax_t) getpid());
		         if(argc>1)
		         	exit(getInt(argv[1], 0, "exit-status"));
		         else
		         	while(1)
		         		pause();
		         exit(EXIT_FAILURE);
		default:
		         while(1){
		         	childPid = waitpid(-1, &status, WUNTRACED | WCONTINUED);
		            if(childPid == -1)
		            	errExit("waitpid()");

		            printf("waitpid() returned: PID = %jd; status = 0x%04x (%d, %d)\n",
		            	    (intmax_t) childPid, (unsigned int) status, status >> 8, status & 0x00FF);
		            printWaitStatus(NULL, status);

		            if(WIFEXITED(status) || WIFSIGNALED(status))
		            	exit(EXIT_SUCCESS);
		        }
	}
}
