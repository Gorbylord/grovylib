#include "Game.h"

#include<Windows.h>

void																	refreshPosFromDeltas										( SAnimatedObject* character )	{
	::ftwlib::SCoord2<float>												*charDeltas							= &character->PositionDeltas;
	
	int																		deltaX								= (int)charDeltas->x;

	character->Position.x													+= deltaX;
	charDeltas->x															-= deltaX;

	if(charDeltas->x < 0) {
		character->Position.x													-= 1;
		charDeltas->x															+= 1;
	}
	
	int																		deltaY								= (int)charDeltas->y;
	character->Position.y													+= deltaY;
	charDeltas->y															-= deltaY;

	if(charDeltas->y < 0) {
		character->Position.y													-= 1;
		charDeltas->y															+= 1;
	}
}

void																	updatePlayer												(SGame* gameObject, float fLastFrameTime) {
	SAnimatedObject															& player													= gameObject->Player;
	SMap																	& map														= gameObject->Map;

	::ftwlib::SCoord2<float>												* playerDeltas												= &gameObject->Player.PositionDeltas;
	float																	fSpeed														= gameObject->Player.Speed;

	if(			GetAsyncKeyState(	VK_RIGHT	)	&&		map.TilesSolid[	player.Position.y	][	player.Position.x+1	] != true	)	player.CurrentDirection	=	RIGHT;
	if(			GetAsyncKeyState(	VK_LEFT		)	&&		map.TilesSolid[	player.Position.y	][	player.Position.x-1	] != true	)	player.CurrentDirection	=	LEFT;
	if(			GetAsyncKeyState(	VK_UP		)	&&		map.TilesSolid[	player.Position.y-1	][	player.Position.x	] != true	)	player.CurrentDirection	=	UP;
	if(			GetAsyncKeyState(	VK_DOWN		)	&&		map.TilesSolid[	player.Position.y+1	][	player.Position.x	] != true	)	player.CurrentDirection	=	DOWN;

	if(			player.CurrentDirection	== UP		&&		map.TilesSolid[	player.Position.y-1	][	player.Position.x	] != true	)	playerDeltas->y			-=	fSpeed*fLastFrameTime;
	else if(	player.CurrentDirection == DOWN		&&		map.TilesSolid[	player.Position.y+1	][	player.Position.x	] != true	)	playerDeltas->y			+=	fSpeed*fLastFrameTime;
	else if(	player.CurrentDirection == RIGHT	&&		map.TilesSolid[	player.Position.y	][	player.Position.x+1	] != true	)	playerDeltas->x			+=	fSpeed*fLastFrameTime;
	else if(	player.CurrentDirection == LEFT		&&		map.TilesSolid[	player.Position.y	][	player.Position.x-1	] != true	)	playerDeltas->x			-=	fSpeed*fLastFrameTime;
	if(			player.CurrentDirection == UP		&&		player.Position.y == 0 )													player.Position.y		=	21;
	if(			player.CurrentDirection == DOWN		&&		player.Position.y == 21 )													player.Position.y		=	0;

	refreshPosFromDeltas( &gameObject->Player );

	if(	map.TilesMap[player.Position.y][player.Position.x] == TILE_FOOD	) {
		gameObject->Score														+= 10;
		gameObject->CounterFood													++;
		map.TilesMap[player.Position.y][player.Position.x]						= TILE_VOID;
	}
	else if( map.TilesMap[player.Position.y][player.Position.x] == TILE_ENERGYZER ) {
		gameObject->Score														+= 50;
		map.TilesMap[player.Position.y][player.Position.x]						= TILE_VOID;
		if(gameObject->CounterFrightened > 0)
			gameObject->CounterFrightened = 1;
		else
			gameObject->CounterFrightened++;
		for(int Ienemy=0; Ienemy<GHOST_COUNT; Ienemy++) {
			if(gameObject->Enemies[Ienemy].InHouse == false) {
				gameObject->Enemies[Ienemy].Vulnerability							= true;
				gameObject->Enemies[Ienemy].Image									= 153;
				gameObject->Enemies[Ienemy].Speed									= 3.0f;
				gameObject->Enemies[Ienemy].CurrentMode								= MODE_FRIGHTENED;
				if(gameObject->Enemies[Ienemy].CurrentDirection == UP)
					gameObject->Enemies[Ienemy].CurrentDirection = DOWN;
				else if(gameObject->Enemies[Ienemy].CurrentDirection == DOWN)
					gameObject->Enemies[Ienemy].CurrentDirection = UP;
				else if(gameObject->Enemies[Ienemy].CurrentDirection == LEFT)
					gameObject->Enemies[Ienemy].CurrentDirection = RIGHT;
				else
					gameObject->Enemies[Ienemy].CurrentDirection = LEFT;
			}
		}
	}

	if(	player.Image == 79	)
		player.Image = 67;
	else
		player.Image = 79;
}
DIRECTION																 getRandomDirection											(SAnimatedObject* currentObject){
	int																		random														= rand()%4;
	if																		(random == UP)												return	currentObject->CurrentDirection	= UP;
	else if																	(random == LEFT)											return	currentObject->CurrentDirection	= LEFT;
	else if																	(random == DOWN)											return	currentObject->CurrentDirection	= DOWN;
	else																																return	currentObject->CurrentDirection	= RIGHT;
}

