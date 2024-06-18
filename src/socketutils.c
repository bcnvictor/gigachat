#include "socketutils.h"


int createIPv4socket() 
{
  return socket(AF_INET,SOCK_STREAM,0);
}


struct sockaddr_in* build_IPv4_socket(char *ip,int port)
{
  struct sockaddr_in *addr_ipv4 = malloc(sizeof (struct sockaddr_in));
  addr_ipv4->sin_family = AF_INET;
  addr_ipv4->sin_port = htons(port);

  if (strlen(ip) == 0)
  {
    addr_ipv4 -> sin_addr.s_addr = INADDR_ANY;
  }
  else
  {
    inet_pton(AF_INET,ip,&addr_ipv4->sin_addr.s_addr);
  }
  return addr_ipv4;
}


struct AcceptedSocket *acceptIncomingConnection(int socketFD)
{
  struct sockaddr_in clientAddress;
  unsigned int clientAddrSize = sizeof (struct sockaddr_in);
  int clientSocketFD = accept(socketFD,(struct sockaddr *)&clientAddress,&clientAddrSize);

  struct AcceptedSocket* acceptedSocket = malloc(sizeof(struct AcceptedSocket));
  acceptedSocket->socketAddress = clientAddress;
  acceptedSocket->acceptedSocketFD = clientSocketFD;
  acceptedSocket->acceptedSuccessfully = clientSocketFD>0;
  if (!acceptedSocket->acceptedSuccessfully)
  {
    acceptedSocket->error = clientSocketFD;
  }

  return acceptedSocket;
}

void receive_print_incomming_data(int socketFD)
{
  char buffer_1Kb[1024];
  
  while(1) 
  {
    ssize_t amount_received = recv(socketFD,buffer_1Kb,1024,0);
    if (amount_received > 0)
    {
      buffer_1Kb[amount_received] = 0;
      printf("Response was :\n%s\n ",buffer_1Kb);
    }

    if (amount_received <= 0)
      break;
  }

}
