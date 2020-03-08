#include "Sir_Game.h"
#include "Pieze_Description.h"

#include <Windows.h>

int menuX = 0;
int counterTitle = 0;
bool movement = false;
void																updateTitle												(SGame* gameObject) {
	if(movement == false) {
		for(int y=0; y < PIEZE_SIZE+1; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.screen[13+y][menuX+x] = sirTetrisTitle[y][x];
				gameObject->Map.screen[13+y][SCREEN_SIZE_X-menuX+x] = anothersirTetrisTitle[y][x];
			}
		}
		for(int x=0; x < 11; x++)
			gameObject->Map.screen[20][41+x] = textTitleThree[x];
		movement = true;
	}
	else {
		for(int y=0; y < PIEZE_SIZE+1; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.screen[13+y][menuX+x] = sirTetrisTitleTwo[y][x];
				gameObject->Map.screen[13+y][SCREEN_SIZE_X-menuX+x] = anothersirTetrisTitleTwo[y][x];
			}
		}
		movement = false;
	}
	if(menuX == SCREEN_SIZE_X/2-2) {
		for(int y=0; y < PIEZE_SIZE+1; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.screen[13+y][menuX+x] = sirTetrisTitleThree[y][x];
				gameObject->Map.screen[13+y][menuX+x+4] = anothersirTetrisTitleThree[y][x];
			}
		}
	}
	else
		menuX++;

	if(counterTitle > 22) {
		for(int y=0; y < 7; y++) {
			for(int x=0; x < 3; x++) {
				gameObject->Map.screen[y+4][26+x] = titleS[y][x];
				gameObject->Map.screen[y+4][66-x] = titleS[y][x];
			}
		}
	}
	if(counterTitle > 27) {
		for(int y=0; y < 7; y++) {
			for(int x=0; x < 3; x++) {
				gameObject->Map.screen[y+4][29+x] = titleI[y][x];
				gameObject->Map.screen[y+4][63-x] = titleI[y][x];
			}
		}
	}
	if(counterTitle > 31) {
		for(int y=0; y < 7; y++) {
			for(int x=0; x < 5; x++) {
				gameObject->Map.screen[y+4][32+x] = titleR[y][x];
				gameObject->Map.screen[y+4][60-x] = titleR[y][x];
			}
		}
	}
	if(counterTitle > 37) {
		for(int y=0; y < 7; y++) {
			for(int x=0; x < 6; x++) {
				gameObject->Map.screen[y+4][38+x] = titleT[y][x];
				gameObject->Map.screen[y+4][54-x] = titleT[y][x];
			}
		}
	}
	if(counterTitle == 44 || counterTitle == 45 || counterTitle == 48 || counterTitle == 49) {
		for(int y=0; y < 7; y++) {
			for(int x=0; x < 4; x++) {
				gameObject->Map.screen[y+4][44+x] = titleE[y][x];
			}
		}
		gameObject->Map.screen[14][45] = 217;
		Sleep(200);
	}
	else if(counterTitle == 46 || counterTitle == 47 || counterTitle == 50 || counterTitle == 51) {
		for(int y=0; y < 7; y++) {
			for(int x=0; x < 4; x++) {
				gameObject->Map.screen[y+4][48-x] = titleE[y][x];
			}
		}
		gameObject->Map.screen[14][47] = 192;
		Sleep(200);
	}
	if(counterTitle > 50) {
		for(int y=0; y < 7; y++) {
			for(int x=0; x < 5; x++) {
				gameObject->Map.screen[y+4][44+x] = titleEe[y][x];
			}
		}
	}

	if(counterTitle > 56 && counterTitle < 65) {
		for(int x=0; x < 5; x++) {
			gameObject->Map.screen[13][37+x] = textTitle[x];
			gameObject->Map.screen[13][55-x] = textTitle[x];
		}
	}
	else if(counterTitle > 65 && counterTitle < 80) {
		for(int y=0; y < 3; y++) {
			for(int x=0; x < 10; x++) {
				gameObject->Map.screen[13+y][32+x] = textTitleTwo[y][x];
				gameObject->Map.screen[13+y][60-x] = textTitleTwo[y][x];
			}
		}
		gameObject->Map.screen[14][47] = 196;
		gameObject->Map.screen[14][45] = 196;
	}
	else if(counterTitle > 80 && counterTitle < 110) {
		for(int y=0; y < 4; y++) {
			for(int x=0; x < 17; x++) {
				gameObject->Map.screen[13+y][25+x] = textTitleFour[y][x];
				gameObject->Map.screen[13+y][67-x] = textTitleFour[y][x];
			}
		}
		gameObject->Map.screen[16][47] = 192;
		gameObject->Map.screen[16][45] = 217;
	}
	else if(counterTitle > 110 && counterTitle < 130) {
		for(int y=0; y < 2; y++) {
			for(int x=0; x < 16; x++) {
				gameObject->Map.screen[13+y][25+x] = textTitleFive[y][x];
				gameObject->Map.screen[13+y][67-x] = textTitleFive[y][x];
			}
		}
		gameObject->Map.screen[16][47] = 0;
		gameObject->Map.screen[16][45] = 0;
		gameObject->Map.screen[15][47] = 196;
		gameObject->Map.screen[15][45] = 196;
	}
	else if(counterTitle == 130) {
		menuX = 0;
		counterTitle = 0;
	}
	
	if(GetAsyncKeyState(VK_RETURN)) {
		gameObject->ScreenMode = SCREEN_MENU;
	}
	counterTitle++;
}

