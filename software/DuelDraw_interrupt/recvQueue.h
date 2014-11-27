#ifndef _RECVQUEUE_H
#define _RECVQUEUE_H

#include "config.h"

typedef struct recvQueue {
	packet*	data;
	struct recvQueue* next;
} recvQueue;

recvQueue* initRecvQueue();
recvQueue* getEndNode(recvQueue* head);
recvQueue* addToQueue(recvQueue* head, packet* p);
packet* removeFromQueue(recvQueue* head);
int isEmptyQueue(recvQueue* head);
int getQueueSize(recvQueue* head);

#endif
