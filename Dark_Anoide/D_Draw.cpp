#include "D_Game.h"

void												draw								( SGame* gameObject ) {
	char																			imageMap[4096]={};		
	int																				cursor = 0;
	for(int y=0; y < AXIS_Y; y++) {
		for(int x=0; x < AXIS_X; x++) {
			if( y == gameObject->MotherShip.position.y && x == gameObject->MotherShip.position.x)
				imageMap[cursor++] = gameObject->MotherShip.image;
			else if(gameObject->Map.mapBalls[y][x] != INVALID_BALL)
				imageMap[cursor++] = gameObject->Map.mapBalls[y][x];
			else
				imageMap[cursor++] = gameObject->Map.mapTiles[y][x] ? gameObject->Map.mapTiles[y][x]:' ';
		}
		imageMap[cursor++] = '\n';
	}
	imageMap[cursor++] = '\n';
	imageMap[cursor] = 0;
	printf("%s", imageMap);
}