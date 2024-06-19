#ifndef SERVERUTIL_SERVERUTIL_H
#define SERVERUTIL_SERVERUTIL_H

#include "socketutils.h"

void *receive_print_incomming_data(void *arg);
void start_accepting_connections(int serverSocketFD);
void thread_receive_print_incoming_data(struct AcceptedSocket *pSocket);



#endif // SERVERUTIL_SERVERUTIL_H

