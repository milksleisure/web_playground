#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <time.h>

int write_message(int socket, char *message);
void read_message(int socket);
void copy_message(int socket, char *buf);
void do_client(int *socket);
void do_server(int *socket);

#endif /* !MAIN_H */
