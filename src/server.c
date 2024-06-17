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

  struct sockaddr_in clientAddress;
  unsigned int clientAddrSize = sizeof (struct sockaddr_in);

  int clientSocketFD = accept(serverSocketFD,(struct sockaddr *)&clientAddress,&clientAddrSize);

  char buffer_2Kb[2048];
  recv(clientSocketFD,buffer_2Kb,2048,0);

  printf("SERVER RESPONSE :\n%s\n",buffer_2Kb);

  return 0;
}