bool																cursorPosition					=					 false;
void																updateMenu												(SGame* gameObject) {
	//for(int y=0; y < 7; y++) {
	//	for(int x=0; x < 40; x++) {
	//		gameObject->Map.screen[1+y][25+x] = title[y][x];
	//	}
	//}
	if(cursorPosition == false) {
		for(int x=0; x < 7; x++) {
			gameObject->Map.screen[16][40+x] = textMenuOneM[x];
		}
		for(int x=0; x < 8; x++) {
			gameObject->Map.screen[18][40+x] = textMenuTwo[x];
		}
	}
	else {
		for(int x=0; x < 7; x++) {
			gameObject->Map.screen[16][40+x] = textMenuOne[x];
		}
		for(int x=0; x < 8; x++) {
			gameObject->Map.screen[18][40+x] = textMenuTwoM[x];
		}
	}
	if(GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(VK_UP)) {
		if(cursorPosition == false)
			cursorPosition = true;
		else
			cursorPosition = false;
	}
	else if(GetAsyncKeyState(VK_RETURN)) {
		if(cursorPosition == false) {
			gameObject->ScreenMode = SCREEN_ONE_PLAYER;
			setupPlayerOne(gameObject);
			setupMapOne(gameObject);
		}
		else {
			gameObject->ScreenMode = SCREEN_TWO_PLAYERS;
			setupPlayerOne(gameObject);
			setupMapOne(gameObject);
			setupPlayerTwo(gameObject);
			setupMapTwo(gameObject);
		}
	}
}

