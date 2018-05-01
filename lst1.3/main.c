#include "main.h"

int create_socket_pair(int *socket_pair)
{
    int errno;

    errno = socketpair(AF_LOCAL, SOCK_STREAM, 0, socket_pair);
    if (errno != 0) {
        printf("Cannot create socket\n");
    }
    return errno;
}

int hello_write(int socket)
{
    char *message = "Hello?";
    return write(socket, message, strlen(message));
}

void read_message(int socket)
{
    size_t len;
    char buf[80] = {0};
    len = read(socket, buf, sizeof(buf));
    buf[len] = '\0';
    printf("Receive message: \"%s\"\n", buf);
}

void copy_message(int socket, char *buf)
{
    size_t len;
    len = read(socket, buf, sizeof(buf));
    buf[len] = '\0';
}

int write_message(int socket, char *message)
{
    return write(socket, message, strlen(message));
}

int main(int argc, char *argv[])
{
    int socket[2] = {0};
    int errno;

    errno = create_socket_pair(socket);

    if (errno != 0) {
        return errno;
    } else {
        printf("s[0]=%d, s[1]=%d\n", socket[0], socket[1]);
    }

    {
        /* Testing Hello */
        write_message(socket[1], "Hello?");
        read_message(socket[0]);
        write_message(socket[0], "Someone is here!");
        read_message(socket[1]);
    }

    {
        /* Do fork */
        pid_t chpid;
        chpid = fork();
        if (chpid == (pid_t) -1) {
            printf("Fork failed...\n");
            return -1;
        }
        if (chpid == 0) {
            /* chile process */
            do_client(socket);
        } else {
            /* parent process */
            printf("Child PID %d\n", chpid);
            fflush(stdout);
            do_server(socket);
            waitpid(chpid, &errno, 0);
        }
    }

    close(socket[0]);
    close(socket[1]);
    return 0;
}
