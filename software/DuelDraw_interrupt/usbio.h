/*
 * usbio.h
 *
 * Contains all declaration for USB IO
 *
 *  Created on: 2014. 11. 11.
 *      Author: Harry
 */

#ifndef USBIO_H_
#define USBIO_H_

#include "usb/usb.h"
#include "assert.h"
#include "string.h"
#include "stdlib.h"
#include "packet.h"

/**
 * Send data through USB
 * @param byte_to_send number of byte to send
 * @param data base address of data to be sent
 *
 * @returns 0 if successful, -1 if length more than 100
 */
int usb_send(packet* p);

/**
 * Wait and receive data through USB
 * @param byte_to_recv - number of byte expected to receive
 * @param data base address of data to be written in
 *
 * @returns number of bytes successfully received
 */
packet* usb_recv();

packet* make_packet(char client_id, char* data);

#endif /* USBIO_H_ */
