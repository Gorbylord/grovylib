#include "Game.h"
#include "Timer.h"
#include <Windows.h>
#include <stdio.h>

void setup( SGame* gameObject) {
	setupMap		( gameObject );
	setupPlayer		( gameObject );
}
void update( SGame* gameObject, float fLastFrameTime ) {
	updatePlayer( gameObject, fLastFrameTime );
	//updateShots( gameObject, fLastFrameTime );
}
int main() {
	SGame		gameInstance	= {};
	STimer		timer			= {};
	int			frameCounter	=	0;

	setup( &gameInstance );
	while( true ) {
		timer.Frame();
		printf("FRAMECOUNTER:%i           LAST FRAME:%f\n", frameCounter, timer.LastTime);
		update	( &gameInstance, timer.LastTime );
		draw	( &gameInstance );
		if(GetAsyncKeyState(VK_ESCAPE))
			break;
		Sleep(130);
		++frameCounter;
	}
	return 0;
}