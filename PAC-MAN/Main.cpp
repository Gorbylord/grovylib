#include "pacman.h"

#include<windows.h>
#include<stdio.h>
#include<vector>
#include<stdint.h>

static const STile tileDefinitions[] = 
	{	{' '		, '0', "VOID"					, false,	}
	,	{250		, 'P', "POINTS"					, false,	}
	,	{15			, 'W', "POWER_UP"				, false,	}
	,	{3			, 'X', "TARGET_FRUIT"			, false,	}
	,	{179		, '4', "VERTICAL_LINE"			, true,		}
	,	{200		, 'C', "CORNER_DOWN_LEFT"		, true,		}
	,	{201		, 'D', "CORNER_UP_LEFT"			, true,		}
	,	{187		, 'E', "CORNER_UP_RIGHT"		, true,		}
	,	{188		, 'F', "CORNER_DOWN_RIGHT"		, true,		}
	,	{203		, 'T', "T_DOWN"					, true,		}
	,	{202		, 'U', "T_UP"					, true,		}
	,	{204		, 'R', "T_RIGHT"				, true,		}
	,	{185		, 'L', "T_LEFT"					, true,		}
	,	{205		, 'H', "HORIZONTAL"				, true,		}
	,	{186		, 'V', "VERTICAL"				, true,		}
	};

unsigned char getImageByCode(unsigned char code) {
	for (uint32_t iTile = 0; iTile < (uint32_t)::std::size(tileDefinitions); ++iTile)
		if (tileDefinitions[iTile].Code == code)
			return tileDefinitions[iTile].Image;
	return ' ';
}

bool getSolidByImage(unsigned char image) {
	for (uint32_t iTile = 0; iTile < (uint32_t)::std::size(tileDefinitions); ++iTile)
		if (tileDefinitions[iTile].Image == image)
			return tileDefinitions[iTile].Solid;
	return true;
}

const ::std::string map0[AXIS_Y] =  
	{ "DHHHHHHHHE  V V  DHHHTTHHHE"
	, "VPPWPPPPPV  V V  VPPWVVPPPV"
	, "VPDHEPDEPV  V V  VPVPCFPVPV"
	, "VPV VPVVPV  V V  VPVPPPPVPV"
	, "VPCHFPCFPCHHF CHHFPCHHHPVPV"
	, "VPPPPPPPPPPPPPPPPPPPPPPPVPV"
	, "VPDHEPHHHTHHH HHHHPVPHHHLPV"
	, "VPV VPPPPV        PVPPPPVPV"
	, "VPCHFPDEPV DHHE DEPVPDEPVPV"
	, "VPPPPPVVP  4  V VVPPPVVPPPV"
	, "RHHHHPVRHH 4  V VRHH VRHHPV"
	, "VPPPPPVVP  4  V VVPPPVVPPPV"
	, "VPDHEPCFPV CHHF CFPVPCFPVPV"
	, "VPV VPPPPV        PVPPPPVPV"
	, "VPCHFPHHHUHHH HHHHPVPHHHLPV"
	, "VPPPPPPPPPPPPPPPPPPPPPPPVPV"
	, "VPDHEPDEPDHHE DHHEPDHHHPVPV"
	, "VPV VPVVPV  V V  VPVPPPPVPV"
	, "VPCHFPCFPV  V V  VPVPDEPVPV"
	, "VPPWPPPPPV  V V  VPPWVVPPPV"
	, "CHHHHHHHHF  V V  CHHHUUHHHF"
	, "                           "
	};


#define TILE_VOID				0
#define TILE_POINTS				250
#define TILE_POWER_UP			15
#define TILE_TARGET_FRUIT		3
#define TILE_VERTICAL_LINE		179
#define TILE_CORNER_DOWN_LEFT	200
#define TILE_CORNER_UP_LEFT		201
#define TILE_CORNER_UP_RIGHT	187
#define TILE_CORNER_DOWN_RIGHT	188
#define TILE_T_DOWN				203
#define TILE_T_UP				202
#define TILE_T_RIGHT			204
#define TILE_T_LEFT				185
#define TILE_HORIZONTAL			205
#define TILE_VERTICAL			186

