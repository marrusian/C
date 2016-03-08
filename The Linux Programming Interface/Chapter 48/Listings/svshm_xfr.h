#define _XOPEN_SOURCE 500
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/binary_sems.h"
#include "/home/marru/C Programming/LPI/tlpi-dist/lib/tlpi_hdr.h"


#define SHM_KEY 0x1234		/* Key for shared memory segment */
#define SEM_KEY 0x5678		/* Key for semaphore set */

#define OBJ_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
							/* Permissions for our IPC objects */

#define WRITE_SEM 0  		/* Writer has access to shared memory */
#define READ_SEM  1			/* Reader has access to shared memory */

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

struct shmseg{				/* Defines structure of shared memory segment */
	int cnt;				/* Number of bytes used in 'buf' */
	char buf[BUF_SIZE];		/* Data being transferred */
};

