
#include "Game.h"


void																			draw									(SGame* gameObject) {
	printf("FOOD:%i   CHASE:%i   SCATTER:%i   FRIGHTENED:%i   SCORE:%i\n", gameObject->CounterFood, gameObject->CounterChase, gameObject->CounterScatter, gameObject->CounterFrightened, gameObject->Score);
	printf("BLINKY TARGET_Y:%i   TARGET_X:%i   CURRENTMODE:%i\n", gameObject->Enemies[BLINKY].TargetTile.y, gameObject->Enemies[BLINKY].TargetTile.x, gameObject->Enemies[BLINKY].CurrentMode);
	printf("PINKY TARGET_Y:%i   TARGET_X:%i   CURRENTMODE:%i\n", gameObject->Enemies[PINKY].TargetTile.y, gameObject->Enemies[PINKY].TargetTile.x, gameObject->Enemies[PINKY].CurrentMode);
	printf("INKY TARGET_Y:%i   TARGET_X:%i   CURRENTMODE:%i\n", gameObject->Enemies[INKY].TargetTile.y, gameObject->Enemies[INKY].TargetTile.x, gameObject->Enemies[INKY].CurrentMode);
	printf("CLYDE TARGET_Y:%i   TARGET_X:%i   CURRENTMODE:%i\n\n", gameObject->Enemies[CLYDE].TargetTile.y, gameObject->Enemies[CLYDE].TargetTile.x, gameObject->Enemies[CLYDE].CurrentMode);

	char																			imageMap[4096]={};		
	int																				cursor = 0;
	for(int32_t y=0; y < (int32_t)gameObject->Map.Size.y - 1; y++) {
		for(int32_t x=0; x < (int32_t)gameObject->Map.Size.x; x++) {
			if( gameObject->Player.Position.y == y && gameObject->Player.Position.x == x)
				imageMap[cursor++] = gameObject->Player.Image;
			else if( gameObject->Map.TilesEnemy[y][x] != INVALID_ENEMY)
				imageMap[cursor++] = gameObject->Map.TilesEnemy[y][x];
			else 
				imageMap[cursor++] = gameObject->Map.TilesMap[y][x] ? gameObject->Map.TilesMap[y][x]:' ';
		}
		imageMap[cursor++] = '\n';
	}
	imageMap[cursor++] = '\n';
	imageMap[cursor] = 0;
	printf("%s", imageMap);
}