void																	transformPieze														(SPlayer* player) {
	if						(player->currentPieze == BARRA_H) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = barraH[y][x];
			}
		}
	}
	else if					(player->currentPieze == BARRA_V) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = barraV[y][x];
			}
		}
	}
	else if						(player->currentPieze == DOS_H) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = dosH[y][x];
			}
		}
	}
	else if						(player->currentPieze == DOS_V) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = dosV[y][x];
			}
		}
	}
	else if						(player->currentPieze == ESE_H) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = eseH[y][x];
			}
		}
	}
	else if						(player->currentPieze == ESE_V) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = eseV[y][x];
			}
		}
	}
	else if						(player->currentPieze == ELE_UP) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = eleUp[y][x];
			}
		}
	}
	else if						(player->currentPieze == ELE_LEFT) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = eleLeft[y][x];
			}
		}
	}
	else if						(player->currentPieze == ELE_DOWN) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = eleDown[y][x];
			}
		}
	}
	else if						(player->currentPieze == ELE_RIGHT) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = eleRight[y][x];
			}
		}
	}
	else if						(player->currentPieze == ELE_INV_UP) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = eleInvUp[y][x];
			}
		}
	}
	else if						(player->currentPieze == ELE_INV_LEFT) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = eleInvLeft[y][x];
			}
		}
	}
	else if						(player->currentPieze == ELE_INV_DOWN) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = eleInvDown[y][x];
			}
		}
	}
	else if						(player->currentPieze == ELE_INV_RIGHT) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = eleInvRight[y][x];
			}
		}
	}
	else if						(player->currentPieze == PODIO_UP) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = podioUp[y][x];
			}
		}
	}
	else if						(player->currentPieze == PODIO_LEFT) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = podioLeft[y][x];
			}
		}
	}
	else if						(player->currentPieze == PODIO_DOWN) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = podioDown[y][x];
			}
		}
	}
	else if						(player->currentPieze == PODIO_RIGHT) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = podioRight[y][x];
			}
		}
	}
	else {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				player->realPieze[y][x] = square[y][x];
			}
		}
	}
}
void																	rotateLeft													(SPlayer* player) {
	if			(player->currentPieze == BARRA_H)			player->currentPieze = BARRA_V;
	else if		(player->currentPieze == BARRA_V)			player->currentPieze = BARRA_H;
	else if		(player->currentPieze == DOS_V)				player->currentPieze = DOS_H;
	else if		(player->currentPieze == DOS_H)				player->currentPieze = DOS_V;
	else if		(player->currentPieze == ESE_V)				player->currentPieze = ESE_H;
	else if		(player->currentPieze == ESE_H)				player->currentPieze = ESE_V;
	else if		(player->currentPieze == ELE_UP)			player->currentPieze = ELE_LEFT;
	else if		(player->currentPieze == ELE_LEFT)			player->currentPieze = ELE_DOWN;
	else if		(player->currentPieze == ELE_DOWN)			player->currentPieze = ELE_RIGHT;
	else if		(player->currentPieze == ELE_RIGHT)			player->currentPieze = ELE_UP;
	else if		(player->currentPieze == ELE_INV_UP)		player->currentPieze = ELE_INV_LEFT;
	else if		(player->currentPieze == ELE_INV_LEFT)		player->currentPieze = ELE_INV_DOWN;
	else if		(player->currentPieze == ELE_INV_DOWN)		player->currentPieze = ELE_INV_RIGHT;
	else if		(player->currentPieze == ELE_INV_RIGHT)		player->currentPieze = ELE_INV_UP;
	else if		(player->currentPieze == PODIO_UP)			player->currentPieze = PODIO_LEFT;
	else if		(player->currentPieze == PODIO_LEFT)		player->currentPieze = PODIO_DOWN;
	else if		(player->currentPieze == PODIO_DOWN)		player->currentPieze = PODIO_RIGHT;
	else if		(player->currentPieze == PODIO_RIGHT)		player->currentPieze = PODIO_UP;
	transformPieze(player);
}
void																	rotateRight													(SPlayer* player) {
	if			(player->currentPieze == BARRA_H)			player->currentPieze = BARRA_V;
	else if		(player->currentPieze == BARRA_V)			player->currentPieze = BARRA_H;
	else if		(player->currentPieze == DOS_V)				player->currentPieze = DOS_H;
	else if		(player->currentPieze == DOS_H)				player->currentPieze = DOS_V;
	else if		(player->currentPieze == ESE_V)				player->currentPieze = ESE_H;
	else if		(player->currentPieze == ESE_H)				player->currentPieze = ESE_V;
	else if		(player->currentPieze == ELE_UP)			player->currentPieze = ELE_RIGHT;
	else if		(player->currentPieze == ELE_RIGHT)			player->currentPieze = ELE_DOWN;
	else if		(player->currentPieze == ELE_DOWN)			player->currentPieze = ELE_LEFT;
	else if		(player->currentPieze == ELE_LEFT)			player->currentPieze = ELE_UP;
	else if		(player->currentPieze == ELE_INV_UP)		player->currentPieze = ELE_INV_RIGHT;
	else if		(player->currentPieze == ELE_INV_RIGHT)		player->currentPieze = ELE_INV_DOWN;
	else if		(player->currentPieze == ELE_INV_DOWN)		player->currentPieze = ELE_INV_LEFT;
	else if		(player->currentPieze == ELE_INV_LEFT)		player->currentPieze = ELE_INV_UP;
	else if		(player->currentPieze == PODIO_UP)			player->currentPieze = PODIO_RIGHT;
	else if		(player->currentPieze == PODIO_RIGHT)		player->currentPieze = PODIO_DOWN;
	else if		(player->currentPieze == PODIO_DOWN)		player->currentPieze = PODIO_LEFT;
	else if		(player->currentPieze == PODIO_LEFT)		player->currentPieze = PODIO_UP;
	transformPieze(player);
}
void																	refreshPosFromDeltas										( SPlayer* character )	{
	::ftwlib::SCoord2<float>												*charDeltas							= &character->positionDeltas;
	
	int																		deltaY								= (int)charDeltas->y;
	character->axis.y														+= deltaY;
	charDeltas->y															-= deltaY;
	if(charDeltas->y < 0) {
		character->axis.y														-= 1;
		charDeltas->y															+= 1;
	}
}
void																	getRandomPieze													(SPlayer* player) {
	int																		random														=	rand() % 7;
	if						(random == BARRA)									player->nextPieze					=	BARRA;
	else if					(random == PODIO)									player->nextPieze					=	PODIO;
	else if					(random == SQUARE)									player->nextPieze					=	SQUARE;
	else if					(random == DOS)										player->nextPieze					=	DOS;
	else if					(random == ESE)										player->nextPieze					=	ESE;
	else if					(random == ELE_INV)									player->nextPieze					=	ELE_INV;
	else																		player->nextPieze					=	ELE;
}

