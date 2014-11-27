/*
 * recvQueue.c
 *
 *  Created on: 2014. 11. 26.
 *      Author: Harry
 */

#include "recvQueue.h"
#include "config.h"

recvQueue* initRecvQueue() {
	recvQueue* q = (recvQueue*) malloc(sizeof(recvQueue));
	q->data = 0;
	q->next = 0;
	return q;
}

recvQueue* getEndNode(recvQueue* head) {
	recvQueue* copy = head;
	while (copy->next)
		copy = copy->next;
	return copy;
}

recvQueue* addToQueue(recvQueue* head, packet* p) {
	if (getQueueSize(head) == 0) {
		head->data = p;
		return head;
	}
	recvQueue* copy = head;
	while (copy->next) {
		copy = copy->next;
	}
	copy->next = initRecvQueue();
	copy = copy->next;
	copy->data = p;

	return head;
}

packet* removeFromQueue(recvQueue* head) {
	packet* out = head->data;
	head = head->next;
	return out;
}

/**
 * Returns 1 if queue is empty
 */
int isEmptyQueue(recvQueue* head) {
	if (head->data == 0)
		return 1;
	return 0;
}

/**
 * Returns size of the queue
 */
int getQueueSize(recvQueue* head) {
	int count = 0;
	if (head->data == 0)
		return 0;
	recvQueue* copy = head;
	while (copy->data != 0) {
		count++;
		copy = copy->next;
	}
	return count;
}
