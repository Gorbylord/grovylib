#pragma once
#include "D_Coord.h"
#include <vector>

#define												GAME_PI								3.141592653589793238462643383279
#define												GAME_2PI							(2*GAME_PI)
#define												GAME_EPSILON						0.00001f


#define												AXIS_Y								23
#define												AXIS_X								45
#define												TILE_VOID							0
#define												INVALID_BALL						-1
#define												TILE_HORIZONTAL						205
#define												TILE_VERTICAL						186
#define												TILE_UP_LEFT						201
#define												TILE_UP_RIGHT						187
struct												SAnimatedObject {
	::ftwlib::SCoord2<int>																position;
	::ftwlib::SCoord2<float>															positionDeltas;
	float																				speed;
	unsigned char																		image;
};

struct												SBall : public	SAnimatedObject {
	float																				direction;
};

struct												SMap {
	unsigned char																		mapTiles[AXIS_Y][AXIS_X];
	char																				mapBalls[AXIS_Y][AXIS_X];
};

struct												SGame {
	std::vector<SBall>																	Balls;
	SAnimatedObject																		MotherShip;
	SMap																				Map;
};

void												setupMap							( SGame* gameObject );
void												setupMotherShip						( SGame* gameObject );
void												setupBall							( SGame* gameObject );
void												draw								( SGame* gameObject );