void																	getNewPieze														(SPlayer* player) {
	if						(player->nextPieze == BARRA)						player->currentPieze				=	BARRA_H;
	else if					(player->nextPieze == PODIO)						player->currentPieze				=	PODIO_DOWN;
	else if					(player->nextPieze == SQUARE)						player->currentPieze				=	SQUARE_O;
	else if					(player->nextPieze == DOS)							player->currentPieze				=	DOS_H;
	else if					(player->nextPieze == ESE)							player->currentPieze				=	ESE_H;
	else if					(player->nextPieze == ELE_INV)						player->currentPieze				=	ELE_INV_RIGHT;
	else																		player->currentPieze				=	ELE_LEFT;

	player->axis.y				=				0;
	player->axis.x				=				10;
	player->positionDeltas		=				{0, 0};
	transformPieze(player);
	getRandomPieze(player);
	player->animation = true;
}
void																	linesCheck													(unsigned char	someMap[MAP_SIZE_Y][MAP_SIZE_X], SPlayer *player) {
	int linesCount = 0;
	for(int y = MAP_SIZE_Y-2; y>0; y--) {
		int xCheck = 6;

		while(true) {
			if(someMap[y][xCheck] == TILE_VOID)
				break;
			if(xCheck == MAP_SIZE_X-1) {
				for(int x=6; x < MAP_SIZE_X-1; x++) {
					someMap[y][x] = TILE_VOID;
				}
				for(int anotherY = y; anotherY > 0; anotherY--) {
					for(int anotherX = 6; anotherX < MAP_SIZE_X-1; anotherX++) {
						if(someMap[anotherY][anotherX] == TILE_BLOCK) {
							someMap[anotherY][anotherX] = TILE_VOID;
							someMap[anotherY+1][anotherX] = TILE_BLOCK;
						}
					}
				}
				linesCount++;
				++y;
			}
			xCheck++;
		}
	}
	if(linesCount > 0) {
		if(linesCount == 1) {
			player->score += 100;
			if(player->power != 32)
				player->power += 1;
		}
		else if(linesCount == 2) {
			player->score += 400;
			if(player->power != 32)
				player->power += 4;
		}
		else if(linesCount == 3) {
			player->score += 900;
			if(player->power != 32)
				player->power += 9;
		}
		else {
			player->score += 1600;
			if(player->power != 32)
				player->power += 16;
		}
	}
	if(player->power > 32)
		player->power = 32;
}

void																powerLine												(unsigned char someMap[MAP_SIZE_Y][MAP_SIZE_X]) {
	for(int y = 0; y < MAP_SIZE_Y-1; y++) {
		for(int x=6; x < MAP_SIZE_X-1; x++) {
			if(someMap[y][x] == TILE_BLOCK) {
				someMap[y][x] = TILE_VOID;
				someMap[y-1][x] = TILE_BLOCK;
			}
		}
	}
	for(int x=6; x < MAP_SIZE_X-1; x++) {
		someMap[MAP_SIZE_Y-2][x] = TILE_BLOCK;
	}
	int random = rand()%11+6;
	someMap[MAP_SIZE_Y-2][random] = TILE_VOID;
}
void																decreaseLine												(unsigned char someMap[MAP_SIZE_Y][MAP_SIZE_X]) {
	for(int x=6; x < MAP_SIZE_X-1; x++)
		someMap[MAP_SIZE_Y-2][x] = TILE_VOID;
	for(int y = MAP_SIZE_Y-3; y > 0; y--) {
		for(int x=6; x < MAP_SIZE_X-1; x++) {
			if(someMap[y][x] == TILE_BLOCK) {
				someMap[y][x] = TILE_VOID;
				someMap[y+1][x] = TILE_BLOCK;
			}
		}
	}
}

void																updatePlayerOne											(SGame* gameObject, float fLastFrameTime) {
	SPlayer		& player					=					 gameObject->PlayerOne;
//////////////////////////////////////////////clean pieze////////////////////////////
	for(int y=0; y < PIEZE_SIZE; y++) {
		for(int x=0; x < PIEZE_SIZE; x++) {
			if(player.realPieze[y][x] != TILE_VOID)
				gameObject->Map.mapOne[player.axis.y+y][player.axis.x+x] = TILE_VOID;
		}
	}
/////////////////////////////////////////////check move//////////////////////////////
	if(GetAsyncKeyState('A')) {
		bool										check						= false;
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapOne[player.axis.y+y][player.axis.x+x-1] != TILE_VOID)
					check = true;
			}
		}
		if(check == false)
			player.axis.x--;
	}
	else if(GetAsyncKeyState('D')) {
		bool										check						= false;
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapOne[player.axis.y+y][player.axis.x+x+1] != TILE_VOID)
					check = true;
			}
		}
		if(check == false)
			player.axis.x++;
	}
