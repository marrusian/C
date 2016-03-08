#include "svmsg_file.h"

static int clientId;

static void             /* Exit Handler */
removeQueue(void)
{
    if(msgctl(clientId, IPC_RMID, NULL) == -1)
        errExit("msgctl()");
}

int main(int argc, char *argv[])
{
    struct requestMsg req;
    struct responseMsg resp;
    int serverId, numMsgs;
    ssize_t msgLen, totBytes;

    if(argc!=2 || !strcmp(argv[1], "--help"))
        usageErr("%s pathname\n", argv[0]);

    if(strlen(argv[1]) > sizeof(req.pathname)-1)
        cmdLineErr("pathname too long (max: %jd bytes)\n",
                    (intmax_t) sizeof(req.pathname) -1);

    /* Get server's queue identifier; creaet queue for response */

    if((serverId = msgget(SERVER_KEY, S_IWUSR)) == -1)
        errExit("msgget() - server message queue");

    if((clientId = msgget(IPC_PRIVATE, S_IRUSR | S_IWUSR | S_IWGRP)) == -1)
        errExit("msgget() - client message queue");

    if(atexit(removeQueue) != 0)
        errExit("atexit()");

    /* Send message asking for file named in argv[1] */

    req.mtype = 1;                  /* Any type will do */
    req.clientId = clientId;
    strncpy(req.pathname, argv[1], sizeof(req.pathname) - 1);
    req.pathname[sizeof(req.pathname) - 1] = '\0';  /* Ensure string is terminated */

    if(msgsnd(serverId, &req, REQ_MSG_SIZE, 0) == -1)
        errExit("msgsnd()");

    /* Get first response, which may be failure notification */

    msgLen = msgrcv(clientId, &resp, RESP_MSG_SIZE, 0, 0);
    if(msgLen == -1)
        errExit("msgrcv()");

    if(resp.mtype == RESP_MT_FAILURE){
        printf("%s\n", resp.data);      /* Display msg from server */
        if(msgctl(clientId, IPC_RMID, NULL) == -1)
            errExit("msgctl()");
        exit(EXIT_FAILURE);
    }

    /* File was opened successfully by server; process messages
       (including the one already received) containing file data */

    totBytes = msgLen;          /* Count first message */
    for(numMsgs = 1; resp.mtype == RESP_MT_DATA; ++numMsgs){
        msgLen = msgrcv(clientId, &resp, RESP_MSG_SIZE, 0, 0);
        if(msgLen == -1)
            errExit("msgcrv()");

        totBytes += msgLen;
    }

    printf("Received %jd bytes (%d messages)\n", (intmax_t) totBytes, numMsgs);
    exit(EXIT_SUCCESS);
}