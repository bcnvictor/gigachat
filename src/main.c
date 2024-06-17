#include "socketutils.h"
#include <stdio.h>



int main()
{
  int socket_fd = createIPv4socket();


  struct sockaddr_in* addr = build_IPv4_socket("172.253.63.100",80);


  int res = connect(socket_fd,(struct sockaddr *)addr,sizeof(*addr));
   
  if (res == 0)
    printf("Connection successful\n");


  char* msg;
  msg = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
  send(socket_fd, msg, strlen(msg),0);

  char buffer_2ko[2048];

  recv(socket_fd,buffer_2ko,2048,0);

  printf("SERVER RESPONSE :\n%s\n",buffer_2ko);
  return 0;
}
