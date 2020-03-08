#include "Game.h"

void	setupMap		( SGame* gameObject ) {
	for( int y=0; y<AXIS_Y; ++y ) {
		for( int x=0; x<AXIS_X; ++x ) {
			gameObject->Map.MapTiles[y][x]		= TILE_VOID;
			gameObject->Map.EnemyTiles[y][x]	= INVALID_ENEMY;
			gameObject->Map.ShotTiles[y][x]		= INVALID_SHOT;
		}
	}
}
void setupWeapons		( SGame* gameObject) {
	gameObject->Player.Weapon[0].owned	=	true;
	gameObject->Player.Weapon[0].icon	=	1;
	gameObject->Player.Weapon[0].type	=	WEAPON_DEFAULT;

	gameObject->Player.Weapon[1].owned		=	true;
	gameObject->Player.Weapon[1].icon		=	2;
	gameObject->Player.Weapon[1].type	=	WEAPON_ONE;

	gameObject->Player.Weapon[2].owned		=	true;
	gameObject->Player.Weapon[2].icon		=	3;
	gameObject->Player.Weapon[2].type	=	WEAPON_TWO;
}
void	setupPlayer		( SGame* gameObject ) {
	gameObject->Player.y						=	AXIS_Y/2;
	gameObject->Player.x						=	1;
	gameObject->Player.icon						=	149;
	gameObject->Player.HP						=	10;
	gameObject->Player.Direction				=	0.0f;
	gameObject->Player.Speed					=	5.5f;
	gameObject->Player.PositionDeltas			=	{0,0};
	gameObject->Player.Action					=	ACTION_STAND;
	gameObject->Player.ActiveWeapon				=	WEAPON_DEFAULT;
	setupWeapons( gameObject );
}
