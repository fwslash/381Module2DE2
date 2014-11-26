/*
 * recv_packet.h
 *
 *  Created on: 2014. 11. 11.
 *      Author: Harry
 */

#ifndef RECV_PACKET_H_
#define RECV_PACKET_H_

typedef struct packet {
	unsigned char client_id;
	unsigned char byte_count;
	char* data;
} packet;

#endif /* RECV_PACKET_H_ */
