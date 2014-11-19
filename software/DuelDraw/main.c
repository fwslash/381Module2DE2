#include "usb/usb.h"
#include "altera_up_avalon_usb.h"
#include "system.h"
#include "sys/alt_timestamp.h"
#include "packet.h"
#include "usbio.h"
#include "stdio.h"
#include "player.h"
#include "unistd.h"

#include <assert.h>

char asciify(char c) {
	if (0x0 <= c && 0xa > c)
		return c | 0x30;
	return c;
}

int main() {
	int i, index;
	int targetID;
	int numOfPlayers = 0;
	unsigned char protocol;
	char* androidID = (char*) malloc(sizeof(char) * 17);
	player_t player_list[10];
	packet* p = (packet*) malloc(sizeof(packet));
	p->data = (char*) malloc(sizeof(char) * 100);
	i = 0;

	printf("USB Initialization\n");
	alt_up_usb_dev * usb_dev;
	usb_dev = alt_up_usb_open_dev(USB_0_NAME);
	usb_device_init(usb_dev, USB_0_IRQ);

	printf("Polling USB device.  Run middleman now!\n");
	alt_timestamp_start();
	int clocks = 0;
	while (clocks < 50000000 * 5) {
		clocks = alt_timestamp();
		usb_device_poll();
	}
	printf("Done polling USB\n");

	printf("Initializing loop\n");

	while (1) {

	}

	return 0;
}
