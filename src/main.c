#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <malloc.h>
#include <string.h>

// Socket address builder, using netinet's sockaddr_in struct.
//Returns a pointer to the socket, which is created on the heap.
struct sockaddr_in* build_IPv4_socket(char *ip,int port)
{
  struct sockaddr_in *addr_ipv4 = malloc(sizeof (struct sockaddr_in));
  addr_ipv4->sin_family = AF_INET;
  addr_ipv4->sin_port = htons(port);
  inet_pton(AF_INET,ip,&addr_ipv4->sin_addr.s_addr);
  return addr_ipv4;
}


int main()
{
  int socket_fd = socket(AF_INET,SOCK_STREAM,0);


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
