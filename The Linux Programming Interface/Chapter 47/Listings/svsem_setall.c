#define _XOPEN_SOURCE 500
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

union semun{
    int                 val;
    struct semid_ds     *buf;
    unsigned short      *array;
};

int main(int argc, char *argv[])
{
    struct semid_ds ds;
    union semun arg;
    int semid;

    if(argc<3 || !strcmp(argv[1], "--help"))
        usageErr("%s semid val...\n", argv[0]);

    semid = getInt(argv[1], 0, "semid");

    /* Obtain size of semaphore set */

    arg.buf = &ds;
    if(semctl(semid, 0, IPC_STAT, arg) == -1)
        errExit("semctl()");

    if(ds.sem_nsems != (unsigned long) (argc-2))
        cmdLineErr("Set contains %jd semaphores, but %d values were supplied\n",
                    (intmax_t) ds.sem_nsems, argc-2);

    /* Set up array of values; perform semaphore initialization */

    arg.array = calloc(ds.sem_nsems, sizeof(arg.array[0]));
    if(arg.array == NULL)
        errExit("calloc()");

    for(int j=2; j<argc; ++j)
        arg.array[j-2] = getInt(argv[j], 0, "val");

    if(semctl(semid, 0, SETALL, arg) == -1)
        errExit("semctl() - SETALL");
    printf("Semaphore values changed (PID = %jd)\n", (intmax_t) getpid());

    exit(EXIT_SUCCESS);
}