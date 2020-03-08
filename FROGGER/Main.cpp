#include "grovylib.h"
#include "TimerPoint.h"
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <string>

#define AXIS_Y	20
#define AXIS_X	30
#define	INVALID_PLATAFORM	-1

struct STile {
	unsigned char						Image;
	unsigned char						Code;
	::std::string						Name;
};
static const STile tileDefinitions[] = 
	{	{' '		, '0', "VOID"					,}
	,	{205		, 'H', "HORIZONTAL"				,}
	,	{186		, 'V', "VERTICAL"				,}
	,	{200		, 'C', "CORNER_DOWN_LEFT"		,}
	,	{201		, 'D', "CORNER_UP_LEFT"			,}
	,	{187		, 'E', "CORNER_UP_RIGHT"		,}
	,	{188		, 'F', "CORNER_DOWN_RIGHT"		,}
	};
const ::std::string map0[AXIS_Y] =  
	{ "DHHHHHHHHHHHHHHHHHHHHHHHHHHHHE"
	, "V                            V"
	, "V                            V"
	, "                              "
	, "V                            V"
	, "                              "
	, "V                            V"
	, "                              "
	, "V                            V"
	, "                              "
	, "V                            V"
	, "                              "
	, "V                            V"
	, "                              "
	, "V                            V"
	, "                              "
	, "V                            V"
	, "                              "
	, "V                            V"
	, "CHHHHHHHHHHHHHHHHHHHHHHHHHHHHF"
	};
unsigned char getImageByCode(unsigned char code) {
	for (uint32_t iTile = 0; iTile < (uint32_t)::std::size(tileDefinitions); ++iTile)
		if (tileDefinitions[iTile].Code == code)
			return tileDefinitions[iTile].Image;
	return ' ';
}

struct SAnimatedObject {
	SCoord			coord;
	int				icon;
	SVector2D		PositionsDeltas;
	float			Speed;
};

struct SGame {
	SAnimatedObject Player;
	std::vector<SAnimatedObject> Plataforms;
	int		Map[AXIS_Y][AXIS_X]
		,	plataformTiles[AXIS_Y][AXIS_X]
		;
};

void			refreshPosFromDeltas						( SAnimatedObject* object ) {
	SVector2D*						charDeltas				= &object->PositionsDeltas;
	while( charDeltas->x >= 1.0f ) {
		object->coord.x													+= 1;
		charDeltas->x													-= 1.0f;	
	}
	while( charDeltas->x < 0.0f ) {
		object->coord.x													-= 1;
		charDeltas->x													+= 1.0f;
	}
	
	while( charDeltas->y >= 1.0f ) {
		object->coord.y													+= 1;
		charDeltas->y													-= 1.0f;
	}
while( charDeltas->y < 0.0f ) {
		object->coord.y													-= 1;
		charDeltas->y													+= 1.0f;
	}
}

