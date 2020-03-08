#include "Game.h"
#include "Timer.h"

#include <Windows.h>

int main () {
	SGame								gameInstance;
	::ftwlib::STimer					timer;
									setup(&gameInstance);

	while(true) {
		timer.Frame();
		update(&gameInstance, timer.LastTimeSeconds);
		draw(&gameInstance);
		if(GetAsyncKeyState(VK_ESCAPE))
			break;
		Sleep(125);
	}
	return 0;
}