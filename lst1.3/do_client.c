#include "main.h"

void do_client(int *socket)
{
    int errno;
    char buf[80] = {0};
    char *message = "%A %d-%b-%Y %l:%M %p";
    printf("Parent pid: %d\n", getppid());

    close(socket[0]); socket[0] = -1; /* Use socket[1] only */
    printf("Child sending request '%s'\n", message);
    fflush(stdout);
    
    errno = write_message(socket[1], message);
    if (errno < 0) {
        printf("Failed to write message...\n");
        return;
    }

    /* Then shutdown client */
    errno = shutdown(socket[1], SHUT_WR);
    if (errno < 0) {
        printf("Failed to shutdown...\n");
        return;
    }

    /* Receive message from server */
    printf("Client receiving...\n");
    read_message(socket[1]);
    fflush(stdout);
}