void resetEnemy(	SCharacter* someEnemy	) {
	someEnemy->Position.x		= 12;	
	someEnemy->Position.y		= 10; 
	someEnemy->icono			= 2; 
	someEnemy->vulnerability	= false; 
	someEnemy->InHouse			= true;
}

void enemyBonus(	SGame* gameObject	) {
	gameObject->Player.score += (200*gameObject->CounterCombo); 
	gameObject->CounterCombo++;
}

void lifeLost(	SGame* gameObject	) {
	std::vector<SCharacter>::iterator iEnemy = gameObject->Enemy.begin();	int index = 0; 
	while(	iEnemy != gameObject->Enemy.end()	) {
		SCharacter* currentEnemy = &gameObject->Enemy[index];
		resetEnemy(	currentEnemy	);
		iEnemy++;	index++;
	}
	gameObject->Player.Position.x = 20; 
	gameObject->Player.Position.y = 10;	
	gameObject->Lives--;	
	gameObject->Player.direction = 3;
	gameObject->PowerUp = false;	gameObject->CounterFruit = 0;	gameObject->Map.maptiles[10][15] = TILE_VOID;
	printf("                 //////////////   //////////////   //////////////\n");
	printf("                 ///              ///                    //\n");
	printf("                 ///              ////////               //\n");
	printf("                 ///      /////   ///                    //\n");
	printf("                 ///        ///   ///                    //\n");
	printf("                 //////////////   //////////////         //\n\n");
	printf(" /////////////   //////////////   //////////////   ///////////      ///     ///\n");
	printf(" ///        ///  ///              //          //   ///      ////     ///   ///\n");
	printf(" ///       ///   ////////         //          //   ///        ///     /// ///\n");
	printf(" ///////////     ///              //////////////   ///        ///       ///\n");
	printf(" ///      ///    ///              //          //   ///      ////        ///\n");
	printf(" ///       ///   //////////////   //          //   ////////////         ///\n");
	Sleep(2000);
}
void setupEnemies(	SGame* gameObject	) {
	for(uint32_t enemyCount=0; enemyCount < gameObject->GameLvl; enemyCount++	) {
		SCharacter newEnemy;
		newEnemy.Position.x		= 12; 
		newEnemy.Position.y		= 10; 
		newEnemy.icono			= 2;	
		newEnemy.vulnerability	= false;
		newEnemy.InHouse		= true;
		gameObject->Map.enemyTiles[newEnemy.Position.y][newEnemy.Position.x] = newEnemy.icono;
		gameObject->Enemy.push_back(newEnemy);
	}
}
void updateEnemies(	SGame* gameObject	) {
	for(uint32_t y=0; y < (uint32_t)gameObject->Map.axis.y; y++	)
		memset(gameObject->Map.enemyTiles[y], INVALID_ENEMY, gameObject->Map.axis.x);
	std::vector<SCharacter>::iterator iEnemy = gameObject->Enemy.begin();		int index = 0; 
	while(iEnemy != gameObject->Enemy.end()) {
		SCharacter* currentEnemy = &gameObject->Enemy[index];
		if(currentEnemy->InHouse == true) {
			currentEnemy->direction = rand()%4;
			if(currentEnemy->direction == 1) {
				if(gameObject->Map.maptiles[currentEnemy->Position.y][currentEnemy->Position.x-1] == TILE_VERTICAL_LINE){
					currentEnemy->Position.x-=2; currentEnemy->InHouse = false; currentEnemy->direction = rand()%4;
				}
			}
		}
		if(	gameObject->CounterPower == 50	) {
			currentEnemy->icono = 2; currentEnemy->vulnerability = false;
		}
		if(	gameObject->CounterPower >= 29 && gameObject->CounterPower <= 49 && currentEnemy->vulnerability == true	) {
			if(	currentEnemy->icono == 2	)	
				currentEnemy->icono = 1;		
			else	
				currentEnemy->icono = 2;
		}
		if(	currentEnemy->Position.x == gameObject->Player.Position.x && currentEnemy->Position.y == gameObject->Player.Position.y	) {
			if(	currentEnemy->vulnerability == false	)	
				lifeLost(	gameObject	);
			else {	
				enemyBonus(	gameObject	);	
				resetEnemy(	currentEnemy	);	
			}
		}
		if(	currentEnemy->Position.y > 20	)	currentEnemy->Position.y = 0;
		
		if(	currentEnemy->direction == 0	) {
			if(	gameObject->Map.solidMap[currentEnemy->Position.y][currentEnemy->Position.x+1] != true	)
				currentEnemy->Position.x++;
			else	
				currentEnemy->direction = 2;
		}
		else if(	currentEnemy->direction == 1	) {
			if(	gameObject->Map.solidMap[currentEnemy->Position.y][currentEnemy->Position.x-1] != true	)
				currentEnemy->Position.x--;
			else
				currentEnemy->direction = 3;
		}
		else if(	currentEnemy->direction == 2	) {
			if( currentEnemy->Position.y-1 < 0 )
				currentEnemy->Position.y = 20;
			else if(	gameObject->Map.solidMap[currentEnemy->Position.y-1][currentEnemy->Position.x] != true	)
				currentEnemy->Position.y--;
			else
				currentEnemy->direction = 1;
		}
		else if(	currentEnemy->direction == 3	) {
			if(	gameObject->Map.solidMap[currentEnemy->Position.y+1][currentEnemy->Position.x] != true	)
				currentEnemy->Position.y++;
			else if(	gameObject->Map.solidMap[currentEnemy->Position.y][currentEnemy->Position.x+1] != true	)
				currentEnemy->Position.x++;
			else
				currentEnemy->Position.x--;
		}
		gameObject->Map.enemyTiles[currentEnemy->Position.y][currentEnemy->Position.x] = currentEnemy->icono;
		index	++;	
		iEnemy	++;
	}
}
void setupOtherMaps(	SGame* gameObject	) {
	for(uint32_t y=0; y < (uint32_t)gameObject->Map.axis.y; y++ ) {
		for(uint32_t x=0; x < (uint32_t)gameObject->Map.axis.x; x++	) {
			gameObject->Map.enemyTiles	[y][x] = (unsigned char)INVALID_ENEMY;
			gameObject->Map.solidMap	[y][x] = getSolidByImage(gameObject->Map.maptiles[y][x]);
		}
	}
}
void setupPlayer(	SGame* gameObject	) {
	gameObject->Player.Position.x	= 20;	
	gameObject->Player.Position.y	= 10;	
	gameObject->Player.direction	= 3;
	gameObject->Player.icono		= 67;
}
void updatePlayer(	SGame* gameObject	) {
	SCharacter		& player		= gameObject->Player;
	SMap			& map			= gameObject->Map;

	if(	player.Position.y > 20	)		player.Position.y = 0;
	
	if(	map.maptiles[player.Position.y][player.Position.x] == TILE_TARGET_FRUIT	) {
		map.maptiles[player.Position.y][player.Position.x] = TILE_VOID;
		player.score += 100;
	}
	if(	map.maptiles[player.Position.y][player.Position.x] == TILE_POINTS	) {
		player.score += 10; 
		gameObject->CounterPoints++;
		map.maptiles[player.Position.y][player.Position.x] = TILE_VOID;
	}
	int index = 0;
	std::vector<SCharacter>::iterator iEnemy = gameObject->Enemy.begin();
	while(	iEnemy != gameObject->Enemy.end()	) {
		SCharacter* currentEnemy = &gameObject->Enemy[index];
		if(	player.Position.x == currentEnemy->Position.x 
		 && player.Position.y == currentEnemy->Position.y	
		 ) {
			if(	currentEnemy->vulnerability == false	)
				lifeLost(	gameObject	);
			else {
				enemyBonus(	gameObject	);	
				resetEnemy(	currentEnemy	);	
			}
		}
		iEnemy	++;	
		index	++;
	}
	int Aindex = 0;			std::vector<SCharacter>::iterator AiEnemy = gameObject->Enemy.begin();
	if(	map.maptiles[player.Position.y][player.Position.x] == TILE_POWER_UP	) {
		map.maptiles[player.Position.y][player.Position.x] = TILE_VOID;
		gameObject->PowerUp = true; player.score += 50;	gameObject->CounterCombo = 1;
		while(	AiEnemy != gameObject->Enemy.end()	) {
			SCharacter							* currentEnemy			= &gameObject->Enemy[Aindex];
			currentEnemy->icono				= 1; 
			currentEnemy->vulnerability		= true;
			AiEnemy++;	
			Aindex++;
		}
		gameObject->CounterPower = 0;
	}			


	if(	GetAsyncKeyState(VK_RIGHT	)	&& map.solidMap[player.Position.y	][player.Position.x+1] != true	)	{ player.direction = 0; if(rand()%4)  for(uint32_t indexEnemy = 0, enemyCount = (uint32_t)gameObject->Enemy.size(); indexEnemy < enemyCount; ++indexEnemy) gameObject->Enemy[indexEnemy].direction = rand()%4;	}
	if(	GetAsyncKeyState(VK_LEFT	)	&& map.solidMap[player.Position.y	][player.Position.x-1] != true	)	{ player.direction = 1; if(rand()%8)  for(uint32_t indexEnemy = 0, enemyCount = (uint32_t)gameObject->Enemy.size(); indexEnemy < enemyCount; ++indexEnemy) gameObject->Enemy[indexEnemy].direction = rand()%4;	}
	if(	GetAsyncKeyState(VK_UP		)	&& map.solidMap[player.Position.y-1	][player.Position.x] != true	)	{ player.direction = 2; if(rand()%16) for(uint32_t indexEnemy = 0, enemyCount = (uint32_t)gameObject->Enemy.size(); indexEnemy < enemyCount; ++indexEnemy) gameObject->Enemy[indexEnemy].direction = rand()%4;	}
	if(	GetAsyncKeyState(VK_DOWN	)	&& map.solidMap[player.Position.y+1	][player.Position.x] != true	)	{ player.direction = 3; if(rand()%32) for(uint32_t indexEnemy = 0, enemyCount = (uint32_t)gameObject->Enemy.size(); indexEnemy < enemyCount; ++indexEnemy) gameObject->Enemy[indexEnemy].direction = rand()%4;	}
										
		 if( player.direction == 0 && map.solidMap[player.Position.y	][player.Position.x+1] != true	)	player.Position.x++;
	else if( player.direction == 1 && map.solidMap[player.Position.y	][player.Position.x-1] != true	)	player.Position.x--;
	else if( player.direction == 2 && player.Position.y-1 < 0 )												player.Position.y = 20;
	else if( player.direction == 2 && map.solidMap[player.Position.y-1	][player.Position.x] != true	)	player.Position.y--;
	else if( player.direction == 3 && map.solidMap[player.Position.y+1	][player.Position.x] != true	)	player.Position.y++;
	
	if(	player.icono == 79	)
		player.icono = 67;
	else
		player.icono = 79;
}
void setupMap(	SGame* gameObject	) {
	gameObject->Map.axis.y = AXIS_Y;	
	gameObject->Map.axis.x = AXIS_X;
	for(uint32_t y = 0; y < (uint32_t)gameObject->Map.axis.y; ++y)
		for(uint32_t x = 0; x < (uint32_t)gameObject->Map.axis.x; ++x)
			gameObject->Map.maptiles[y][x] = getImageByCode(map0[y][x]);
}
void draw(	SGame* gameObject	) {
	char imageMap[4096]={};		
	int cursor = 0;
	for(int32_t y=0; y < (int32_t)gameObject->Map.axis.y - 1; y++) {
		for(int32_t x=0; x < (int32_t)gameObject->Map.axis.x; x++) {
			if(gameObject->Player.Position.y == y && gameObject->Player.Position.x == x)
				imageMap[cursor++] = gameObject->Player.icono;
			else if(gameObject->Map.enemyTiles[y][x] != INVALID_ENEMY)
				imageMap[cursor++] = gameObject->Map.enemyTiles[y][x];
			else
				imageMap[cursor++] = gameObject->Map.maptiles[y][x] ? gameObject->Map.maptiles[y][x]:' ';
		}
		if(y == 1){
			::std::string	scoreLabel(" SCORE");
			memcpy_s(&imageMap[cursor], ::std::size(imageMap)-cursor, scoreLabel.c_str(), scoreLabel.size());
			cursor += (int)scoreLabel.size();
		}
		if(y == 10) {
			imageMap[cursor++] = ' ';
			imageMap[cursor++] = 4;
		}
		imageMap[cursor++] = '\n';
	}
	imageMap[cursor++] = '\n';
	imageMap[cursor] = 0;
	printf("%s", imageMap);
	printf("SCORE:%i		LIVES:%i\n\n", gameObject->Player.score, gameObject->Lives);
}

