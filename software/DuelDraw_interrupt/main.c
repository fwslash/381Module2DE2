#include "usb/usb.h"
#include "altera_up_avalon_usb.h"
#include "system.h"
#include "sys/alt_timestamp.h"
#include "packet.h"
#include "usbio.h"
#include "stdio.h"
#include "player.h"
#include "unistd.h"
#include "sys/alt_irq.h"
#include "io.h"

#include <assert.h>

volatile int count = 0;
// runs every 25ms
void timer_isr(void * context, unsigned int irq_id) {
	// receive from middleman
//	if (!usb_recv_queue_is_empty()) {
//
//	}

	count++;
	if (count == 40){
		printf("check.\n");
		count = 0;
	}

	IOWR_32DIRECT(TIMER_0_BASE, 0, 0);
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

	printf("Initialize IRQ\n");
	alt_irq_register(TIMER_0_IRQ, NULL, timer_isr);
	alt_irq_disable(TIMER_0_IRQ);
	IOWR_16DIRECT(TIMER_0_BASE, 1, 0x07);
	alt_irq_enable(TIMER_0_IRQ);

	printf("Initializing loop\n");

	while (1) {
		// send to middle man
		if (!usb_send_queue_is_empty()) {

		}
	}

	return 0;
}
