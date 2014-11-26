/*
 * usbio.c
 *
 * Contains all source code for USB transmission modules
 *
 *  Created on: 2014. 11. 11.
 *      Author: Harry
 */
#include "usbio.h"

packet* make_packet(char client_id, char* data) {
	packet* p = (packet*) malloc(sizeof(packet));
	p->client_id = (unsigned char) (client_id & 0xff);
	p->byte_count = (unsigned char) strlen(data);
	strcpy(p->data, data);
	return p;
}

int usb_send(packet* p) {
	unsigned char length = p->byte_count;
	if (length > 100) {
		return -1;
	}
	usb_device_send(&(p->client_id), 1);
	char* data = calloc(sizeof(unsigned char), length + 1);
	data[0] = length;
	strcpy(data + 1, p->data);
	usb_device_send((unsigned char *) data, (unsigned int) strlen(data));

	while(!usb_send_queue_is_empty());

//	printf("Sent \"%s\" to device ID %d.\n", p->data, p->client_id);

	return 0;
}

packet* usb_recv() {
	if (usb_recv_queue_is_empty())
		return NULL;
	packet* recv_packet = (packet*) malloc(sizeof(packet));
//	recv_packet->client_id = 0;
//	recv_packet->byte_count = 0;
//	strcpy(recv_packet->data, "");
	int total_recvd = 0;
	int byte_to_recv = 1;
	int bytes_recvd = 0;

	/**
	 * Get client id.
	 */
	while (total_recvd < 1) {
		byte_to_recv = usb_device_recv(
				(unsigned char*) &(recv_packet->client_id), 1);
		if (byte_to_recv > 0) {
			total_recvd += byte_to_recv;
		}
	}

	total_recvd = 0;

	/*
	 * Get byte count.
	 */
	while (total_recvd < 1) {
		byte_to_recv = usb_device_recv(
				(unsigned char*) &(recv_packet->byte_count), 1);
		if (byte_to_recv > 0) {
			total_recvd += byte_to_recv;
		}
	}

	/**
	 * Receive data via USB
	 */
	byte_to_recv = (int) recv_packet->byte_count;
	total_recvd = 0;

	while (total_recvd < byte_to_recv) {
		bytes_recvd = usb_device_recv(
				(unsigned char*) (recv_packet->data + total_recvd), 1);
		if (bytes_recvd > 0)
			total_recvd += bytes_recvd;
	}

	return recv_packet;
}
