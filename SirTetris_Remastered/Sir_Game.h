#pragma once

#include "Sir_Coord.h"
#include "Pieze_Description.h"

#define															SCREEN_SIZE_Y										27
#define															SCREEN_SIZE_X										90
#define															MAP_SIZE_Y											22
#define															MAP_SIZE_X											17

#define															TILE_VOID											0
#define															TILE_DOWN_LEFT										200
#define															TILE_UP_LEFT										201
#define															TILE_UP_RIGHT										187
#define															TILE_DOWN_RIGHT										188
#define															TILE_VERTICAL										186
#define															TILE_HORIZONTAL										205
#define															TILE_BLOCK											219


enum															PIEZE_TYPE {
																								BARRA	,
																								ELE		,
																								ELE_INV	,
																								SQUARE	,
																								DOS		,
																								ESE		,
																								PODIO
};
enum															PIEZE_DIRECTION {
																								BARRA_H			,
																								BARRA_V			,
																								DOS_H			,
																								DOS_V			,
																								ESE_H			,
																								ESE_V			,
																								ELE_UP			,
																								ELE_LEFT		,
																								ELE_DOWN		,
																								ELE_RIGHT		,
																								ELE_INV_UP		,
																								ELE_INV_LEFT	,
																								ELE_INV_DOWN	,
																								ELE_INV_RIGHT	,
																								PODIO_UP		,
																								PODIO_LEFT		,
																								PODIO_DOWN		,
																								PODIO_RIGHT		,
																								SQUARE_O
};
enum															SCREEN_MODE {
																								SCREEN_TITLE		,
																								SCREEN_MENU			,
																								SCREEN_ONE_PLAYER	,
																								SCREEN_TWO_PLAYERS
};
struct															SMap {
	unsigned char																				screen[SCREEN_SIZE_Y][SCREEN_SIZE_X];
	unsigned char																				mapOne[MAP_SIZE_Y][MAP_SIZE_X];
	unsigned char																				mapTwo[MAP_SIZE_Y][MAP_SIZE_X];
};
struct															SPlayer {
	unsigned char																				realPieze[PIEZE_SIZE][PIEZE_SIZE];
	PIEZE_TYPE																					nextPieze;
	PIEZE_DIRECTION																				currentPieze;
	::ftwlib::SCoord2<int>																		axis;
	::ftwlib::SCoord2<float>																	positionDeltas;
	float																						speed;
	unsigned int																				score;
	unsigned int																				power;
	bool																						animation = false;
};
struct															SGame {
	SMap																						Map;
	SCREEN_MODE																					ScreenMode;
	SPlayer																						PlayerOne;
	SPlayer																						PlayerTwo;
};

void																getRandomPieze											(SPlayer* player);
void																getNewPieze												(SPlayer* player);
void																setupThings												(SGame* gameObject);
void																setupMapOne												(SGame* gameObject);
void																setupMapTwo												(SGame* gameObject);
void																setupPlayerOne											(SGame* gameObject);
void																setupPlayerTwo											(SGame* gameObject);
void																updateTitle												(SGame* gameObject);
void																updateMenu												(SGame* gameObject);
void																updatePlayerOne											(SGame* gameObject, float fLastFrameTime);
void																updatePlayerTwo											(SGame* gameObject, float fLastFrameTime);
void																draw													(SGame* gameObject);