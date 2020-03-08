#include "Game.h"
#include "Timer.h"

#include <Windows.h>

void																Setup															(SGame* gameObject) {
	setupMap															(gameObject);
	setupPlayer															(gameObject);
	setupEnemies														(gameObject);
}
void																Update															(SGame* gameObject, float fLastFrameTime) {
	updatePlayer														(gameObject, fLastFrameTime);
	updateEnemies														(gameObject, fLastFrameTime);
}

int main() {
	SGame								gameInstance;
	::ftwlib::STimer					timer;
										Setup ( &gameInstance );
	
	while(	true ) {
		timer.Frame();
		Update( &gameInstance, timer.LastTimeSeconds);
		draw ( &gameInstance );
		Sleep(150);
		if(	GetAsyncKeyState(VK_ESCAPE)	)
			break;
	}
	return 0;
}