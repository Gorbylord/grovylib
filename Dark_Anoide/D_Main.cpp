#include "D_Game.h"
#include <Windows.h>

void												setup								( SGame* gameObject ) {
	setupMap(gameObject);
	setupMotherShip(gameObject);
	setupBall(gameObject);
}

int													main() {
	SGame												gameInstance;
	setup(&gameInstance);
	while(true) {
		draw(&gameInstance);
		if(GetAsyncKeyState(VK_ESCAPE))
			break;
		Sleep(100);
	}
	return 0;
}