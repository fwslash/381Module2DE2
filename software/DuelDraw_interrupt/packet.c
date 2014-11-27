#include "packet.h"

packet* init_packet() {
	packet* p = (packet*) malloc(sizeof(packet));
	p->client_id = -1;
	p->byte_count = 0;
	p->data = malloc(100*sizeof(char));
	return p;
}

packet* make_packet(char client_id, char* data) {
	packet* p = init_packet();
	p->client_id = (unsigned char) (client_id & 0xff);
	p->byte_count = (unsigned char) strlen(data);
	p->data = strcpy(p->data, data);
	return p;
}
