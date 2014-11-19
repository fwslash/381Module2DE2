/*
 * player.c
 *
 *  Created on: 2014. 11. 11.
 *      Author: Harry
 */

#include "player.h"

void makeNewPlayer(player_t list[], int* numberOfPlayers, int clientID,
		char* androidID) {
	int i = isNewPlayer(list, *numberOfPlayers, androidID);
	if (i == -1) {
		player_t player = { clientID, 0 };
		player.android_id = (char*) malloc(sizeof(char) * 17);
		strcpy(player.android_id, androidID);
		list[*numberOfPlayers] = player;
		(*numberOfPlayers)++;
	} else {
		list[i].client_id = clientID;
	}
}

int isNewPlayer(player_t list[], int numberOfPlayers, char* androidID) {
	int i;
	for (i = 0; i < numberOfPlayers; i++) {
		if (strcmp(list[i].android_id, androidID) == 0)
			return i;
	}
	return -1;
}

int findChallengeIndex(player_t list[], int numberOfPlayers, char* androidID) {
	int i;
	for (i = 0; i < numberOfPlayers; i++) {
		if (strcpy(list[i].android_id, androidID) == 0)
			return i;
	}
	return -1;
}