//////////////////////////////check rotation///////////////////////////////////////////
	if(GetAsyncKeyState('T')) {
		rotateLeft(&player);
		bool check = false;
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapOne[player.axis.y+y][player.axis.x+x] != TILE_VOID)
					check = true;
			}
		}
		if(check == true)
			rotateRight(&player);
	}
	else if(GetAsyncKeyState('W') || GetAsyncKeyState('Y')) {
		rotateRight(&player);
		bool check = false;
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapOne[player.axis.y+y][player.axis.x+x] != TILE_VOID)
					check = true;
			}
		}
		if(check == true)
			rotateLeft(&player);
	}
	if(GetAsyncKeyState(VK_SPACE)) {
		int futureY = player.axis.y;
		bool check = false;
		while(true) {
			for(int y=0; y < PIEZE_SIZE; y++) {
				for(int x=0; x < PIEZE_SIZE; x++) {
					if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapOne[futureY+y][player.axis.x+x] != TILE_VOID) {
						check = true;
					}
				}
			}
			if(check == true) {
				for(int anotherY=0; anotherY < PIEZE_SIZE; anotherY++) {
					for(int anotherX=0; anotherX < PIEZE_SIZE; anotherX++) {
						if(player.realPieze[anotherY][anotherX] != TILE_VOID)
							gameObject->Map.mapOne[futureY+anotherY-1][player.axis.x+anotherX] = TILE_BLOCK;
					}
				}
				linesCheck(gameObject->Map.mapOne, &player);
				getNewPieze(&player);
				break;
			}
			++futureY;
		}
	}
/////////////////////////////////////////check power////////////////////////////////////////////////
	if(GetAsyncKeyState('G') && gameObject->ScreenMode == SCREEN_TWO_PLAYERS && player.power > 7) {
		if(player.power > 7 && player.power < 16) {
			player.power-=8;
			powerLine(gameObject->Map.mapTwo);
		}
		else if(player.power > 15 && player.power < 24) {
			player.power-=16;
			powerLine(gameObject->Map.mapTwo);
			powerLine(gameObject->Map.mapTwo);
		}
		else if(player.power > 23 && player.power < 32) {
			player.power-=24;
			powerLine(gameObject->Map.mapTwo);
			powerLine(gameObject->Map.mapTwo);
			powerLine(gameObject->Map.mapTwo);
		}
		else {
			player.power-=32;
			powerLine(gameObject->Map.mapTwo);
			powerLine(gameObject->Map.mapTwo);
			powerLine(gameObject->Map.mapTwo);
			powerLine(gameObject->Map.mapTwo);
		}
	}
	if(GetAsyncKeyState('H') && gameObject->ScreenMode == SCREEN_TWO_PLAYERS && player.power > 7) {
		if(player.power > 7 && player.power < 16) {
			player.power-=8;
			gameObject->PlayerTwo.speed += 0.25f;
		}
		else if(player.power > 15 && player.power < 24) {
			player.power-=16;
			gameObject->PlayerTwo.speed += 0.50f;
		}
		else if(player.power > 23 && player.power < 32) {
			player.power-=24;
			gameObject->PlayerTwo.speed += 0.75f;
		}
		else {
			player.power-=32;
			gameObject->PlayerTwo.speed += 1.00f;
		}
	}
	if(GetAsyncKeyState('E') && gameObject->ScreenMode == SCREEN_TWO_PLAYERS && player.power > 7) {
		if(player.power > 7 && player.power < 16) {
			player.power-=8;
			player.speed -= 0.25f;
		}
		else if(player.power > 15 && player.power < 24) {
			player.power-=16;
			player.speed -= 0.50f;
		}
		else if(player.power > 23 && player.power < 32) {
			player.power-=24;
			player.speed -= 0.75f;
		}
		else {
			player.power-=32;
			player.speed -= 1.00f;
		}
	}
	if(GetAsyncKeyState('Q') && gameObject->ScreenMode == SCREEN_TWO_PLAYERS && player.power > 7) {
		if(player.power > 7 && player.power < 16) {
			player.power-=8;
			decreaseLine(gameObject->Map.mapOne);
		}
		else if(player.power > 15 && player.power < 24) {
			player.power-=16;
			decreaseLine(gameObject->Map.mapOne);
			decreaseLine(gameObject->Map.mapOne);
		}
		else if(player.power > 23 && player.power < 32) {
			player.power-=24;
			decreaseLine(gameObject->Map.mapOne);
			decreaseLine(gameObject->Map.mapOne);
			decreaseLine(gameObject->Map.mapOne);
		}
		else {
			player.power-=32;
			decreaseLine(gameObject->Map.mapOne);
			decreaseLine(gameObject->Map.mapOne);
			decreaseLine(gameObject->Map.mapOne);
		}
	}
/////////////////////////////////////////increase axis y////////////////////////////////////////////
	float																fSpeed									= GetAsyncKeyState('S') ? gameObject->PlayerOne.speed*3.0f : gameObject->PlayerOne.speed;
	::ftwlib::SCoord2<float>											* playerDeltas							= &gameObject->PlayerOne.positionDeltas;

	playerDeltas->y			+=	fSpeed*fLastFrameTime;
	refreshPosFromDeltas( &gameObject->PlayerOne );
