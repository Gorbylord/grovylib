#include "Game.h"

#include <Windows.h>

void																	refreshPosFromDeltas										( SPieze* character )	{
	::ftwlib::SCoord2<float>												*charDeltas							= &character->PositionDeltas;
	//int																		deltaX								= (int)charDeltas->x;
	//character->Axis.x														+= deltaX;
	//charDeltas->x															-= deltaX;
	//if(charDeltas->x < 0) {
	//	character->Axis.x														-= 1;
	//	charDeltas->x															+= 1;
	//}
	int																		deltaY								= (int)charDeltas->y;
	character->Axis.y														+= deltaY;
	charDeltas->y															-= deltaY;
	if(charDeltas->y < 0) {
		character->Axis.y														-= 1;
		charDeltas->y															+= 1;
	}
}
void																	randomPieze													(SGame* gameObject) {
	int																		random														=	rand() % 7;
	if						(random == BARRA)									gameObject->nextPieze										=	BARRA;
	else if					(random == PODIO)									gameObject->nextPieze										=	PODIO;
	else if					(random == SQUARE)									gameObject->nextPieze										=	SQUARE;
	else if					(random == ESCALERITA_IZQUIERDA)					gameObject->nextPieze										=	ESCALERITA_IZQUIERDA;
	else if					(random == ESCALERITA_DERECHA)						gameObject->nextPieze										=	ESCALERITA_DERECHA;
	else if					(random == L_DERECHA)								gameObject->nextPieze										=	L_DERECHA;
	else																		gameObject->nextPieze										=	L_IZQUIERDA;
}
void																	setParts													(SGame* gameObject) {
	if(gameObject->pieze.Type == BARRA)																												{
		if									(gameObject->pieze.Direction == UP || gameObject->pieze.Direction == DOWN)								{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y-2;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x;
		}
		else																																	{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x+1;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x-1;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x-2;
		}
	}
	else if(gameObject->pieze.Type == ESCALERITA_IZQUIERDA)																							{
		if									(gameObject->pieze.Direction == UP || gameObject->pieze.Direction == DOWN)							{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x+1;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x+1;
		}
		else																																	{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x+1;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x-1;
		}
	}
	else if(gameObject->pieze.Type == ESCALERITA_DERECHA)																							{
		if									(gameObject->pieze.Direction == UP || gameObject->pieze.Direction == DOWN)							{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x-1;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x-1;
		}
		else																																	{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x-1;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x+1;
		}
	}
	else if(gameObject->pieze.Type == PODIO)																										{
		if												(gameObject->pieze.Direction == UP )													{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x-1;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x+1;
		}
		else if											(gameObject->pieze.Direction == LEFT)													{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x-1;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x;
		}
		else if											(gameObject->pieze.Direction == DOWN)													{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x+1;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x-1;
		}
		else																																	{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x+1;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x;
		}
	}
	else if(gameObject->pieze.Type == L_IZQUIERDA)																									{
		if												(gameObject->pieze.Direction == UP )													{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x-1;
		}
		else if											(gameObject->pieze.Direction == LEFT)													{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x+1;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x-1;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x-1;
		}
		else if											(gameObject->pieze.Direction == DOWN)													{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x+1;
		}
		else																																	{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x-1;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x+1;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x+1;
		}
	}
	else if(gameObject->pieze.Type == L_DERECHA)																									{
		if												(gameObject->pieze.Direction == UP )													{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x+1;
		}
		else if											(gameObject->pieze.Direction == LEFT)													{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x+1;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x-1;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x-1;
		}
		else if											(gameObject->pieze.Direction == DOWN)													{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x-1;
		}
		else																																	{
			gameObject->parts[0].y	=	gameObject->pieze.Axis.y;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x-1;
			gameObject->parts[1].y	=	gameObject->pieze.Axis.y;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x+1;
			gameObject->parts[2].y	=	gameObject->pieze.Axis.y+1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x+1;
		}
	}
	else																																			{
		gameObject->parts[0].y	=	gameObject->pieze.Axis.y;						gameObject->parts[0].x	=	gameObject->pieze.Axis.x-1;
		gameObject->parts[1].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[1].x	=	gameObject->pieze.Axis.x-1;
		gameObject->parts[2].y	=	gameObject->pieze.Axis.y-1;						gameObject->parts[2].x	=	gameObject->pieze.Axis.x;
	}
}
void																	getNewPieze															(SGame* gameObject) {
	gameObject->pieze.Axis.x							=							5;
	gameObject->pieze.Axis.y							=							2;
	gameObject->pieze.PositionDeltas					=							{0, 0};
	gameObject->pieze.Type								=							gameObject->nextPieze;
	if(gameObject->pieze.Type == PODIO)
		gameObject->pieze.Direction							=							DOWN;
	else if(gameObject->pieze.Type == L_IZQUIERDA)
		gameObject->pieze.Direction							=							LEFT;
	else
		gameObject->pieze.Direction							=							RIGHT;
	setParts(gameObject);
	if		(gameObject->pieze.Type == L_IZQUIERDA	|| gameObject->pieze.Type == ESCALERITA_IZQUIERDA)	gameObject->pieze.Image			=		176;
	else if	(gameObject->pieze.Type == L_DERECHA	|| gameObject->pieze.Type == ESCALERITA_DERECHA)	gameObject->pieze.Image			=		177;
	else																								gameObject->pieze.Image			=		178;
	randomPieze(gameObject);
	if(gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x]	== TILE_BLOCK || gameObject->map.mapTiles[gameObject->parts[0].y][gameObject->parts[0].x] == TILE_BLOCK
	|| gameObject->map.mapTiles[gameObject->parts[1].y][gameObject->parts[1].x]	== TILE_BLOCK || gameObject->map.mapTiles[gameObject->parts[2].y][gameObject->parts[2].x] == TILE_BLOCK)
		setup(gameObject);
}
void bonus(SGame* gameObject) {
	if(gameObject->comboCounter == 1) {
		gameObject->map.mapPiezes[10][3] = 'S'; gameObject->map.mapPiezes[10][4] = 'I'; gameObject->map.mapPiezes[10][5] = 'N'; gameObject->map.mapPiezes[10][6] = 'G';
		gameObject->map.mapPiezes[10][7] = 'L'; gameObject->map.mapPiezes[10][8] = 'E'; gameObject->Score += 100;
	}
	else if(gameObject->comboCounter == 2) {
		gameObject->map.mapPiezes[10][3] = 'D'; gameObject->map.mapPiezes[10][4] = 'O'; gameObject->map.mapPiezes[10][5] = 'U'; gameObject->map.mapPiezes[10][6] = 'B';
		gameObject->map.mapPiezes[10][7] = 'L'; gameObject->map.mapPiezes[10][8] = 'E';
		gameObject->map.mapPiezes[11][3] = 'D'; gameObject->map.mapPiezes[11][4] = 'O'; gameObject->map.mapPiezes[11][5] = 'U'; gameObject->map.mapPiezes[11][6] = 'B';
		gameObject->map.mapPiezes[11][7] = 'L'; gameObject->map.mapPiezes[11][8] = 'E'; gameObject->Score += 400;
	}
	else if(gameObject->comboCounter == 3) {
		gameObject->map.mapPiezes[10][3] = 'T'; gameObject->map.mapPiezes[10][4] = 'R'; gameObject->map.mapPiezes[10][5] = 'I'; gameObject->map.mapPiezes[10][6] = 'P';
		gameObject->map.mapPiezes[10][7] = 'L'; gameObject->map.mapPiezes[10][8] = 'E';
		gameObject->map.mapPiezes[11][3] = 'T'; gameObject->map.mapPiezes[11][4] = 'R'; gameObject->map.mapPiezes[11][5] = 'I'; gameObject->map.mapPiezes[11][6] = 'P';
		gameObject->map.mapPiezes[11][7] = 'L'; gameObject->map.mapPiezes[11][8] = 'E';
		gameObject->map.mapPiezes[12][3] = 'T'; gameObject->map.mapPiezes[12][4] = 'R'; gameObject->map.mapPiezes[12][5] = 'I'; gameObject->map.mapPiezes[12][6] = 'P';
		gameObject->map.mapPiezes[12][7] = 'L'; gameObject->map.mapPiezes[12][8] = 'E'; gameObject->Score += 900;
	}
	else {
		gameObject->map.mapPiezes[10][3] = 'T'; gameObject->map.mapPiezes[10][4] = 'E'; gameObject->map.mapPiezes[10][5] = 'T'; gameObject->map.mapPiezes[10][6] = 'R';
		gameObject->map.mapPiezes[10][7] = 'I'; gameObject->map.mapPiezes[10][8] = 'S';
		gameObject->map.mapPiezes[11][3] = 'T'; gameObject->map.mapPiezes[11][4] = 'E'; gameObject->map.mapPiezes[11][5] = 'T'; gameObject->map.mapPiezes[11][6] = 'R';
		gameObject->map.mapPiezes[11][7] = 'I'; gameObject->map.mapPiezes[11][8] = 'S';
		gameObject->map.mapPiezes[12][3] = 'T'; gameObject->map.mapPiezes[12][4] = 'E'; gameObject->map.mapPiezes[12][5] = 'T'; gameObject->map.mapPiezes[12][6] = 'R';
		gameObject->map.mapPiezes[12][7] = 'I'; gameObject->map.mapPiezes[12][8] = 'S';
		gameObject->map.mapPiezes[13][3] = 'T'; gameObject->map.mapPiezes[13][4] = 'E'; gameObject->map.mapPiezes[13][5] = 'T'; gameObject->map.mapPiezes[13][6] = 'R';
		gameObject->map.mapPiezes[13][7] = 'I'; gameObject->map.mapPiezes[13][8] = 'S'; gameObject->Score += 1600;
	}
	gameObject->comboCounter = 0;
}

