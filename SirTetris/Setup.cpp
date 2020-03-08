#include "Game.h"

void												setup												(SGame* gameObject) {
	for(int y=0; y < AXIS_Y; y++) {
		for(int x=0; x < AXIS_X; x++) {
			gameObject->map.mapTiles[y][x]						=								TILE_VOID;
			gameObject->map.mapPiezes[y][x]						=								INVALID_PIEZE;
		}
	}
	for(int y=1; y < AXIS_Y-1; y++) {
		gameObject->map.mapTiles[y][0]								=								TILE_VERTICAL;
		gameObject->map.mapTiles[y][AXIS_X-1]						=								TILE_VERTICAL;
	}
	for(int x=1; x < AXIS_X-1; x++)
		gameObject->map.mapTiles[AXIS_Y-1][x]						=								TILE_HORIZONTAL;

	gameObject->map.mapTiles[AXIS_Y-1][0]							=								TILE_DOWN_LEFT;
	gameObject->map.mapTiles[AXIS_Y-1][AXIS_X-1]					=								TILE_DOWN_RIGHT;
	randomPieze(gameObject);
	getNewPieze(gameObject);
	gameObject->pieze.Speed									=								0.5f;
	gameObject->gameLevel									=								1;
	gameObject->Lines										=								0;
	gameObject->levelLines									=								0;
	gameObject->Score										=								0;
	gameObject->comboCounter								=								0;
}
