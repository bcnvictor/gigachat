#include <stdio.h>
#include <unistd.h>
#include "socketutils.h"

int main()
{
  int socketFD = createIPv4socket();


  struct sockaddr_in* addr = build_IPv4_socket("127.0.0.1", 2000);


  int res = connect(socketFD,(struct sockaddr *)addr,sizeof(*addr));
   
  if (res == 0)
    printf("Connection successful\n");



  char *msg = NULL;
  size_t msgsize = 0;
  printf("Connected ! Type 'exit' to quit.\nType a message to send...\n");

  while (1) // true
  {
    ssize_t char_count = getline(&msg,&msgsize,stdin); 
    if (char_count>0)
    {
      if (strcmp(msg,"exit\n")==0)
        break;
      ssize_t sent_amount = send(socketFD, msg, char_count,0);
    }
  }

  close(socketFD);
  return 0;
}