void												update													(SGame* gameObject, float fLastFrameTime) {
	float																fSpeed														= GetAsyncKeyState(VK_DOWN) ? gameObject->pieze.Speed*5.0f : gameObject->pieze.Speed;
	::ftwlib::SCoord2<float>											* playerDeltas												= &gameObject->pieze.PositionDeltas;

	
	if(GetAsyncKeyState(VK_LEFT) && gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x-1] == TILE_VOID && gameObject->map.mapTiles[gameObject->parts[0].y][gameObject->parts[0].x-1] == TILE_VOID
	&&								gameObject->map.mapTiles[gameObject->parts[1].y]	[gameObject->parts[1].x-1] == TILE_VOID	&& gameObject->map.mapTiles[gameObject->parts[2].y][gameObject->parts[2].x-1] == TILE_VOID)
		gameObject->pieze.Axis.x--;
	
	else if(GetAsyncKeyState(VK_RIGHT) && gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x+1] == TILE_VOID 
	&& gameObject->map.mapTiles[gameObject->parts[0].y][gameObject->parts[0].x+1] == TILE_VOID && gameObject->map.mapTiles[gameObject->parts[1].y][gameObject->parts[1].x+1] == TILE_VOID
	&& gameObject->map.mapTiles[gameObject->parts[2].y][gameObject->parts[2].x+1] == TILE_VOID) {
		gameObject->pieze.Axis.x++;
	}
	if(GetAsyncKeyState(VK_SPACE)) {
		int futureY		= gameObject->pieze.Axis.y;		int futureX		= gameObject->pieze.Axis.x;
		int futureYuno	= gameObject->parts[0].y;		int futureXuno	= gameObject->parts[0].x;
		int futureYdos	= gameObject->parts[1].y;		int futureXdos	= gameObject->parts[1].x;
		int futureYtres	= gameObject->parts[2].y;		int futureXtres	= gameObject->parts[2].x;
		while(true) {
			if(gameObject->map.mapTiles[futureY+1][futureX] == TILE_VOID && gameObject->map.mapTiles[futureYuno+1][futureXuno] == TILE_VOID && gameObject->map.mapTiles[futureYdos+1][futureXdos] == TILE_VOID
				&& gameObject->map.mapTiles[futureYtres+1][futureXtres] == TILE_VOID) {
				futureY++;				futureYuno++;				futureYdos++;				futureYtres++;
			}
			else {
				gameObject->pieze.Axis.y = futureY;
				//gameObject->parts[0].y = futureYuno;
				//gameObject->parts[1].y = futureYdos;
				//gameObject->parts[2].y = futureYtres;
				break;
			}
		}
	}
	if(GetAsyncKeyState(VK_NUMPAD1)) {
		if(gameObject->pieze.Type == BARRA) {
			if(gameObject->map.mapTiles[gameObject->pieze.Axis.y+1][gameObject->pieze.Axis.x+1]	== TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y+1][gameObject->pieze.Axis.x]		== TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x+1]	== TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x-1]	== TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x-2]	== TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x]		== TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y-2][gameObject->pieze.Axis.x]		== TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x-1]	== TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y-2][gameObject->pieze.Axis.x-1]	== TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x-2]	== TILE_VOID) {
				if(gameObject->pieze.Direction == UP)								gameObject->pieze.Direction									= LEFT;
				else if(gameObject->pieze.Direction == LEFT)						gameObject->pieze.Direction									= DOWN;
				else if(gameObject->pieze.Direction == DOWN)						gameObject->pieze.Direction									= RIGHT;
				else																gameObject->pieze.Direction									= UP;
			}
		}
		else {
			if(gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x-1] == TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x] == TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x+1] == TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x-1] == TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x+1] == TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y+1][gameObject->pieze.Axis.x-1] == TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y+1][gameObject->pieze.Axis.x] == TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y+1][gameObject->pieze.Axis.x+1] == TILE_VOID) {
				if		(gameObject->pieze.Direction == UP)							gameObject->pieze.Direction									= LEFT;
				else if (gameObject->pieze.Direction == LEFT)						gameObject->pieze.Direction									= DOWN;
				else if (gameObject->pieze.Direction == DOWN)						gameObject->pieze.Direction									= RIGHT;
				else																gameObject->pieze.Direction									= UP;
			}
		}
	}
	else if(GetAsyncKeyState(VK_NUMPAD2) || GetAsyncKeyState(VK_UP)) {
		if(gameObject->pieze.Type == BARRA) {
			if(gameObject->map.mapTiles[gameObject->pieze.Axis.y+1][gameObject->pieze.Axis.x+1]	== TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y+1][gameObject->pieze.Axis.x]		== TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x+1]	== TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x-1]	== TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x-2]	== TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x]		== TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y-2][gameObject->pieze.Axis.x]		== TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x-1]	== TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y-2][gameObject->pieze.Axis.x-1]	== TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x-2]	== TILE_VOID) {
				if(gameObject->pieze.Direction == UP)								gameObject->pieze.Direction									= RIGHT;
				else if(gameObject->pieze.Direction == LEFT)						gameObject->pieze.Direction									= UP;
				else if(gameObject->pieze.Direction == DOWN)						gameObject->pieze.Direction									= LEFT;
				else																gameObject->pieze.Direction									= DOWN;
			}
		}
		else {
			if(gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x-1] == TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x] == TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x+1] == TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x-1] == TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x+1] == TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y+1][gameObject->pieze.Axis.x-1] == TILE_VOID
			&& gameObject->map.mapTiles[gameObject->pieze.Axis.y+1][gameObject->pieze.Axis.x] == TILE_VOID && gameObject->map.mapTiles[gameObject->pieze.Axis.y+1][gameObject->pieze.Axis.x+1] == TILE_VOID) {
				if(gameObject->pieze.Direction == UP)								gameObject->pieze.Direction									= RIGHT;
				else if(gameObject->pieze.Direction == LEFT)						gameObject->pieze.Direction									= UP;
				else if(gameObject->pieze.Direction == DOWN)						gameObject->pieze.Direction									= LEFT;
				else																gameObject->pieze.Direction									= DOWN;
			}
		}
	}

	playerDeltas->y			+=	fSpeed*fLastFrameTime;
	refreshPosFromDeltas( &gameObject->pieze );
	setParts(gameObject);
	
	if( gameObject->map.mapTiles[gameObject->pieze.Axis.y][gameObject->pieze.Axis.x] != TILE_VOID || gameObject->map.mapTiles[gameObject->parts[0].y][gameObject->parts[0].x] != TILE_VOID
	|| gameObject->map.mapTiles[gameObject->parts[1].y][gameObject->parts[1].x] != TILE_VOID || gameObject->map.mapTiles[gameObject->parts[2].y][gameObject->parts[2].x] != TILE_VOID )		{
		gameObject->map.mapTiles[gameObject->pieze.Axis.y-1][gameObject->pieze.Axis.x] = TILE_BLOCK;
		for(int p = 0; p < 3; p++)
			gameObject->map.mapTiles[gameObject->parts[p].y-1][gameObject->parts[p].x] = TILE_BLOCK;
		getNewPieze(gameObject);
	}

	for(uint32_t y=0; y < (uint32_t)AXIS_Y; y++)
		memset(gameObject->map.mapPiezes[y], INVALID_PIEZE, AXIS_X);

	for(int i=0; i < 3; i++) {
		if(gameObject->parts[i].y >= 0)
			gameObject->map.mapPiezes[gameObject->parts[i].y][gameObject->parts[i].x] = gameObject->pieze.Image;
	}
	
	for(int y = AXIS_Y-2; y>0; y--) {
		int xCheck = 1;
		
		while(true) {
			if(gameObject->map.mapTiles[y][xCheck] == TILE_VOID)
				break;
			if(xCheck == AXIS_X-1) {
				gameObject->Lines++;
				gameObject->levelLines++;
				gameObject->comboCounter++;
				for(int x=1; x < AXIS_X-1; x++) {
					gameObject->map.mapTiles[y][x] = TILE_VOID;
				}
				for(int anotherY = y; anotherY > 0; anotherY--) {
					for(int anotherX = 0; anotherX < AXIS_X-1; anotherX++) {
						if(gameObject->map.mapTiles[anotherY][anotherX] == TILE_BLOCK) {
							gameObject->map.mapTiles[anotherY][anotherX] = TILE_VOID;
							gameObject->map.mapTiles[anotherY+1][anotherX] = TILE_BLOCK;
						}
					}
				}
				++y;
			}
			xCheck++;
		}
	}
	if(gameObject->comboCounter > 0)		bonus(gameObject);
	if(gameObject->levelLines >= gameObject->gameLevel * 3) {
		gameObject->gameLevel++;
		gameObject->levelLines = 0;
		//gameObject->pieze.Speed = 0.4f * gameObject->gameLevel;
	}
	gameObject->pieze.Speed += 0.002f;
}
