#include "socketutils.h"
#include "serverutils.h"


void start_accepting_connections(int serverSocketFD)
{
  while(1)
  {
    struct AcceptedSocket* clientSocket = acceptIncomingConnection(serverSocketFD);
    
    thread_receive_print_incoming_data(clientSocket);
  }
}


void thread_receive_print_incoming_data(struct AcceptedSocket *pSocket)
{
  pthread_t id;
  pthread_create(&id,NULL,receive_print_incomming_data,&pSocket->acceptedSocketFD);
}


void *receive_print_incomming_data(void *arg)
{
  struct AcceptedSocket *pSocket = (struct AcceptedSocket *)arg;
  int socketFD = pSocket->acceptedSocketFD;
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
  close(socketFD);
  free(pSocket);
  return NULL;
}

