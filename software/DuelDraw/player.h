/*
 * player.h
 *
 *  Created on: 2014. 11. 11.
 *      Author: Harry
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#ifndef NULL
#define NULL (void*)0
#endif

typedef struct player_t {
	unsigned char client_id;
	char* android_id;
//	char name[25];
} player_t;

void makeNewPlayer(player_t list[], int* numberOfPlayers, int clientID,
		char* androidID);

int isNewPlayer(player_t list[], int numberOfPlayers, char* androidID);

int findChallengeIndex(player_t list[], int numberOfPlayers, char* androidID);
