#include "Sir_Game.h"
#include "Sir_timer.h"

#include <Windows.h>

void																update												(SGame* gameObject, float fLastFrameTime) {
	for(int y=0; y < SCREEN_SIZE_Y; y++) {
		for(int x=0; x < SCREEN_SIZE_X; x++) {
			gameObject->Map.screen[y][x] = TILE_VOID;
		}
	}
	if(gameObject->ScreenMode == SCREEN_TITLE)
		updateTitle(gameObject);
	else if(gameObject->ScreenMode == SCREEN_MENU)
		updateMenu(gameObject);
	else if(gameObject->ScreenMode == SCREEN_ONE_PLAYER)
		updatePlayerOne(gameObject, fLastFrameTime);
	else if(gameObject->ScreenMode == SCREEN_TWO_PLAYERS) {
		updatePlayerOne(gameObject, fLastFrameTime);
		updatePlayerTwo(gameObject, fLastFrameTime);
	}
}

int main () {
	SGame								gameInstance;
	::ftwlib::STimer					timer;
										setupThings(&gameInstance);

	while(true) {
		timer.Frame();
		
		update(&gameInstance, timer.LastTimeSeconds);
		draw(&gameInstance);
		if(GetAsyncKeyState(VK_ESCAPE)) {
			if(gameInstance.ScreenMode == SCREEN_ONE_PLAYER || gameInstance.ScreenMode == SCREEN_TWO_PLAYERS)
				gameInstance.ScreenMode = SCREEN_MENU;
			else
				break;
		}
		Sleep(125);
	}
	return 0;
}