/////////////////////////////////////////check pieze/////////////////////////////////////////////////
	bool										check						= false;
	for(int y=0; y < PIEZE_SIZE; y++) {
		for(int x=0; x < PIEZE_SIZE; x++) {
			if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapOne[player.axis.y+y][player.axis.x+x] != TILE_VOID)
				check = true;
		}
	}
	if(check == true) {
		if(gameObject->ScreenMode == SCREEN_ONE_PLAYER && player.axis.y == 1) {
			setupMapOne(gameObject);
			setupPlayerOne(gameObject);
			player.score = 0;
		}
		else if(gameObject->ScreenMode == SCREEN_TWO_PLAYERS && player.axis.y == 1) {
			gameObject->ScreenMode = SCREEN_MENU;
		}
		else {
			for(int y=0; y < PIEZE_SIZE; y++) {
				for(int x=0; x < PIEZE_SIZE; x++) {
					if(player.realPieze[y][x] != TILE_VOID)
						gameObject->Map.mapOne[player.axis.y+y-1][player.axis.x+x] = TILE_BLOCK;
				}
			}
			linesCheck(gameObject->Map.mapOne, &player);
			getNewPieze(&player);
		}
	}
	else {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				if(player.realPieze[y][x] != TILE_VOID)
					gameObject->Map.mapOne[player.axis.y+y][player.axis.x+x] = player.realPieze[y][x];
			}
		}
	}
////////////////////////////////////////////set map///////////////////////////////////////////////////////////
	if						(gameObject->PlayerOne.nextPieze == BARRA) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapOne[2+y][x] = barraH[y][x];
			}
		}
	}
	else if					(gameObject->PlayerOne.nextPieze == PODIO) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapOne[2+y][x] = podioDown[y][x];
			}
		}
	}
	else if					(gameObject->PlayerOne.nextPieze == SQUARE) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapOne[2+y][x] = square[y][x];
			}
		}
	}
	else if					(gameObject->PlayerOne.nextPieze == DOS) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapOne[2+y][x] = dosH[y][x];
			}
		}
	}
	else if					(gameObject->PlayerOne.nextPieze == ESE) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapOne[2+y][x] = eseH[y][x];
			}
		}
	}
	else if					(gameObject->PlayerOne.nextPieze == ELE_INV) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapOne[2+y][x] = eleInvRight[y][x];
			}
		}
	}
	else {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapOne[2+y][x] = eleLeft[y][x];
			}
		}
	}

	if(player.animation == true) {
		for(int y=0; y < PIEZE_SIZE+1; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapOne[5+y][x] = sirTerisTwo[y][x];
			}
		}
		player.animation = false;
	}
	else {
		for(int y=0; y < PIEZE_SIZE+1; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapOne[5+y][x] = sirTeris[y][x];
			}
		}
	}

	if(gameObject->ScreenMode == SCREEN_ONE_PLAYER) {
		for(int y=0; y < MAP_SIZE_Y; y++) {
			for(int x=0; x < MAP_SIZE_X; x++) {
				gameObject->Map.screen[4+y][36+x] = gameObject->Map.mapOne[y][x];
			}
		}
	}
	if(gameObject->ScreenMode == SCREEN_TWO_PLAYERS) {
		for(int y=0; y < MAP_SIZE_Y; y++) {
			for(int x=0; x < MAP_SIZE_X; x++) {
				gameObject->Map.screen[5+y][14+x] = gameObject->Map.mapOne[y][x];
			}
		}
		if(player.power > 0 && player.power < 17) {
			for(unsigned int y = 0; y != player.power; ++y)
				gameObject->Map.screen[SCREEN_SIZE_Y-1-y][33] = TILE_BLOCK;
		}
		else if(player.power > 16) {
			for(unsigned int y = 0; y != player.power-16; ++y)
				gameObject->Map.screen[SCREEN_SIZE_Y-1-y][34] = TILE_BLOCK;
			for(unsigned int y = 0; y < 16; ++y)
				gameObject->Map.screen[SCREEN_SIZE_Y-1-y][33] = TILE_BLOCK;
		}
	}
}

