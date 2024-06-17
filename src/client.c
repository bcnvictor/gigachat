#include "socketutils.h"
#include <stdio.h>



int main()
{
  int socketFD = createIPv4socket();


  struct sockaddr_in* addr = build_IPv4_socket("127.0.0.1", 2000);


  int res = connect(socketFD,(struct sockaddr *)addr,sizeof(*addr));
   
  if (res == 0)
    printf("Connection successful\n");


  char* msg;
  msg = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
  
  send(socketFD, msg, strlen(msg),0);

  char buffer_2ko[2048];

  recv(socketFD,buffer_2ko,2048,0);

  printf("SERVER RESPONSE :\n%s\n",buffer_2ko);
  return 0;
}
