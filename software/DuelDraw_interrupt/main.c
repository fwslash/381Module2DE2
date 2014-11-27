#include "config.h"

volatile int count = 0;
volatile int value = 0;

volatile recvQueue* rq;

// runs every 25ms
void timer_isr(void * context, unsigned int irq_id) {
	count = (count + 1) % 2;

	if (!(usb_recv_queue_is_empty())) {
		printf("Received packet\n");
		packet* p = usb_recv();
		assert(p != NULL);
		rq = addToQueue(rq, p);
		printf("\nQueue size: %d\n", getQueueSize(rq));
	}

	IOWR_8DIRECT(LEDG_BASE, 0, count);

	IOWR_16DIRECT(TIMER_0_BASE, 0, 0);
}

int main() {
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

//	printf("Initializing IRQ\n");
//	alt_irq_disable(TIMER_0_IRQ);
//	alt_irq_register(TIMER_0_IRQ, NULL, timer_isr);
//	IOWR_16DIRECT(TIMER_0_BASE, 4, 0x07);
//	alt_irq_enable(TIMER_0_IRQ);

	printf("Initializing Queue\n");
	rq = initRecvQueue();

	printf("Initializing loop\n");

	while (1) {
		// send to middle man
		printf("Check for packet\n");
		packet* p = usb_recv();
		printf("post usb_recv\n");
		rq = addToQueue(rq, p);
		printf("\nQueue size: %d\n", getQueueSize(rq));
	}

	return 0;
}
