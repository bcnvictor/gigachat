#ifndef SOCKETUTIL_SOCKETUTIL_H
#define SOCKETUTIL_SOCKETUTIL_H

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

struct AcceptedSocket
{
  int acceptedSocketFD;
  struct sockaddr_in socketAddress;
  int error;
  bool acceptedSuccessfully; 
};

struct sockaddr_in* build_IPv4_socket(char *ip,int port);
int createIPv4socket();
void receive_print_incomming_data(int socketFD);
struct AcceptedSocket * acceptIncomingConnection(int socketFD);

#endif // SOCKETUTIL_SOCKETUTIL_H