void																	updateEnemies												(SGame* gameObject, float fLastFrameTime) {
	for(uint32_t y=0; y < (uint32_t)gameObject->Map.Size.y; y++)
		memset(gameObject->Map.TilesEnemy[y], INVALID_ENEMY, gameObject->Map.Size.x);
	
	if(gameObject->CounterFood == 1) {
			gameObject->Enemies[PINKY].Position.y	= 10;
			gameObject->Enemies[PINKY].Position.x	= 10;
			gameObject->Enemies[PINKY].InHouse		= false;
	}
	else if(gameObject->CounterFood == 20) {
			gameObject->Enemies[INKY].Position.y	= 10;
			gameObject->Enemies[INKY].Position.x	= 10;
			gameObject->Enemies[INKY].InHouse		= false;
	}
	else if(gameObject->CounterFood == 63) {
			gameObject->Enemies[CLYDE].Position.y	= 10;
			gameObject->Enemies[CLYDE].Position.x	= 10;
			gameObject->Enemies[CLYDE].InHouse		= false;
	}
	if(gameObject->CounterFrightened == 0) {
		if(gameObject->CounterChase == 0) {
			gameObject->CounterScatter ++;
		}
		if(gameObject->CounterScatter == 16) {
			gameObject->CounterScatter = 0;
			gameObject->Enemies[BLINKY].CurrentMode = MODE_CHASE;
			gameObject->Enemies[BLINKY].Speed	 = 4.5f;
			gameObject->Enemies[PINKY].CurrentMode = MODE_CHASE;
			gameObject->Enemies[INKY].CurrentMode = MODE_CHASE;
		}
		if(gameObject->CounterScatter == 0) {
			gameObject->CounterChase ++;
		}
		if(gameObject->CounterChase == 32) {
			gameObject->CounterChase = 0;
			gameObject->Enemies[BLINKY].CurrentMode = MODE_SCATTER;
			gameObject->Enemies[BLINKY].Speed	 = 4.0f;
			gameObject->Enemies[PINKY].CurrentMode = MODE_SCATTER;
			gameObject->Enemies[INKY].CurrentMode = MODE_SCATTER;
		}
		for( int32_t y = gameObject->Enemies[CLYDE].Position.y-4; y < gameObject->Enemies[CLYDE].Position.y+4; y++) {
			for(int32_t x = gameObject->Enemies[CLYDE].Position.x-4; x < gameObject->Enemies[CLYDE].Position.x+4; x++) {
				if(y == gameObject->Player.Position.y && x == gameObject->Player.Position.x)
					gameObject->Enemies[CLYDE].CurrentMode = MODE_SCATTER;
				else
					gameObject->Enemies[CLYDE].CurrentMode = MODE_CHASE;
			}
		}
	}

	if(gameObject->CounterFrightened > 0) 
		gameObject->CounterFrightened++;
	if(gameObject->CounterFrightened > 20) {
		for(int Ienemy=0; Ienemy<GHOST_COUNT; Ienemy++) {
			if(gameObject->Enemies[Ienemy].Vulnerability == true) {
				if(gameObject->Enemies[Ienemy].Image != 153)
					gameObject->Enemies[Ienemy].Image = 153;
				else {
					if(gameObject->Enemies[Ienemy].CurrentGhost == BLINKY)
						gameObject->Enemies[Ienemy].Image = 147;
					else if(gameObject->Enemies[Ienemy].CurrentGhost == PINKY)
						gameObject->Enemies[Ienemy].Image = 148;
					else if(gameObject->Enemies[Ienemy].CurrentGhost == INKY)
						gameObject->Enemies[Ienemy].Image = 149;
					else
						gameObject->Enemies[Ienemy].Image = 162;
				}
			}
		}
	}
	if(gameObject->CounterFrightened == 42) {
		gameObject->CounterFrightened = 0;
		gameObject->Enemies[BLINKY].Image = 147;
		gameObject->Enemies[PINKY].Image = 148;
		gameObject->Enemies[INKY].Image = 149;
		gameObject->Enemies[CLYDE].Image = 162;
		for(int Ienemy=0; Ienemy<GHOST_COUNT; Ienemy++) {
			gameObject->Enemies[Ienemy].Vulnerability							= false;
			gameObject->Enemies[Ienemy].Speed									= 4.0f;
		}
	}

	for(int enemyC = 0; enemyC < GHOST_COUNT; enemyC++) {
		SEnemy*																		currentEnemy									= &gameObject->Enemies[enemyC];
		::ftwlib::SCoord2<float>													* enemyDeltas									= &currentEnemy->PositionDeltas;
		float																		fEnemySpeed										= currentEnemy->Speed;

		if(currentEnemy->InHouse == true)
			currentEnemy->CurrentDirection = getRandomDirection(currentEnemy);
		else if(gameObject->Map.TilesDecision[currentEnemy->Position.y][currentEnemy->Position.x]	==	true) {
			if(currentEnemy->CurrentMode == MODE_FRIGHTENED)
				currentEnemy->CurrentDirection = getRandomDirection(currentEnemy);
			else if(currentEnemy->CurrentMode == MODE_SCATTER) {
				if(currentEnemy->CurrentGhost == BLINKY) {
					currentEnemy->TargetTile.y =0;
					currentEnemy->TargetTile.x =2;
				}
				else if(currentEnemy->CurrentGhost == PINKY) {
					currentEnemy->TargetTile.y =21;
					currentEnemy->TargetTile.x =2;
				}
				else if(currentEnemy->CurrentGhost == INKY) {
					currentEnemy->TargetTile.y =0;
					currentEnemy->TargetTile.x =24;
				}
				else if(currentEnemy->CurrentGhost == CLYDE) {
					currentEnemy->TargetTile.y =21;
					currentEnemy->TargetTile.x =24;
				}
			}
			else if(currentEnemy->CurrentMode == MODE_CHASE){
				if(currentEnemy->CurrentGhost == BLINKY) {
					currentEnemy->TargetTile.y = gameObject->Player.Position.y;
					currentEnemy->TargetTile.x = gameObject->Player.Position.x;
				}
				else if(currentEnemy->CurrentGhost == PINKY) {
					if(gameObject->Player.CurrentDirection == UP) {
						currentEnemy->TargetTile.y = gameObject->Player.Position.y-4;
						currentEnemy->TargetTile.x = gameObject->Player.Position.x;
					}
					else if(gameObject->Player.CurrentDirection == LEFT) {
						currentEnemy->TargetTile.y = gameObject->Player.Position.y;
						currentEnemy->TargetTile.x = gameObject->Player.Position.x-4;
					}
					else if(gameObject->Player.CurrentDirection == RIGHT) {
						currentEnemy->TargetTile.y = gameObject->Player.Position.y;
						currentEnemy->TargetTile.x = gameObject->Player.Position.x+4;
					}
					else {
						currentEnemy->TargetTile.y = gameObject->Player.Position.y+4;
						currentEnemy->TargetTile.x = gameObject->Player.Position.x;
					}
				}
				else if(currentEnemy->CurrentGhost == INKY) {
					if(gameObject->Player.CurrentDirection == UP) {
						currentEnemy->TargetTile.y = gameObject->Player.Position.y-2;
						currentEnemy->TargetTile.x = gameObject->Player.Position.x+2;
					}
					else if(gameObject->Player.CurrentDirection == LEFT) {
						currentEnemy->TargetTile.y = gameObject->Player.Position.y-2;
						currentEnemy->TargetTile.x = gameObject->Player.Position.x-2;
					}
					else if(gameObject->Player.CurrentDirection == RIGHT) {
						currentEnemy->TargetTile.y = gameObject->Player.Position.y+2;
						currentEnemy->TargetTile.x = gameObject->Player.Position.x+2;
					}
					else {
						currentEnemy->TargetTile.y = gameObject->Player.Position.y+2;
						currentEnemy->TargetTile.x = gameObject->Player.Position.x-2;
					}
				}
				else {
					currentEnemy->TargetTile.y = gameObject->Player.Position.y;
					currentEnemy->TargetTile.x = gameObject->Player.Position.x;
				}
			}

			unsigned char											targetY;
			unsigned char											targetX;

			if(currentEnemy->TargetTile.y < currentEnemy->Position.y)
				targetY													=	(unsigned char)currentEnemy->Position.y - (unsigned char)currentEnemy->TargetTile.y;
			else
				targetY													=	(unsigned char)currentEnemy->TargetTile.y - (unsigned char)currentEnemy->Position.y;
			if(currentEnemy->TargetTile.x < currentEnemy->Position.x)
				targetX													=	(unsigned char)currentEnemy->Position.x - (unsigned char)currentEnemy->TargetTile.x;
			else
				targetX													=	(unsigned char)currentEnemy->TargetTile.x - (unsigned char)currentEnemy->Position.x;
			if(targetX < targetY)
				currentEnemy->ClosestTarget								= 'x';
			else
				currentEnemy->ClosestTarget								= 'y';

			if(currentEnemy->CurrentDirection == UP) {
				if(currentEnemy->TargetTile.y > currentEnemy->Position.y || gameObject->Map.TilesSolid[currentEnemy->Position.y-1][currentEnemy->Position.x]  == true || currentEnemy->ClosestTarget == 'x') {
					if(currentEnemy->TargetTile.x < currentEnemy->Position.x && gameObject->Map.TilesSolid[currentEnemy->Position.y][currentEnemy->Position.x-1] == false)
						currentEnemy->CurrentDirection = LEFT;
					else {
						if(gameObject->Map.TilesSolid[currentEnemy->Position.y][currentEnemy->Position.x+1] == false)
							currentEnemy->CurrentDirection = RIGHT;
						else
							currentEnemy->CurrentDirection = LEFT;
					}
				}
				else
					currentEnemy->CurrentDirection = UP;
			}
			else if(currentEnemy->CurrentDirection == LEFT) {
				if(currentEnemy->TargetTile.x > currentEnemy->Position.x || gameObject->Map.TilesSolid[currentEnemy->Position.y][currentEnemy->Position.x-1]  == true || currentEnemy->ClosestTarget == 'y') {
					if(currentEnemy->TargetTile.y > currentEnemy->Position.y && gameObject->Map.TilesSolid[currentEnemy->Position.y+1][currentEnemy->Position.x] == false)
						currentEnemy->CurrentDirection = DOWN;
					else {
						if(gameObject->Map.TilesSolid[currentEnemy->Position.y-1][currentEnemy->Position.x] == false)
							currentEnemy->CurrentDirection = UP;
						else
							currentEnemy->CurrentDirection = DOWN;
					}
				}
				else
					currentEnemy->CurrentDirection = LEFT;
			}
			else if(currentEnemy->CurrentDirection == RIGHT) {
				if(currentEnemy->TargetTile.x < currentEnemy->Position.x || gameObject->Map.TilesSolid[currentEnemy->Position.y][currentEnemy->Position.x+1]  == true || currentEnemy->ClosestTarget == 'y') {
					if(currentEnemy->TargetTile.y < currentEnemy->Position.y && gameObject->Map.TilesSolid[currentEnemy->Position.y-1][currentEnemy->Position.x] == false)
						currentEnemy->CurrentDirection = UP;
					else{
						if(gameObject->Map.TilesSolid[currentEnemy->Position.y+1][currentEnemy->Position.x] == false)
							currentEnemy->CurrentDirection = DOWN;
						else
							currentEnemy->CurrentDirection = UP;
					}
				}
				else
					currentEnemy->CurrentDirection = RIGHT;
			}
			else {
				if(currentEnemy->TargetTile.y < currentEnemy->Position.y || gameObject->Map.TilesSolid[currentEnemy->Position.y+1][currentEnemy->Position.x]  == true || currentEnemy->ClosestTarget == 'x') {
					if(currentEnemy->TargetTile.x > currentEnemy->Position.x && gameObject->Map.TilesSolid[currentEnemy->Position.y][currentEnemy->Position.x+1] == false)
						currentEnemy->CurrentDirection = RIGHT;
					else{
						if(gameObject->Map.TilesSolid[currentEnemy->Position.y][currentEnemy->Position.x-1] == false)
							currentEnemy->CurrentDirection = LEFT;
						else
							currentEnemy->CurrentDirection = RIGHT;
					}
				}
				else
					currentEnemy->CurrentDirection = DOWN;
			}
		}

		if(currentEnemy->CurrentDirection == UP) {
			if(gameObject->Map.TilesSolid[currentEnemy->Position.y-1][currentEnemy->Position.x] == true) {
				if(gameObject->Map.TilesSolid[currentEnemy->Position.y][currentEnemy->Position.x-1] != true) {
					currentEnemy->CurrentDirection = LEFT;
					enemyDeltas->x	-= fEnemySpeed*fLastFrameTime;
				}
				else {
					currentEnemy->CurrentDirection = RIGHT;
					enemyDeltas->x	+= fEnemySpeed*fLastFrameTime;
				}
			}
			else {
				if(currentEnemy->Position.y == 0)
					currentEnemy->Position.y = 21;
				else
					enemyDeltas->y			-=	fEnemySpeed * fLastFrameTime;
			}
		}
		else if(currentEnemy->CurrentDirection == LEFT) {
			if(gameObject->Map.TilesSolid[currentEnemy->Position.y][currentEnemy->Position.x-1] == true) {
				if(gameObject->Map.TilesSolid[currentEnemy->Position.y-1][currentEnemy->Position.x] != true) {
					currentEnemy->CurrentDirection = UP;
					enemyDeltas->y	-= fEnemySpeed*fLastFrameTime;
				}
				else {
					currentEnemy->CurrentDirection = DOWN;
					enemyDeltas->y	+= fEnemySpeed*fLastFrameTime;
				}
			}
			else
				enemyDeltas->x			-=	fEnemySpeed * fLastFrameTime;
		}
		else if(currentEnemy->CurrentDirection == RIGHT) {
			if(gameObject->Map.TilesSolid[currentEnemy->Position.y][currentEnemy->Position.x+1] == true) {
				if(gameObject->Map.TilesSolid[currentEnemy->Position.y-1][currentEnemy->Position.x] != true) {
					currentEnemy->CurrentDirection = UP;
					enemyDeltas->y	-= fEnemySpeed*fLastFrameTime;
				}
				else {
					currentEnemy->CurrentDirection = DOWN;
					enemyDeltas->y	+= fEnemySpeed*fLastFrameTime;
				}
			}
			else
				enemyDeltas->x			+=	fEnemySpeed * fLastFrameTime;
		}
		else {
			if(gameObject->Map.TilesSolid[currentEnemy->Position.y+1][currentEnemy->Position.x] == true) {
				if(gameObject->Map.TilesSolid[currentEnemy->Position.y][currentEnemy->Position.x-1] != true) {
					currentEnemy->CurrentDirection = LEFT;
					enemyDeltas->x	-= fEnemySpeed*fLastFrameTime;
				}
				else {
					currentEnemy->CurrentDirection = RIGHT;
					enemyDeltas->x	+= fEnemySpeed*fLastFrameTime;
				}
			}
			else {
				if(currentEnemy->Position.y == 21)
					currentEnemy->Position.y = 0;
				else
					enemyDeltas->y			+=	fEnemySpeed * fLastFrameTime;
			}
		}

		refreshPosFromDeltas( currentEnemy );
		gameObject->Map.TilesEnemy[currentEnemy->Position.y][currentEnemy->Position.x] = currentEnemy->Image;
	}
}