void																updatePlayerTwo											(SGame* gameObject, float fLastFrameTime) {
	SPlayer		& player					=					 gameObject->PlayerTwo;
//////////////////////////////////////////////clean pieze////////////////////////////
	for(int y=0; y < PIEZE_SIZE; y++) {
		for(int x=0; x < PIEZE_SIZE; x++) {
			if(player.realPieze[y][x] != TILE_VOID)
				gameObject->Map.mapTwo[player.axis.y+y][player.axis.x+x] = TILE_VOID;
		}
	}
/////////////////////////////////////////////check move//////////////////////////////
	if(GetAsyncKeyState(VK_LEFT)) {
		bool										check						= false;
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapTwo[player.axis.y+y][player.axis.x+x-1] != TILE_VOID)
					check = true;
			}
		}
		if(check == false)
			player.axis.x--;
	}
	else if(GetAsyncKeyState(VK_RIGHT)) {
		bool										check						= false;
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapTwo[player.axis.y+y][player.axis.x+x+1] != TILE_VOID)
					check = true;
			}
		}
		if(check == false)
			player.axis.x++;
	}
//////////////////////////////check rotation///////////////////////////////////////////
	if(GetAsyncKeyState(VK_NUMPAD1)) {
		rotateLeft(&player);
		bool check = false;
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapTwo[player.axis.y+y][player.axis.x+x] != TILE_VOID)
					check = true;
			}
		}
		if(check == true)
			rotateRight(&player);
	}
	else if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_NUMPAD2)) {
		rotateRight(&player);
		bool check = false;
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapTwo[player.axis.y+y][player.axis.x+x] != TILE_VOID)
					check = true;
			}
		}
		if(check == true)
			rotateLeft(&player);
	}
	if(GetAsyncKeyState(VK_NUMPAD0)) {
		int futureY = player.axis.y;
		bool check = false;
		while(true) {
			for(int y=0; y < PIEZE_SIZE; y++) {
				for(int x=0; x < PIEZE_SIZE; x++) {
					if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapTwo[futureY+y][player.axis.x+x] != TILE_VOID) {
						check = true;
					}
				}
			}
			if(check == true) {
				for(int anotherY=0; anotherY < PIEZE_SIZE; anotherY++) {
					for(int anotherX=0; anotherX < PIEZE_SIZE; anotherX++) {
						if(player.realPieze[anotherY][anotherX] != TILE_VOID)
							gameObject->Map.mapTwo[futureY+anotherY-1][player.axis.x+anotherX] = TILE_BLOCK;
					}
				}
				linesCheck(gameObject->Map.mapTwo, &player);
				getNewPieze(&player);
				break;
			}
			++futureY;
		}
	}
/////////////////////////////////////////check power////////////////////////////////////////////////
	if(GetAsyncKeyState(VK_NUMPAD4) && player.power > 7) {
		if(player.power > 7 && player.power < 16) {
			player.power-=8;
			powerLine(gameObject->Map.mapOne);
		}
		else if(player.power > 15 && player.power < 24) {
			player.power-=16;
			powerLine(gameObject->Map.mapOne);
			powerLine(gameObject->Map.mapOne);
		}
		else if(player.power > 23 && player.power < 32) {
			player.power-=24;
			powerLine(gameObject->Map.mapOne);
			powerLine(gameObject->Map.mapOne);
			powerLine(gameObject->Map.mapOne);
		}
		else {
			player.power-=32;
			powerLine(gameObject->Map.mapOne);
			powerLine(gameObject->Map.mapOne);
			powerLine(gameObject->Map.mapOne);
			powerLine(gameObject->Map.mapOne);
		}
	}
	if(GetAsyncKeyState(VK_NUMPAD5) && player.power > 7) {
		if(player.power > 7 && player.power < 16) {
			player.power-=8;
			gameObject->PlayerOne.speed += 0.25f;
		}
		else if(player.power > 15 && player.power < 24) {
			player.power-=16;
			gameObject->PlayerOne.speed += 0.50f;
		}
		else if(player.power > 23 && player.power < 32) {
			player.power-=24;
			gameObject->PlayerOne.speed += 0.75f;
		}
		else {
			player.power-=32;
			gameObject->PlayerOne.speed += 1.00f;
		}
	}
	if(GetAsyncKeyState(VK_NUMPAD6) && player.power > 7) {
		if(player.power > 7 && player.power < 16) {
			player.power-=8;
			player.speed -= 0.25f;
		}
		else if(player.power > 15 && player.power < 24) {
			player.power-=16;
			player.speed -= 0.50f;
		}
		else if(player.power > 23 && player.power < 32) {
			player.power-=24;
			player.speed -= 0.75f;
		}
		else {
			player.power-=32;
			player.speed -= 1.00f;
		}
	}
	if(GetAsyncKeyState(VK_NUMPAD3) && player.power > 7) {
		if(player.power > 7 && player.power < 16) {
			player.power-=8;
			decreaseLine(gameObject->Map.mapTwo);
		}
		else if(player.power > 15 && player.power < 24) {
			player.power-=16;
			decreaseLine(gameObject->Map.mapTwo);
			decreaseLine(gameObject->Map.mapTwo);
		}
		else if(player.power > 23 && player.power < 32) {
			player.power-=24;
			decreaseLine(gameObject->Map.mapTwo);
			decreaseLine(gameObject->Map.mapTwo);
			decreaseLine(gameObject->Map.mapTwo);
		}
		else {
			player.power-=32;
			decreaseLine(gameObject->Map.mapTwo);
			decreaseLine(gameObject->Map.mapTwo);
			decreaseLine(gameObject->Map.mapTwo);
		}
	}
