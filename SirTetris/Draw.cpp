#include "Game.h"

#include <stdio.h>

void															draw																	(SGame* gameObject) {
	printf("\n NEXT\n                   LEVEL:%i\n", gameObject->gameLevel);
	unsigned char																			imageText[4096]={};

	if(gameObject->nextPieze == BARRA) {
		//int u = 0;
		//for(int i = 0; i < 4; i++) {
		//	for(int x = 0; x < 4; x++) {
		//		imageText[u++] = typeBarra[i][x];
		//	}
		//	imageText[u++] = '\n';
		//}
		//imageText[u++] = '\n';
		//imageText[u] = 0;
		imageText[0] = ' ';		imageText[1]	= 178;		imageText[2]	= 178;		imageText[3] = 178;		imageText[4]	= 178;		imageText[5]	= '\n';		imageText[6] = '\n';
	}
	else if (gameObject->nextPieze == L_IZQUIERDA) {
		imageText[0] = ' ';		imageText[1]	= 176;		imageText[2]	= 176;		imageText[3]	= 176;		imageText[4] = '\n';
		imageText[5] = ' ';		imageText[6]	= 176;		imageText[7]	= '\n';
	}
	else if (gameObject->nextPieze == L_DERECHA) {
		imageText[0] = ' ';		imageText[1]	= 177;		imageText[2]	= 177;		imageText[3]	= 177;		imageText[4] = '\n';
		imageText[5] = ' ';		imageText[6]	= ' ';		imageText[7]	= ' ';		imageText[8]	= 177;		imageText[9] = '\n';
	}
	else if (gameObject->nextPieze == ESCALERITA_DERECHA) {
		imageText[0] = ' ';		imageText[1]	= ' ';		imageText[2]	= 177;		imageText[3]	= 177;		imageText[4] = '\n';
		imageText[5] = ' ';		imageText[6]	= 177;		imageText[7]	= 177;		imageText[8]	= '\n';
	}
	else if (gameObject->nextPieze == ESCALERITA_IZQUIERDA) {
		imageText[0] = ' ';		imageText[1]	= 176;		imageText[2]	= 176;		imageText[3]	= '\n';
		imageText[4] = ' ';		imageText[5]	= ' ';		imageText[6]	= 176;		imageText[7]	= 176;		imageText[8] = '\n';
	}
	else if (gameObject->nextPieze == PODIO) {
		imageText[0] = ' ';		imageText[1]	= 178;		imageText[2]	= 178;		imageText[3]	= 178;		imageText[4] = '\n';
		imageText[5] = ' ';		imageText[6]	= ' ';		imageText[7]	= 178;		imageText[8]	= '\n';
	}
	else {
		imageText[0] = ' ';		imageText[1]	= 178;		imageText[2]	= 178;		imageText[3]	= '\n';
		imageText[4] = ' ';		imageText[5]	= 178;		imageText[6]	= 178;		imageText[7]	= '\n';
	}
	printf("%s", imageText);
	printf("                   SCORE:%i\n LINES:%i\n",gameObject->Score, gameObject->Lines);

	char																			imageMap[4096]={};
	int																				cursor = 0;
	for(int y=0; y < AXIS_Y; y++) {
		for(int x=0; x < AXIS_X; x++) {
			if(gameObject->map.mapPiezes[y][x] != INVALID_PIEZE)
				imageMap[cursor++] = gameObject->map.mapPiezes[y][x];
			else if(x == gameObject->pieze.Axis.x && y == gameObject->pieze.Axis.y)
				imageMap[cursor++] = gameObject->pieze.Image;
			else
				imageMap[cursor++] = gameObject->map.mapTiles[y][x] ? gameObject->map.mapTiles[y][x]:' ';
		}
		imageMap[cursor++] = '\n';
	}
	imageMap[cursor++] = '\n';
	imageMap[cursor] = 0;
	printf("%s", imageMap);
}