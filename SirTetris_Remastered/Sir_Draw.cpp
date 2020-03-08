#include "Sir_Game.h"

#include <stdio.h>

void															draw																	(SGame* gameObject) {
	if(gameObject->ScreenMode == SCREEN_ONE_PLAYER)
		printf("                                         SCORE:%i\n", gameObject->PlayerOne.score);
	else if(gameObject->ScreenMode == SCREEN_TWO_PLAYERS)
		printf("                   SCORE:%i                                      SCORE:%i\n", gameObject->PlayerOne.score, gameObject->PlayerTwo.score);

	char																			imageMap[4096]={};
	int																				cursor = 0;
	for(int y=0; y < SCREEN_SIZE_Y; y++) {
		for(int x=0; x < SCREEN_SIZE_X; x++) {
			imageMap[cursor++] = gameObject->Map.screen[y][x] ? gameObject->Map.screen[y][x]:' ';
		}
		imageMap[cursor++] = '\n';
	}
	imageMap[cursor++] = '\n';
	imageMap[cursor] = 0;
	printf("%s", imageMap);
}