/////////////////////////////////////////increase axis y////////////////////////////////////////////
	float																fSpeed									= GetAsyncKeyState(VK_DOWN) ? gameObject->PlayerTwo.speed*3.0f : gameObject->PlayerTwo.speed;
	::ftwlib::SCoord2<float>											* playerDeltas							= &gameObject->PlayerTwo.positionDeltas;

	playerDeltas->y			+=	fSpeed*fLastFrameTime;
	refreshPosFromDeltas( &gameObject->PlayerTwo );
/////////////////////////////////////////check pieze/////////////////////////////////////////////////
	bool										check						= false;
	for(int y=0; y < PIEZE_SIZE; y++) {
		for(int x=0; x < PIEZE_SIZE; x++) {
			if(player.realPieze[y][x] != TILE_VOID && gameObject->Map.mapTwo[player.axis.y+y][player.axis.x+x] != TILE_VOID)
				check = true;
		}
	}
	if(check == true) {
		if(player.axis.y == 1) {
			gameObject->ScreenMode = SCREEN_MENU;
		}
		else {
			for(int y=0; y < PIEZE_SIZE; y++) {
				for(int x=0; x < PIEZE_SIZE; x++) {
					if(player.realPieze[y][x] != TILE_VOID)
						gameObject->Map.mapTwo[player.axis.y+y-1][player.axis.x+x] = TILE_BLOCK;
				}
			}
			linesCheck(gameObject->Map.mapTwo, &player);
			getNewPieze(&player);
		}
	}
	else {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				if(player.realPieze[y][x] != TILE_VOID)
					gameObject->Map.mapTwo[player.axis.y+y][player.axis.x+x] = player.realPieze[y][x];
			}
		}
	}
////////////////////////////////////////////set map///////////////////////////////////////////////////////////
	if						(gameObject->PlayerTwo.nextPieze == BARRA) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapTwo[2+y][x] = barraH[y][x];
			}
		}
	}
	else if					(gameObject->PlayerTwo.nextPieze == PODIO) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapTwo[2+y][x] = podioDown[y][x];
			}
		}
	}
	else if					(gameObject->PlayerTwo.nextPieze == SQUARE) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapTwo[2+y][x] = square[y][x];
			}
		}
	}
	else if					(gameObject->PlayerTwo.nextPieze == DOS) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapTwo[2+y][x] = dosH[y][x];
			}
		}
	}
	else if					(gameObject->PlayerTwo.nextPieze == ESE) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapTwo[2+y][x] = eseH[y][x];
			}
		}
	}
	else if					(gameObject->PlayerTwo.nextPieze == ELE_INV) {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapTwo[2+y][x] = eleInvRight[y][x];
			}
		}
	}
	else {
		for(int y=0; y < PIEZE_SIZE; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapTwo[2+y][x] = eleLeft[y][x];
			}
		}
	}
	
	if(player.animation == true) {
		for(int y=0; y < PIEZE_SIZE+1; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapTwo[5+y][x] = anothersirTerisTwo[y][x];
			}
		}
		player.animation = false;
	}
	else {
		for(int y=0; y < PIEZE_SIZE+1; y++) {
			for(int x=0; x < PIEZE_SIZE; x++) {
				gameObject->Map.mapTwo[5+y][x] = anothersirTeris[y][x];
			}
		}
	}

	for(int y=0; y < MAP_SIZE_Y; y++) {
		for(int x=0; x < MAP_SIZE_X; x++) {
			gameObject->Map.screen[5+y][SCREEN_SIZE_X/2+14+x] = gameObject->Map.mapTwo[y][x];
		}
	}

	if(player.power > 0 && player.power < 17) {
		for(unsigned int y = 0; y != player.power; ++y)
			gameObject->Map.screen[SCREEN_SIZE_Y-1-y][SCREEN_SIZE_X/2+33] = TILE_BLOCK;
	}
	else if(player.power > 16) {
		for(unsigned int y = 0; y != player.power-16; ++y)
			gameObject->Map.screen[SCREEN_SIZE_Y-1-y][SCREEN_SIZE_X/2+34] = TILE_BLOCK;
		for(unsigned int y = 0; y < 16; ++y)
			gameObject->Map.screen[SCREEN_SIZE_Y-1-y][SCREEN_SIZE_X/2+33] = TILE_BLOCK;
	}
}