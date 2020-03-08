#pragma once
#include "Point.h"		
#include <vector>		

#define AXIS_Y				22
#define AXIS_X				100   

#define TILE_VOID			0
#define TILE_STAR			1
#define TILE_STAR_TWO		2
#define TILE_STAR_THREE		3

#define INVALID_ENEMY		-1
#define INVALID_SHOT		-1

#define GAME_PI				3.141592653589793238462643383279
#define GAME_2PI			(2*GAME_PI)
#define GAME_EPSILON		0.00001f

enum WEAPON_TYPE {
		WEAPON_DEFAULT
	,	WEAPON_ONE
	,	WEAPON_TWO
	,	WEAPON_COUNT
};
enum ACTION_TYPE	
	{	ACTION_WALK	
	,	ACTION_STAND
	};
struct SWeapon {
	WEAPON_TYPE							type;
	unsigned char						icon;
	bool								owned;
};
struct SMap {
	unsigned char						MapTiles	[AXIS_Y][AXIS_X];
	short int							EnemyTiles	[AXIS_Y][AXIS_X]
	,									ShotTiles	[AXIS_Y][AXIS_X]
	;
};
struct SAnimatedObject {
	int									x
	,									y
	;
	unsigned char						icon;
	SVector2							PositionDeltas;
	float								Direction;
	float								Speed;
};
struct SPlayer : public SAnimatedObject {
	int									HP;
	ACTION_TYPE							Action;
	short int							ActiveWeapon;
	SWeapon								Weapon[WEAPON_COUNT];
};
struct SEnemy : public SAnimatedObject {
	int									HP;
	short int							index;
	short int							moveCounter;
};
struct SShot : public SAnimatedObject {
	int									damage;
	short int							index;
};
struct SGame {
	SMap								Map;
	SPlayer								Player;
	::std::vector<SEnemy>				Enemy;
	::std::vector<SShot>				Shot;
};

void	setupMap		( SGame* gameObject );
void	setupPlayer		( SGame* gameObject );
void	draw			( SGame* gameObject );
void	updatePlayer	( SGame* gameObject, float fLastFrameTime );
void	updateShots		( SGame* gameObject, float fLastFrameTime );