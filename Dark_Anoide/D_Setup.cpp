#include "D_Game.h"

void												setupMap							( SGame* gameObject ) {
	for(int y = 0; y < AXIS_Y; y++) {
		for(int x = 0; x < AXIS_X; x++) {
			gameObject->Map.mapTiles[y][x]					=								TILE_VOID;
			gameObject->Map.mapBalls[y][x]					=								INVALID_BALL;
		}
	}
	for(int y = 1; y < AXIS_Y; y++) {
		gameObject->Map.mapTiles[y][0]						=								TILE_VERTICAL;
		gameObject->Map.mapTiles[y][AXIS_X-1]				=								TILE_VERTICAL;
	}
	for(int x = 1; x < AXIS_X-1; x++)
		gameObject->Map.mapTiles[0][x]						=								TILE_HORIZONTAL;

	gameObject->Map.mapTiles[0][0]						=								TILE_UP_LEFT;
	gameObject->Map.mapTiles[0][AXIS_X-1]				=								TILE_UP_RIGHT;
}

void												setupMotherShip						( SGame* gameObject ) {
	gameObject->MotherShip.speed							=							7.0f;
	gameObject->MotherShip.positionDeltas					=							{0, 0};
	gameObject->MotherShip.position.y						=							AXIS_Y - 2;
	gameObject->MotherShip.position.x						=							22;
	gameObject->MotherShip.image							=							220;
}

void												setupBall							( SGame* gameObject ) {
	SBall												newBall;
	newBall.direction										=							0.0f;
	newBall.image											=							111;
	newBall.position.y										=							11;
	newBall.position.x										=							22;
	newBall.positionDeltas									=							{0, 0};
	newBall.speed											=							3.0f;
	gameObject->Balls.push_back(newBall);
	gameObject->Map.mapBalls[newBall.position.y][newBall.position.x]		=			newBall.image;
}