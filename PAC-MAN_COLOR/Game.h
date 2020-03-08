#pragma once

#include "Coord.h"

#include <vector>
#include <string>

#define														AXIS_Y						22
#define														AXIS_X						27
#define														INVALID_ENEMY				0xFF
#define														TILE_VOID					0
#define														TILE_FOOD					250
#define														TILE_ENERGYZER				15

enum														DIRECTION {
																						UP		,
																						DOWN	,
																						LEFT	,
																						RIGHT
};

enum														MODE {
																						MODE_SCATTER		,
																						MODE_CHASE			,
																						MODE_FRIGHTENED
};

enum														GHOST {
																						BLINKY	,
																						PINKY	,
																						INKY	,
																						CLYDE	,
																						GHOST_COUNT
};

struct														STile {
	unsigned char																		Image;
	unsigned char																		Code;
	::std::string																		Name;
	bool																				Solid;
	//color
};

struct														SMap {
	::ftwlib::SCoord2<int32_t>															Size;
	unsigned char																		TilesMap		[AXIS_Y][AXIS_X];
	unsigned char																		TilesEnemy		[AXIS_Y][AXIS_X];
	bool																				TilesDecision	[AXIS_Y][AXIS_X];
	bool																				TilesSolid		[AXIS_Y][AXIS_X];
};

struct														SAnimatedObject {
	//Color
	DIRECTION																			CurrentDirection;
	::ftwlib::SCoord2<int32_t>															Position;
	unsigned char																		Image;
	float																				Speed;
	::ftwlib::SCoord2<float>															PositionDeltas;
};

struct														SEnemy : public SAnimatedObject {
	GHOST																				CurrentGhost;
	MODE																				CurrentMode;
	::ftwlib::SCoord2<int32_t>															TargetTile;
	bool																				Vulnerability;
	bool																				InHouse;
	unsigned char																		ClosestTarget;
};

struct														SGame {
	SMap																				Map;
	SAnimatedObject																		Player;
	std::vector<SEnemy>																	Enemies;

	unsigned int																		Score = 0;
	unsigned int																		CounterFood = 0;
	unsigned int																		CounterScatter = 0;
	unsigned int																		CounterChase = 0;
	unsigned int																		CounterFrightened = 0;
};

void																					updatePlayer													(SGame* gameObject, float fLastFrameTime);
void																					updateEnemies													(SGame* gameObject, float fLastFrameTime);

void																					setupMap														(SGame* gameObject);
void																					setupPlayer														(SGame* gameObject);
void																					setupEnemies													(SGame* gameObject);

void																					draw															(SGame* gameObject);