#define _XOPEN_SOURCE 500
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

union semun{
	int					val;
	struct semid_ds		*buf;
	unsigned short		*array;
};

int main(int argc, char *argv[])
{
	struct semid_ds ds;
	union semun arg, dummy;			/* Fourth argument for semctl() */
	int semid;

	if(argc!=2 || !strcmp(argv[1], "--help"))
		usageErr("%s semid\n", argv[0]);

	semid = getInt(argv[1], 0, "semid");

	arg.buf = &ds;
	if(semctl(semid, 0, IPC_STAT, arg) == -1)
		errExit("semctl()");

	printf("Semaphore changed: %s", ctime(&ds.sem_ctime));
	printf("Last semop():	   %s", ctime(&ds.sem_otime));

	/* Display per-semaphore information */

	arg.array = calloc(ds.sem_nsems, sizeof(arg.array[0]));
	if(arg.array == NULL)
		errExit("calloc()");
	if(semctl(semid, 0, GETALL, arg) == -1)
		errExit("semctl() - GETALL");

	printf("Sem #  Value  SEMPID  SEMNCNT  SEMZCNT\n");
	for(unsigned int j=0; j<ds.sem_nsems; ++j)
		printf("%3d   %5d   %5d   %5d\n", j, arg.array[j],
				semctl(semid, j, GETPID, dummy),
				semctl(semid, j, GETNCNT, dummy),
				semctl(semid, j, GETZCNT, dummy));

	exit(EXIT_SUCCESS);
}