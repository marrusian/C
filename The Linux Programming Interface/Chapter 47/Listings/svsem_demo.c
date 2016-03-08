#define _XOPEN_SOURCE 500
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/curr_time.h"
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/semun.h"
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
    int semid;

    if(argc<2 || argc>3 || !strcmp(argv[1], "--help"))
        usageErr("%s init-value\n",
                 "   or: %s semid operation\n", argv[0], argv[0]);

    if(argc == 2){      /* Create and initialize semaphore */
        union semun arg;

        semid = semget(IPC_PRIVATE, 1, S_IRUSR | S_IWUSR);
        if(semid == -1)
            errExit("semid()");

        arg.val = getInt(argv[1], 0, "init-value");
        if(semctl(semid, 0, SETVAL, arg) == -1)
            errExit("semctl()");

        printf("Semaphore ID = %d\n", semid);
    }
    else{               /* Perform an operation on first semaphore */
        struct sembuf sop;

        semid = getInt(argv[1], 0, "semid");

        sop.sem_num = 0;        /* Specifies first semaphore in set */
        sop.sem_op = getInt(argv[2], 0, "operation"); /* Add, substract, or wait for 0 */
        sop.sem_flg = 0;        /* No special options for operation */

        printf("%jd: about to semop at %s\n", (intmax_t) getpid(), currTime("%T"));
        if(semop(semid, &sop, 1) == -1)
            errExit("semop()");

        printf("%jd: semop completed at %s\n", (intmax_t) getpid(), currTime("%T"));
    }

    exit(EXIT_SUCCESS);
}