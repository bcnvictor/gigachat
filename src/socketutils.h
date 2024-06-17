#ifndef SOCKETUTIL_SOCKETUTIL_H
#define SOCKETUTIL_SOCKETUTIL_H

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <malloc.h>
#include <string.h>

struct sockaddr_in* build_IPv4_socket(char *ip,int port);

int createIPv4socket();

#endif // SOCKETUTIL_SOCKETUTIL_H
