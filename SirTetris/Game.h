#pragma once
#include "Coord.h"
#include <vector>

#define																AXIS_Y							22
#define																AXIS_X							12

#define																TILE_VOID						0
#define																TILE_BLOCK						219
#define																TILE_HORIZONTAL					205
#define																TILE_VERTICAL					186
#define																TILE_DOWN_LEFT					200
#define																TILE_DOWN_RIGHT					188

#define																INVALID_PIEZE					-1

struct																SMap {
	unsigned char																						mapTiles[AXIS_Y][AXIS_X];
	char																								mapPiezes[AXIS_Y][AXIS_X];
};
enum																TYPE_PIEZE {
																										BARRA,
																										L_IZQUIERDA,
																										L_DERECHA,
																										SQUARE,
																										ESCALERITA_IZQUIERDA,
																										ESCALERITA_DERECHA,
																										PODIO
};
enum																DIRECTION {
																										UP,
																										LEFT,
																										DOWN,
																										RIGHT
};
struct																SPieze {
	::ftwlib::SCoord2<int>																				Axis;
	::ftwlib::SCoord2<float>																			PositionDeltas;
	unsigned char																						Image;
	float																								Speed;
	TYPE_PIEZE																							Type;
	DIRECTION																							Direction;
};
struct																SGame {
	SMap																								map;
	SPieze																								pieze;
	::ftwlib::SCoord2<int>																				parts[3];
	TYPE_PIEZE																							nextPieze;
	int																									gameLevel;
	int																									Lines;
	int																									levelLines;
	int																									Score;
	int																									comboCounter;
};
const unsigned char													typeBarra[4][4]					=	{0, 0, 0, 0
																										,178, 178, 178, 178
																										,0, 0, 0, 0
																										,0, 0, 0, 0};
void																setup							(SGame* gameObject);
void																draw							(SGame* gameObject);
void																update							(SGame* gameObject, float fLastFrameTime);
void																getNewPieze						(SGame* gameObject);
void																randomPieze						(SGame* gameObject);