#include "Sir_Game.h"


void																setupThings												(SGame* gameObject) {
	gameObject->ScreenMode						=						SCREEN_TITLE;
}

void																setupMapOne												(SGame* gameObject) {
	for(int y=0; y < MAP_SIZE_Y; y++) {
		for(int x=0; x < MAP_SIZE_X; x++) {
			gameObject->Map.mapOne[y][x] = TILE_VOID;
		}
	}
	for(int y=0; y < MAP_SIZE_Y-1; y++) {
		gameObject->Map.mapOne[y][5]								=								TILE_VERTICAL;
		gameObject->Map.mapOne[y][MAP_SIZE_X-1]						=								TILE_VERTICAL;
	}
	for(int x=6; x < MAP_SIZE_X-1; x++)
		gameObject->Map.mapOne[MAP_SIZE_Y-1][x]						=								TILE_HORIZONTAL;

	gameObject->Map.mapOne[MAP_SIZE_Y-1][5]							=								TILE_DOWN_LEFT;
	gameObject->Map.mapOne[MAP_SIZE_Y-1][MAP_SIZE_X-1]				=								TILE_DOWN_RIGHT;

	for(int x=0; x < 4; x++)
		gameObject->Map.mapOne[0][x]						=								textNext[x];
}

void																setupMapTwo												(SGame* gameObject) {
	for(int y=0; y < MAP_SIZE_Y; y++) {
		for(int x=0; x < MAP_SIZE_X; x++) {
			gameObject->Map.mapTwo[y][x] = TILE_VOID;
		}
	}
	for(int y=0; y < MAP_SIZE_Y-1; y++) {
		gameObject->Map.mapTwo[y][5]								=								TILE_VERTICAL;
		gameObject->Map.mapTwo[y][MAP_SIZE_X-1]						=								TILE_VERTICAL;
	}
	for(int x=6; x < MAP_SIZE_X-1; x++)
		gameObject->Map.mapTwo[MAP_SIZE_Y-1][x]						=								TILE_HORIZONTAL;

	gameObject->Map.mapTwo[MAP_SIZE_Y-1][5]							=								TILE_DOWN_LEFT;
	gameObject->Map.mapTwo[MAP_SIZE_Y-1][MAP_SIZE_X-1]				=								TILE_DOWN_RIGHT;

	for(int x=0; x < 4; x++)
		gameObject->Map.mapTwo[0][x]						=								textNext[x];
}

void																setupPlayerOne											(SGame* gameObject) {
	getRandomPieze(&gameObject->PlayerOne);
	getNewPieze(&gameObject->PlayerOne);
	gameObject->PlayerOne.speed					=				2.0f;
	gameObject->PlayerOne.score					=				0;
	gameObject->PlayerOne.power					=				0;
}

void																setupPlayerTwo											(SGame* gameObject) {
	getRandomPieze(&gameObject->PlayerTwo);
	getNewPieze(&gameObject->PlayerTwo);
	gameObject->PlayerTwo.speed					=				0.0f;
	gameObject->PlayerTwo.score					=				0;
	gameObject->PlayerTwo.power					=				0;
}