#include "map.h"

#include<windows.h>
#include<stdio.h>

#define AXIS_X		16
#define AXIS_Y		16
#define TILE_VOID	0

template <size_t axis_x, size_t axis_y>
void setup( SMapEditor<axis_x, axis_y>* gameObject ) {
	gameObject->Cursor.x = 0; 
	gameObject->Cursor.y = 0;
	gameObject->Cursor.image = 1;
	for( int y=0; y<axis_y; y++ )
		for( int x=0; x<axis_x; x++ )
			gameObject->mapTiles[y][x] = TILE_VOID;
}

template <size_t axis_x, size_t axis_y>
void update( SMapEditor<axis_x, axis_y>* gameObject ) {
	if( GetAsyncKeyState(VK_LEFT) ) {
		if( gameObject->Cursor.x == 0 )
			gameObject->Cursor.x = axis_x-1;
		else
			gameObject->Cursor.x--;
	}
	else if( GetAsyncKeyState(VK_RIGHT) ) {
		if( gameObject->Cursor.x == axis_x-1 )
			gameObject->Cursor.x = 0;
		else
			gameObject->Cursor.x++;
	}
	else if( GetAsyncKeyState(VK_UP) ) {
		if( gameObject->Cursor.y == 0 )
			gameObject->Cursor.y = axis_y-1;
		else
			gameObject->Cursor.y--;
	}
	else if( GetAsyncKeyState(VK_DOWN) ) {
		if( gameObject->Cursor.y == axis_y-1 )
			gameObject->Cursor.y = 0;
		else
			gameObject->Cursor.y++;
	}
	if( GetAsyncKeyState(VK_RCONTROL) ) {
		if( gameObject->Cursor.image == 255 )
			gameObject->Cursor.image = 0;
		else
			gameObject->Cursor.image++;
	}
	else if( GetAsyncKeyState(VK_LCONTROL) ) {
		if( gameObject->Cursor.image == 0 )
			gameObject->Cursor.image = 255;
		else
			gameObject->Cursor.image--;
	}
	if( GetAsyncKeyState(VK_SPACE) )
		gameObject->mapTiles[gameObject->Cursor.y][gameObject->Cursor.x] = gameObject->Cursor.image;
}

template <size_t axis_x, size_t axis_y>
void draw( SMapEditor<axis_x, axis_y>* gameObject ) {
	printf("%i\n\n", gameObject->Cursor.image);
	char imageMap[4096]={};
	int imageCursor = 0;
	for( int y=0; y < axis_y; y++ ) {
		for( int x=0; x < axis_x; x++ ) {
			if( gameObject->Cursor.x == x && gameObject->Cursor.y == y )
				imageMap[imageCursor++]					=					(char)gameObject->Cursor.image;
			else
				imageMap[imageCursor++]					=					(char)(gameObject->mapTiles[y][x] ? gameObject->mapTiles[y][x] : ' ');
		}
		imageMap[imageCursor++]	=	'\n';
	}
	imageMap[imageCursor]	=	0;
	printf("%s", imageMap);
}


int main() {

	SMapEditor<80, 25> editorInstance;

	setup( &editorInstance );

	while( true ) {
		update( &editorInstance );
		draw( &editorInstance );
		if( GetAsyncKeyState(VK_ESCAPE) )
			break;
		Sleep(100);
	}
	return 0;
}