#include "main.h"

void do_server(int *socket)
{
    int errno;
    char buf[80] = {0};
    char reply[80] = {0};
    time_t td;
    close(socket[0]); socket[0] = -1; /* Use socket[1] only */
    copy_message(socket[1], buf);
    printf("Server receive message '%s'", buf);
    time(&td);
    strftime(reply, sizeof(reply), buf, localtime(&td));

    write_message(socket[1], reply);
    close(socket[0]);
}
