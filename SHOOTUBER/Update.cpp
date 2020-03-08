#include "Game.h"
#include <windows.h>

void					refreshPosFromDeltas						( SAnimatedObject* character ) {
	SVector2*				charDeltas			= &character->PositionDeltas;
	while( charDeltas->x >= 1.0f ) {
		character->x			+= 1;
		charDeltas->x			-= 1.0f;
	}
	while( charDeltas->x < 0.0f ) {
		character->x			-= 1;
		charDeltas->x			+= 1.0f;
	}
	while( charDeltas->y >= 1.0f ) {
		character->y			+= 1;
		charDeltas->y			-= 1.0f;
	}
	while( charDeltas->y < 0.0f ) {
		character->y			-= 1;
		charDeltas->y			+= 1.0f;
	}
}
void playerShot( SGame* gameObject, SPoint2 origin, float direction ) {
	
	if( gameObject->Player.Weapon[gameObject->Player.ActiveWeapon].type == WEAPON_DEFAULT ) {
		SShot		newShot;
		newShot.damage			=	1;
		newShot.Direction		=	direction;
		newShot.icon			=	46;
		newShot.index			=	0;
		newShot.PositionDeltas	=	origin;
		newShot.Speed			=	10.0f;
		newShot.x				=
		newShot.y				=	0;
		refreshPosFromDeltas( &newShot );
		gameObject->Shot.push_back( newShot );
	}
	else if( gameObject->Player.Weapon[gameObject->Player.ActiveWeapon].type == WEAPON_ONE ) {
		SShot		newShot;
		newShot.damage			=	1;
		newShot.Direction		=	direction;
		newShot.icon			=	63;
		newShot.index			=	0;
		newShot.PositionDeltas	=	origin;
		newShot.Speed			=	20.0f;
		newShot.x				=
		newShot.y				=	0;
		refreshPosFromDeltas( &newShot );
		gameObject->Shot.push_back( newShot );
	}
	else if( gameObject->Player.Weapon[gameObject->Player.ActiveWeapon].type == WEAPON_TWO ) {
		SShot		newShot;
		newShot.damage			=	1;
		newShot.Direction		=	direction;
		newShot.icon			=	111;
		newShot.index			=	0;
		newShot.PositionDeltas	=	origin;
		newShot.Speed			=	40.0f;
		newShot.x				=
		newShot.y				=	0;
		refreshPosFromDeltas( &newShot );
		gameObject->Shot.push_back( newShot );
	}
}
void updatePlayer ( SGame* gameObject, float fLastFrameTime ) {
	if( gameObject->Player.icon == 149 )
		gameObject->Player.icon = 162;
	else
		gameObject->Player.icon = 149;
	
	bool					_keyUp		= GetAsyncKeyState('W') ? true : false,
							_keyDown	= GetAsyncKeyState('S') ? true : false,
							_keyLeft	= GetAsyncKeyState('A') ? true : false,
							_keyRight	= GetAsyncKeyState('D') ? true : false,
							_keyShot	= GetAsyncKeyState('T') ? true : false;

	SVector2				dir	= {0,0};
	if( _keyRight && gameObject->Player.x < AXIS_X-1 )
		++dir.x;
	if( _keyLeft && gameObject->Player.x != 0 )
		--dir.x;
	if( _keyUp && gameObject->Player.y != 0 )
		--dir.y;
	if( _keyDown && gameObject->Player.y < AXIS_Y-1 )
		++dir.y;
	dir.Normalize();

	bool																	noKeysPressed						= !_keyRight && !_keyLeft && !_keyUp && !_keyDown;
	if( noKeysPressed )
		gameObject->Player.Action										= ACTION_STAND;
	else {																
		gameObject->Player.Action										= ACTION_WALK;
		gameObject->Player.Direction									= SVector2(1,0).AngleWith(dir);
		if( dir.y < 0 )
			gameObject->Player.Direction									*= -1; 
	}
	float																	fSpeed								= GetAsyncKeyState(VK_LSHIFT) ? gameObject->Player.Speed*1.5f : gameObject->Player.Speed;

	if( gameObject->Player.Action == ACTION_WALK ) {
		dir.Scale(fSpeed*fLastFrameTime);
		gameObject->Player.PositionDeltas									+= dir;
	}
	refreshPosFromDeltas( &gameObject->Player );

	if(_keyShot) {
		SVector2 origin								={gameObject->Player.x+gameObject->Player.PositionDeltas.x, gameObject->Player.y+gameObject->Player.PositionDeltas.y};
		playerShot(gameObject, origin, gameObject->Player.Direction);
	}

	if( GetAsyncKeyState('1') && gameObject->Player.Weapon[0].owned  == true )
		gameObject->Player.ActiveWeapon	=	0;
	if( GetAsyncKeyState('2') && gameObject->Player.Weapon[1].owned  == true )
		gameObject->Player.ActiveWeapon	=	1;
	if( GetAsyncKeyState('3') && gameObject->Player.Weapon[2].owned  == true )
		gameObject->Player.ActiveWeapon	=	2;
}

void																updateShots							( SGame* gameObject, float fLastFrameTime  )										{
	for( int y = 0; y < AXIS_Y; y++ ) 
		memset( gameObject->Map.ShotTiles[y], INVALID_SHOT, sizeof(int)*AXIS_X );
	std::vector<SShot>::iterator											iShot								= gameObject->Shot.begin();
	short 																	indexShot							= 0;
	while( iShot != gameObject->Shot.end() ) {
		SShot																	* currentShot						= &gameObject->Shot[indexShot]; 
		SVector2																* shotDeltas						= &currentShot->PositionDeltas;

		SVector2																dirVector							= SVector2(1, 0).Rotate( currentShot->Direction );
		shotDeltas->x														+= currentShot->Speed*fLastFrameTime*dirVector.x; 
		shotDeltas->y														+= currentShot->Speed*fLastFrameTime*dirVector.y; 

		refreshPosFromDeltas( currentShot );

		if( currentShot->x < 0 
		 || currentShot->y < 0 
		 || currentShot->x >= AXIS_X
		 || currentShot->y >= AXIS_Y
		 ) { 
			iShot																= gameObject->Shot.erase( iShot );
			continue;
		}
		gameObject->Map.ShotTiles[currentShot->y][currentShot->x]			= currentShot->icon;
		++iShot;
		++indexShot;
	}
}