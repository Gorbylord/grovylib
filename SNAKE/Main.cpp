#include<windows.h>
#include<stdio.h>
#include<vector>

#define AXIS_Y			20
#define AXIS_X			40

#define TILE_FLOOR		0
#define TILE_WALL		1
#define TILE_SEGMENT	2
#define INVALID_SEGMENT -1

struct SMap {
	int MapTiles[AXIS_Y][AXIS_X],
		segmentTiles[AXIS_Y][AXIS_X];
};
struct SCharacter {
	int x		,
		y		,
		icon	,
		direction
				;
};
struct SGame {
	SMap						Map		;
	SCharacter					Player	;
	std::vector<SCharacter>		Segment	;
	bool						Tail	;
	int							Lives	,
								GameLvl	,
								Score
										;
};

void setupMap( SGame* gameObject ) {
	for( int y=0; y<AXIS_Y; y++) {
		for( int x=0; x<AXIS_X; x++){
			gameObject->Map.MapTiles[y][x]					= TILE_FLOOR;
			gameObject->Map.segmentTiles[y][x]				= INVALID_SEGMENT;
		}
	}
	for( int y=0; y<AXIS_Y; y++) {
		gameObject->Map.MapTiles[y][0]						= TILE_WALL;
		gameObject->Map.MapTiles[y][AXIS_X-1]				= TILE_WALL;
	}
	for( int x=0; x<AXIS_X; x++) {
		gameObject->Map.MapTiles[0][x]						= TILE_WALL;
		gameObject->Map.MapTiles[AXIS_Y-1][x]				= TILE_WALL;
	}
	gameObject->Map.MapTiles[10][0]							= TILE_FLOOR;
	gameObject->Map.MapTiles[10][39]						= TILE_FLOOR;
	gameObject->Map.MapTiles[0][20]							= TILE_FLOOR;
	gameObject->Map.MapTiles[19][20]						= TILE_FLOOR;

	gameObject->Map.MapTiles[(rand()%18)+1][(rand()%38)+1]	= TILE_SEGMENT;
}
void draw( SGame* gameObject) {
	printf( "SCORE               LIVES\n%i                       %i\n\n", gameObject->Score, gameObject->Lives );
	char imageMap[4096]={};
	int cursor = 0;
	for( int y=0; y<AXIS_Y; y++) {
		for( int x=0; x<AXIS_X; x++) {
			if( gameObject->Player.x == x && gameObject->Player.y == y )
				imageMap[cursor++] = (char)gameObject->Player.icon;
			else if( gameObject->Map.segmentTiles[y][x] != INVALID_SEGMENT )
				imageMap[cursor++] = (char)gameObject->Map.segmentTiles[y][x];
			else
				imageMap[cursor++] = (char)(gameObject->Map.MapTiles[y][x] ? gameObject->Map.MapTiles[y][x]:' ');
		}
		imageMap[cursor++] = '\n';
	}
	imageMap[cursor] = 0;
	printf("%s", imageMap);
}
void moveInDirection ( SCharacter* someCharacter ) {
	if	   ( someCharacter->direction == 0 )	someCharacter->x++;
	else if( someCharacter->direction == 1 )	someCharacter->x--;
	else if( someCharacter->direction == 2 )	someCharacter->y--;
	else if( someCharacter->direction == 3 )	someCharacter->y++;
}
void resetSegment( SGame* gameObject ) {
	std::vector<SCharacter>::iterator iSegment = gameObject->Segment.begin();
	while( iSegment != gameObject->Segment.end() ) {
		//SCharacter* currentSegment = &gameObject->Segment[0];
		iSegment = gameObject->Segment.erase(iSegment);
		continue;
	}
}
void updateSegment( SGame* gameObject ) {
	for( int y=0; y<AXIS_Y; y++ )
		memset(gameObject->Map.segmentTiles[y], INVALID_SEGMENT, sizeof(int)*AXIS_X );
	std::vector<SCharacter>::iterator iSegment = gameObject->Segment.end();
	int index = (int)gameObject->Segment.size()-1;
	while( iSegment != gameObject->Segment.begin() ) {
		SCharacter* currentSegment = &gameObject->Segment[index];
		moveInDirection( currentSegment );
		if( index != 0 )
			currentSegment->direction = gameObject->Segment[index-1].direction;
		else
			currentSegment->direction = gameObject->Player.direction;
		gameObject->Map.segmentTiles[currentSegment->y][currentSegment->x] = currentSegment->icon;
		if( currentSegment->x == 39 )
			currentSegment->x = 0;
		else if( currentSegment->x == 0 )
			currentSegment->x = 39;
	
		if( currentSegment->y == 19 )
			currentSegment->y = 0;
		else if( currentSegment->y == 0 )
			currentSegment->y = 19;
		index--;
		iSegment--;
	}
}
void getSegment( SGame* gameObject ) {
	SCharacter newSegment;
	newSegment.icon = 2;
	if( gameObject->Tail == false) {
		gameObject->Tail = true;
		newSegment.direction = gameObject->Player.direction;
		if( gameObject->Player.direction == 0 ) {
			newSegment.x = gameObject->Player.x-1;	newSegment.y = gameObject->Player.y;
		}
		else if( gameObject->Player.direction == 1 ) {
			newSegment.x = gameObject->Player.x+1;	newSegment.y = gameObject->Player.y;
		}
		else if( gameObject->Player.direction == 2 ) {
			newSegment.y = gameObject->Player.y+1;	newSegment.x = gameObject->Player.x;
		}
		else if( gameObject->Player.direction == 3 ) {
			newSegment.y = gameObject->Player.y-1;	newSegment.x = gameObject->Player.x;
		}
	}
	else {
		newSegment.direction = gameObject->Segment[gameObject->Segment.size()-1].direction;
		if( gameObject->Segment[gameObject->Segment.size()-1].direction == 0 ) {
			newSegment.x = gameObject->Segment[gameObject->Segment.size()-1].x-1;
			newSegment.y = gameObject->Segment[gameObject->Segment.size()-1].y;
		}
		else if( gameObject->Segment[gameObject->Segment.size()-1].direction == 1 ) {
			newSegment.x = gameObject->Segment[gameObject->Segment.size()-1].x+1;
			newSegment.y = gameObject->Segment[gameObject->Segment.size()-1].y;
		}
		else if( gameObject->Segment[gameObject->Segment.size()-1].direction == 2 ) {
			newSegment.x = gameObject->Segment[gameObject->Segment.size()-1].x;		
			newSegment.y = gameObject->Segment[gameObject->Segment.size()-1].y+1;
		}
		else if( gameObject->Segment[gameObject->Segment.size()-1].direction == 3 ) {
			newSegment.x = gameObject->Segment[gameObject->Segment.size()-1].x;		
			newSegment.y = gameObject->Segment[gameObject->Segment.size()-1].y-1;
		}
	}
	gameObject->Segment.push_back(newSegment);
	gameObject->Map.segmentTiles[newSegment.y][newSegment.x] = newSegment.icon;
}
void setupPlayer( SGame* gameObject ) {
	gameObject->Player.direction	= 2;
	gameObject->Player.icon		= 2;
	gameObject->Player.x		= 8;
	gameObject->Player.y		= 14;
}
void updatePlayer( SGame* gameObject ) {
	SCharacter	&player = gameObject->Player;
	SMap		&map	= gameObject->Map;
	if( map.MapTiles[player.y][player.x] == TILE_SEGMENT ) {
		map.MapTiles[player.y][player.x] = TILE_FLOOR;
		int	y	=(rand()%18)+1;
		int	x	=(rand()%38)+1;
		while( map.segmentTiles[y][x] != INVALID_SEGMENT ) {
			y	=(rand()%18)+1;
			x	=(rand()%38)+1;
		}
		map.MapTiles[y][x]	= TILE_SEGMENT;
		getSegment( gameObject );
		gameObject->Score += 50;
	}
	if( GetAsyncKeyState(VK_RIGHT)		&& player.direction != 1 )	player.direction = 0;
	else if( GetAsyncKeyState(VK_LEFT)  && player.direction != 0 )	player.direction = 1;
	else if( GetAsyncKeyState(VK_UP)	&& player.direction != 3 )	player.direction = 2;
	else if( GetAsyncKeyState(VK_DOWN)  && player.direction != 2 )	player.direction = 3;

	moveInDirection( &player );	
	
	if( player.x == 39 )
		player.x = 0;
	else if( player.x == 0 )
		player.x = 39;
	
	if( player.y == 19 )
		player.y = 0;
	else if( player.y == 0 )
		player.y = 19;

	if( map.MapTiles[player.y][player.x] == TILE_WALL || map.segmentTiles[player.y][player.x] != INVALID_SEGMENT ) {
		gameObject->Lives--;
		setupPlayer( gameObject );
		resetSegment( gameObject );
		gameObject->Tail = false;
	}
}
int main() {
	SGame gameInstance;
	gameInstance.Score		= 0;
	gameInstance.Lives		= 3;
	gameInstance.GameLvl	= 1;
	gameInstance.Tail		= false;
	setupMap( &gameInstance );
	setupPlayer( &gameInstance );
	while( gameInstance.Lives >= 0 ) {
		draw( &gameInstance );
		updatePlayer( &gameInstance );
		updateSegment( &gameInstance );
		
		if( GetAsyncKeyState(VK_ESCAPE) )
			break;
		Sleep(150);
	}
	return 0;
}
