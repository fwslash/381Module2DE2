/*
 * usbio.c
 *
 * Contains all source code for USB transmission modules
 *
 *  Created on: 2014. 11. 11.
 *      Author: Harry
 */
#include "usbio.h"

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

	while (!usb_send_queue_is_empty())
		;

//	printf("Sent \"%s\" to device ID %d.\n", p->data, p->client_id);

	return 0;
}

packet* usb_recv() {
	char* message = (char*) calloc(100, sizeof(char));

	packet* recv_packet = init_packet();

	int total_recvd = 0;
	int byte_to_recv = 1;
	int bytes_recvd = 0;

	/**
	 * Get client id.
	 */
	while (total_recvd < byte_to_recv) {
		bytes_recvd = usb_device_recv((unsigned char*) message, 1);
		if (bytes_recvd > 0) {
			total_recvd += bytes_recvd;
			printf("client id: %d\n", total_recvd);
		}
	}

	strcpy(recv_packet->client_id, message);

	free(message);
	message = (char*) calloc(100, sizeof(char));

	total_recvd = 0;
	byte_to_recv = 1;
	bytes_recvd = 0;

	/*
	 * Get byte count.
	 */
	while (total_recvd < byte_to_recv) {
		bytes_recvd = usb_device_recv(
				(unsigned char*) &(message), 1);
		if (bytes_recvd > 0) {
			total_recvd += bytes_recvd;
			printf("byte count: %d\n", total_recvd);
		}
	}

	strcpy(recv_packet->byte_count, message);

	free(message);
	message = (char*) calloc(100, sizeof(char));

	if (recv_packet->byte_count == 0) {
		printf("Client %d disconnected.", recv_packet->client_id);
		return recv_packet;
	}

	/**
	 * Receive data via USB
	 */
	bytes_recvd = 0;
	byte_to_recv = (int) recv_packet->byte_count;
	total_recvd = 0;

	while (total_recvd < byte_to_recv) {
		bytes_recvd = usb_device_recv(
				(unsigned char*) (message + total_recvd), 1);
		if (bytes_recvd > 0) {
			total_recvd += bytes_recvd;
			printf("data: %d\n", total_recvd);
		}
	}

	strcpy(recv_packet->data, message);
	free(message);

	return recv_packet;
}
