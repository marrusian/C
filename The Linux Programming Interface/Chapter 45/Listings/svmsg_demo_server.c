#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY_FILE "/some-path/some-file"

int main(int argc, char *argv[])
{
    int msqid;
    key_t key;
    const int MQ_PERMS = S_IRUSR | S_IWUSR | S_IWGRP;  /* rw--w---- */

    /* Optional code here to check if another server process is already running */

    /* Generate the key for the message queue */

    if((key = ftok(KEY_FILE, 1)) == -1)
        errExit("ftok()");

    /* While msgget() fails, try creating the queue exclusively */

    while((msqid = msgget(key, IPC_CREAT | IPC_EXCL | MQ_PERMS)) == -1){
        if(errno == EEXIST){ /* MQ with the same key already exists; remove it and try again */
            msqid = msgget(key, 0);
            if(msqid == -1)
                errExit("msgget() failed to retrieve old queue ID");
            if(msgctl(msqid, IPC_RMID, NULL) == -1)
                errExit("msgget() failed to delete old queue");
            printf("Removed old message queue (id = %d)\n", msqid);
        }
        else{   /* Some other error => give up */
            errExit("msgget() failed");
        }
    }

    /* Upon loop exit, we've successfully created the message queue,
       and we can then carry on to do other work... */

    exit(EXIT_SUCCESS);
}