void setupMap( SGame* gameObject ) {
	for(uint32_t y = 0; y <AXIS_Y; ++y) {
		for(uint32_t x = 0; x <AXIS_X; ++x) {
			gameObject->Map[y][x] = getImageByCode(map0[y][x]);
			gameObject->plataformTiles[y][x]	=	INVALID_PLATAFORM;
		}
	}
}
void setupPlayer( SGame* gameObject ) {
	gameObject->Player.coord.x				=	15;
	gameObject->Player.coord.y				=	AXIS_Y-2;
	gameObject->Player.icon					=	2;
	gameObject->Player.PositionsDeltas		=	{0,0};
	gameObject->Player.Speed				=	5.0f;
}
void updatePlayer( SGame* gameObject, float fLastFrameTime ) {
	SVector2D*			playerDeltas		= &gameObject->Player.PositionsDeltas;
	float				fSpeed				= gameObject->Player.Speed;
	if(GetAsyncKeyState(VK_UP))
		playerDeltas->y													-= fSpeed*fLastFrameTime; 
	if(GetAsyncKeyState(VK_DOWN))
		playerDeltas->y													+= fSpeed*fLastFrameTime; 
	if(GetAsyncKeyState(VK_RIGHT))
		playerDeltas->x													+= fSpeed*fLastFrameTime; 
	if(GetAsyncKeyState(VK_LEFT))
		playerDeltas->x													-= fSpeed*fLastFrameTime; 

	refreshPosFromDeltas( &gameObject->Player );
}
void setupPlataforms( SGame* gameObject ){
	float fSpeed = 0.5f;
	for( int y=AXIS_Y-3; y>2; y-=2 ) {
		for(int x=0; x<AXIS_X; x+=4) {
			SAnimatedObject newPlataform;
			newPlataform.coord.y			=	y;
			newPlataform.coord.x			=	x;
			newPlataform.PositionsDeltas	=	{0,0};
			newPlataform.Speed				=	fSpeed;
			newPlataform.icon				=	22;
			gameObject->Plataforms.push_back(newPlataform);
			gameObject->plataformTiles[y][x]	= newPlataform.icon;
		}
		fSpeed	+=	0.5f;
	}
}
void updatePlataforms( SGame* gameObject, float fLastFrameTime ) {
	for( int y=0; y<AXIS_Y; ++y )
		memset(gameObject->plataformTiles[y], INVALID_PLATAFORM, sizeof(int)*AXIS_X);
	for( int iPlataform=0; iPlataform<gameObject->Plataforms.size(); iPlataform++ ) {
		SAnimatedObject*		currentPlataform	=	&gameObject->Plataforms[iPlataform];
		SVector2D*				plataformDeltas	=	&currentPlataform->PositionsDeltas;
		float					fPlataformSpeed	=	currentPlataform->Speed;
		if(currentPlataform->coord.y == AXIS_Y-3 || currentPlataform->coord.y == AXIS_Y-7 ||currentPlataform->coord.y == AXIS_Y-11 || currentPlataform->coord.y == AXIS_Y-15) {
			plataformDeltas->x	+=	fPlataformSpeed*fLastFrameTime;
			if( currentPlataform->coord.x == AXIS_X-1 )
				currentPlataform->coord.x	=	0;
		}
		else {
			plataformDeltas->x	-=	fPlataformSpeed*fLastFrameTime;
			if(currentPlataform->coord.x == 0)
				currentPlataform->coord.x	=	AXIS_X-1;
		}
		refreshPosFromDeltas( currentPlataform );
		gameObject->plataformTiles[currentPlataform->coord.y][currentPlataform->coord.x]	=	currentPlataform->icon;
	}
}
void draw( SGame* gameObject ) {
	char imageMap[4096]={};		
	int cursor = 0;
	for(int32_t y=0; y < AXIS_Y; y++) {
		for(int32_t x=0; x < AXIS_X; x++) {
			if(gameObject->Player.coord.y == y && gameObject->Player.coord.x == x)
				imageMap[cursor++] = (char)gameObject->Player.icon;
			else if( gameObject->plataformTiles[y][x] != INVALID_PLATAFORM )
				imageMap[cursor++]	= (char)gameObject->plataformTiles[y][x];
			else
				imageMap[cursor++] = (char)gameObject->Map[y][x] ? (char)gameObject->Map[y][x]:' ';
		}
		imageMap[cursor++] = '\n';
	}
	imageMap[cursor++] = '\n';
	imageMap[cursor] = 0;
	printf("%s", imageMap);
}

int main() {
	SGame		gameInstance;
	STimer		timer;
	setupMap( &gameInstance );
	setupPlayer( &gameInstance );
	setupPlataforms( &gameInstance );
	while( true ) {
		timer.Frame();
		updatePlayer( &gameInstance, timer.LastTime );
		updatePlataforms( &gameInstance, timer.LastTime );
		draw( &gameInstance );
		if( GetAsyncKeyState(VK_ESCAPE) )
			break;
		Sleep(200);
	}
	return 0;
}