#include "Game.h"
#include <stdio.h>

void	draw	( SGame* gameObject ) {
	unsigned char	imageMap[4096]={};
	int		cursor		=	0;
	for( int y=0; y<AXIS_Y; y++ ) {
		for(int x=0; x<AXIS_X; x++ ) {
			if( gameObject->Player.x == x && gameObject->Player.y == y )
				imageMap[cursor++]	=	gameObject->Player.icon;
			else if( gameObject->Player.x-1 == x && gameObject->Player.y+1 == y )
				imageMap[cursor++]	=	218;
			else if( gameObject->Player.x == x && gameObject->Player.y+1 == y )
				imageMap[cursor++]	=	197;
			else if( gameObject->Player.x+1 == x && gameObject->Player.y+1 == y )
				imageMap[cursor++]	=	196;
			else if( gameObject->Player.x+2 == x && gameObject->Player.y+1 == y )
				imageMap[cursor++]	=	gameObject->Player.Weapon[gameObject->Player.ActiveWeapon].icon;
			else if( gameObject->Map.ShotTiles[y][x] != INVALID_SHOT )
				imageMap[cursor++]	=	gameObject->Map.ShotTiles[y][x];
			else
				imageMap[cursor++]	=	gameObject->Map.MapTiles[y][x] ? gameObject->Map.MapTiles[y][x] :' ';
		}
		imageMap[cursor++]	=	'\n';
	}
	imageMap[cursor]	=	0;
	printf( "%s", imageMap );
}