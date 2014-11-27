/*
 * recv_packet.h
 *
 *  Created on: 2014. 11. 11.
 *      Author: Harry
 */

#include "config.h"

#ifndef RECV_PACKET_H_
#define RECV_PACKET_H_

typedef struct packet {
	unsigned char client_id;
	unsigned char byte_count;
	char* data;
} packet;

packet* init_packet();
packet* make_packet(char client_id, char* data);

#endif /* RECV_PACKET_H_ */
