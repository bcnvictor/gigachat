#include <unistd.h>
#include <stdbool.h>
#include "socketutils.h"





int main()
{

  int serverSocketFD = createIPv4socket();

  struct sockaddr_in *serverAdress = build_IPv4_socket("", 2000);

  int bind_result = bind(serverSocketFD, (struct sockaddr *) serverAdress, sizeof(*serverAdress));
  if (bind_result == 0)
    printf("Socket succesfully bound to port 2000\n");

  int listen_result = listen(serverSocketFD, 10);
  if (listen_result == 0)
    printf("Listening to port 2000...\n");


  struct AcceptedSocket* clientSocket = acceptIncomingConnection(serverSocketFD);

  receive_print_incomming_data(clientSocket->acceptedSocketFD);

  close(clientSocket->acceptedSocketFD);
  shutdown(serverSocketFD,SHUT_RDWR);
  return 0;
}