void newLevel(	SGame* gameObject	) {
	gameObject->GameLvl++;				
	gameObject->CounterPoints	=
	gameObject->CounterPower	=			
	gameObject->CounterFruit	=			
	gameObject->MaxFruit		= 0;
	gameObject->PowerUp			= false;
	gameObject->CounterSleep -= 10;		
	std::vector<SCharacter>::iterator iEnemy = gameObject->Enemy.end();
	while( gameObject->Enemy.size() ) {
		iEnemy = gameObject->Enemy.erase(iEnemy-1); 
		continue;
	}
	setupMap			( gameObject );
	setupEnemies		( gameObject );
	setupPlayer			( gameObject );
	printf("LEVEL: %i",	gameObject->GameLvl);
	Sleep(2000);
}

int main() {
	SGame gameInstance;
	gameInstance.CounterCombo			= 1;
	gameInstance.CounterSleep			= 150;
	gameInstance.Lives					= 3;
	gameInstance.GameLvl				= 1;

	setupMap		( &gameInstance );
	setupOtherMaps	( &gameInstance );
	setupEnemies	( &gameInstance );
	setupPlayer		( &gameInstance );

	while(	gameInstance.Lives >= 0	) {
		if(	gameInstance.CounterPoints == 188	) 
			newLevel(	&gameInstance	);
		gameInstance.CounterFruit++;
		if(	gameInstance.MaxFruit < 2	) { 
			if(	gameInstance.CounterFruit == 75	) {
				gameInstance.MaxFruit++;
				gameInstance.Map.maptiles[10][15] = TILE_TARGET_FRUIT;
			}
			if(	gameInstance.CounterFruit == 175	)
				gameInstance.CounterFruit = 0;
		}
		if(	gameInstance.CounterFruit == 125	) 
			gameInstance.Map.maptiles[10][15] = TILE_VOID;
		if(	gameInstance.PowerUp == true )
			gameInstance.CounterPower++;

		updatePlayer	( &gameInstance );
		updateEnemies	( &gameInstance );
		draw			( &gameInstance );
		if(	gameInstance.CounterPower == 50	) {
			gameInstance.CounterPower	= 0;	
			gameInstance.PowerUp		= false; 
			gameInstance.CounterCombo	= 1;
		}
		Sleep(gameInstance.CounterSleep);
		if(	GetAsyncKeyState(VK_ESCAPE)	)
			break;
	}
	return 0;
}