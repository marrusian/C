#define _XOPEN_SOURCE 500
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

#define MAX_MTEXT 1024

typedef struct msg_buffer{
	long mtype;
	char mtext[MAX_MTEXT];
} Mbuf;

_Noreturn static void    /* Print (optional) message, then usage description */
usageError(const char *progName, const char *msg)
{
	if(msg != NULL)
		fprintf(stderr, "%s", msg);
	fprintf(stderr, "Usage: %s [-n] msqid msg-type [msg-text]\n", progName);
	fprintf(stderr, "       -n      Use IPC_NOWAIT flag\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	int msqid, flags, msgLen;
	Mbuf msg;		/* Message buffer for msgsnd() */
	int opt;        /* Option character for getopt() */

	/* Parse CL options and arguments */

	flags = 0;
	while((opt = getopt(argc, argv, "n")) != -1){
		if (opt == 'n')
			flags |= IPC_NOWAIT;
		else
			usageError(argv[0], NULL);
	}

	if(argc < optind+2 || argc > optind+3)
		usageError(argv[0], "Wrong number of arguments\n");

	msqid = getInt(argv[optind], 0, "msqid");
	msg.mtype = getInt(argv[optind+1], 0, "msg-type");

	if(argc > optind+2){   /* 'msg-text' was supplied */
		msgLen = strlen(argv[optind+2]) + 1;
		if(msgLen > MAX_MTEXT)
			cmdLineErr("msg-text too long (max: %d characters)\n", MAX_MTEXT);

		memcpy(msg.mtext, argv[optind+2], msgLen);
	}
	else{		/* No 'msg-text' => zero-length msg */
		msgLen = 0;
	}

	/* Send Message */

	if(msgsnd(msqid, &msg, msgLen, flags) == -1)
		errExit("msgsnd()");

	exit(EXIT_SUCCESS);
}