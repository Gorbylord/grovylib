#include "grovylib.h"


#include<windows.h>
#include<stdio.h>
#include<vector>

#define TILE_VOID		0
#define INVALID_ENEMY	-1
#define INVALID_SHOT	-1
#define TILE_WALL		219
#define TILE_WALL_TWO	178
#define TILE_WALL_THREE	177
#define TILE_WALL_FOUR	176
#define AXIS_Y			28
#define AXIS_X			25

struct SAnimatedObject {
	int		x
		,	y
		,	icono
		,	direction
		,	initialX
		,	initialY
		;
};
struct SGame {
	SAnimatedObject Player;
	std::vector<SAnimatedObject>Enemy;
	std::vector<SAnimatedObject>Shot;
	int mapTiles[AXIS_Y][AXIS_X];
	int enemyTiles[AXIS_Y][AXIS_X];
	int shotTiles[AXIS_Y][AXIS_X];
	int CounterMove;
	bool validShot;
	int GameLvl;
	int Lives;
	int Score;
};

void resetLvl( SGame* gameObject ){
	std::vector<SAnimatedObject>::iterator iEnemy = gameObject->Enemy.begin();
	int index = 0;
	while(iEnemy != gameObject->Enemy.end()) {
		SAnimatedObject* currentEnemy = &gameObject->Enemy[index];
		currentEnemy->x = currentEnemy->initialX;
		currentEnemy->y = currentEnemy->initialY;
		iEnemy++;
		index++;
	}
	gameObject->Player.x = gameObject->Player.initialX;
	gameObject->CounterMove = 1;
}
void updateEnemies(SGame* gameObject) {
	for( int y=0; y<AXIS_Y; y++)
		memset( gameObject->enemyTiles[y], INVALID_ENEMY, sizeof(int)*AXIS_X );
	
	std::vector<SAnimatedObject>::iterator iEnemy = gameObject->Enemy.begin();
	int index = 0;
	while( iEnemy != gameObject->Enemy.end() ) {
		SAnimatedObject* currentEnemy = &gameObject->Enemy[index];
	
		if( gameObject->CounterMove < 4 ) 
			currentEnemy->x++;
		else if( gameObject->CounterMove == 4 ) 
			currentEnemy->y++;
		else if( gameObject->CounterMove > 4 && gameObject->CounterMove < 9 ) 
			currentEnemy->x--;
		else  
			currentEnemy->y++;

		if( gameObject->mapTiles[currentEnemy->y][currentEnemy->x]  == TILE_WALL		|| gameObject->mapTiles[currentEnemy->y][currentEnemy->x]  == TILE_WALL_TWO ||
			gameObject->mapTiles[currentEnemy->y][currentEnemy->x]  == TILE_WALL_THREE	|| gameObject->mapTiles[currentEnemy->y][currentEnemy->x]  == TILE_WALL_FOUR )
			gameObject->mapTiles[currentEnemy->y][currentEnemy->x]  = TILE_VOID;
			
		if( currentEnemy->x == gameObject->Player.x && currentEnemy->y == gameObject->Player.y ) {
			resetLvl( gameObject );
			break;
		}
		gameObject->enemyTiles[currentEnemy->y][currentEnemy->x] = currentEnemy->icono;
		iEnemy++;
		index++;
		gameObject->validShot = true;
	}
	gameObject->CounterMove++;
	if( gameObject->CounterMove == 10 )
		gameObject->CounterMove = 0;
}
void setupEnemies( SGame* gameObject ) {
	SAnimatedObject newEnemy;
	for( int y=0; y<5; y++) {
		for( int x=2; x<24; x+=2 ) {
			newEnemy.icono		= 2;
			newEnemy.initialX	= x;
			newEnemy.initialY	= y;
			newEnemy.x			= newEnemy.initialX;
			newEnemy.y			= newEnemy.initialY;
			gameObject->enemyTiles[y][x] = newEnemy.icono;
			gameObject->Enemy.push_back(newEnemy);
		}
	}
}
void setupPlayer( SGame* gameObject) {
	gameObject->Player.x		= gameObject->Player.initialX = 12;;
	gameObject->Player.y		= gameObject->Player.initialY =	AXIS_Y-1;
	gameObject->Player.icono	= 205;
}
void updatePlayer( SGame* gameObject) {
	SAnimatedObject & player = gameObject->Player;
	if( GetAsyncKeyState(VK_RIGHT) && player.x+1 < AXIS_X )
		player.x++;
	if( GetAsyncKeyState(VK_LEFT) && player.x-1 >= 0 )
		player.x--;
}
void setupMap ( SGame* gameObject) {
	for( int y=0; y<AXIS_Y; y++) 
		for( int x=0; x<AXIS_X; x++) {
			gameObject->mapTiles[y][x]		= TILE_VOID;
			gameObject->enemyTiles[y][x]	= INVALID_ENEMY;
			gameObject->shotTiles[y][x]		= INVALID_SHOT;
		}
	gameObject->mapTiles[AXIS_Y-3][2] = TILE_WALL;		gameObject->mapTiles[AXIS_Y-3][8] = TILE_WALL;	
	gameObject->mapTiles[AXIS_Y-4][2] = TILE_WALL;		gameObject->mapTiles[AXIS_Y-4][8] = TILE_WALL;
	gameObject->mapTiles[AXIS_Y-4][3] = TILE_WALL;		gameObject->mapTiles[AXIS_Y-4][9] = TILE_WALL;
	gameObject->mapTiles[AXIS_Y-4][4] = TILE_WALL;		gameObject->mapTiles[AXIS_Y-4][10] = TILE_WALL;
	gameObject->mapTiles[AXIS_Y-3][4] = TILE_WALL;		gameObject->mapTiles[AXIS_Y-3][10] = TILE_WALL;

	gameObject->mapTiles[AXIS_Y-3][14] = TILE_WALL;		gameObject->mapTiles[AXIS_Y-3][20] = TILE_WALL;
	gameObject->mapTiles[AXIS_Y-4][14] = TILE_WALL;		gameObject->mapTiles[AXIS_Y-4][20] = TILE_WALL;
	gameObject->mapTiles[AXIS_Y-4][15] = TILE_WALL;		gameObject->mapTiles[AXIS_Y-4][21] = TILE_WALL;
	gameObject->mapTiles[AXIS_Y-4][16] = TILE_WALL;		gameObject->mapTiles[AXIS_Y-4][22] = TILE_WALL;
	gameObject->mapTiles[AXIS_Y-3][16] = TILE_WALL;		gameObject->mapTiles[AXIS_Y-3][22] = TILE_WALL;
}
void draw( SGame* gameObject ) {
	printf("SCORE %i       LEVEL %i        LIVES %i\n", gameObject->Score, gameObject->GameLvl, gameObject->Lives);
	char imageMap[4096]={};
	int cursor = 0;
	for( int y=0; y<AXIS_Y; y++) {
		for(int x=0; x<AXIS_X; x++) {
			if(y == gameObject->Player.y && x == gameObject->Player.x) 
				imageMap[cursor++] = (char)gameObject->Player.icono;
			else if( gameObject->enemyTiles[y][x] != INVALID_ENEMY )
				imageMap[cursor++] = (char)gameObject->enemyTiles[y][x];
			else if( y == gameObject->Player.y-1 && x == gameObject->Player.x)
				imageMap[cursor++] = 30;
			else if( y == gameObject->Player.y && x == gameObject->Player.x-1)
				imageMap[cursor++] = -44;
			else if( y == gameObject->Player.y && x == gameObject->Player.x+1)
				imageMap[cursor++] = -66;
			else if( gameObject->shotTiles[y][x] != INVALID_SHOT )
				imageMap[cursor++] = (char)gameObject->shotTiles[y][x];
			else
				imageMap[cursor++] = (char)(gameObject->mapTiles[y][x] ? gameObject->mapTiles[y][x]:' ');
		}
		imageMap[cursor++] = '\n';
	}
	imageMap[cursor] = 0;
	printf("%s", imageMap);
}

int main() {
	SGame gameInstance;
	gameInstance.Score			= 0;
	gameInstance.Lives			= 5;
	gameInstance.GameLvl		= 1;
	gameInstance.CounterMove	= 2;
	gameInstance.validShot		= true;
	setupMap		( &gameInstance );
	setupPlayer		( &gameInstance );
	setupEnemies	( &gameInstance );
	while( true ) {
		draw			( &gameInstance );
		updatePlayer	( &gameInstance );
		updateEnemies	( &gameInstance );
		if( GetAsyncKeyState(VK_ESCAPE))
			break;
		Sleep(100);
	}
	return 0;
}

