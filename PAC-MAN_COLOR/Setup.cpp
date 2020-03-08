#include "Game.h"

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

unsigned char													 getImageByCode(unsigned char code) {
	for (uint32_t iTile = 0; iTile < (uint32_t)::std::size(tileDefinitions); ++iTile)
		if (tileDefinitions[iTile].Code == code)
			return tileDefinitions[iTile].Image;
	return ' ';
}

bool															 getSolidByImage(unsigned char image) {
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

void																					setupMap														(SGame* gameObject) {
	gameObject->Map.Size.y =																AXIS_Y;	
	gameObject->Map.Size.x =																AXIS_X;

	for(uint32_t y = 0; y < (uint32_t)gameObject->Map.Size.y; ++y) {
		for(uint32_t x = 0; x < (uint32_t)gameObject->Map.Size.x; ++x) {
			gameObject->Map.TilesMap		[y][x]											=							getImageByCode(map0[y][x]);
			gameObject->Map.TilesEnemy		[y][x]											=							(unsigned char)INVALID_ENEMY;
			gameObject->Map.TilesDecision	[y][x]											=							false;
			gameObject->Map.TilesSolid		[y][x]											=							getSolidByImage(gameObject->Map.TilesMap[y][x]);
		}
	}
	gameObject->Map.TilesDecision[1][5]		= gameObject->Map.TilesDecision[3][23]	= gameObject->Map.TilesDecision[5][1]	= gameObject->Map.TilesDecision[5][5]	= gameObject->Map.TilesDecision[5][8]	=
	gameObject->Map.TilesDecision[5][13]	= gameObject->Map.TilesDecision[5][18]	= gameObject->Map.TilesDecision[5][20]	= gameObject->Map.TilesDecision[7][5]	= gameObject->Map.TilesDecision[7][13]	=
	gameObject->Map.TilesDecision[7][15]	= gameObject->Map.TilesDecision[7][18]	= gameObject->Map.TilesDecision[7][20]	= gameObject->Map.TilesDecision[9][5]	= gameObject->Map.TilesDecision[9][10]	=
	gameObject->Map.TilesDecision[9][20]	= gameObject->Map.TilesDecision[9][25]	= gameObject->Map.TilesDecision[11][5]	= gameObject->Map.TilesDecision[11][10]	= gameObject->Map.TilesDecision[11][20]	=
	gameObject->Map.TilesDecision[11][25]	= gameObject->Map.TilesDecision[13][5]	= gameObject->Map.TilesDecision[13][13]	= gameObject->Map.TilesDecision[13][15]	= gameObject->Map.TilesDecision[13][18]	=
	gameObject->Map.TilesDecision[13][20]	= gameObject->Map.TilesDecision[15][1]	= gameObject->Map.TilesDecision[15][5]	= gameObject->Map.TilesDecision[15][8]	= gameObject->Map.TilesDecision[15][13]	=
	gameObject->Map.TilesDecision[15][18]	= gameObject->Map.TilesDecision[15][20]	= gameObject->Map.TilesDecision[17][23]	= gameObject->Map.TilesDecision[19][5]	= true;
}

void																					setupPlayer														(SGame* gameObject) {
	gameObject->Player.CurrentDirection														=							DOWN;
	gameObject->Player.Image																=							67;
	gameObject->Player.Position.y															=							10;
	gameObject->Player.Position.x															=							20;
	gameObject->Player.PositionDeltas														=							{0, 0};
	gameObject->Player.Speed																=							4.5f;
}

void																					setupEnemies													(SGame* gameObject) {
	for(uint32_t enemyCount=0; enemyCount < GHOST_COUNT; enemyCount++	) {
		SEnemy																				newEnemy;

		if(enemyCount == BLINKY) {
			newEnemy.Position.x																=							10;
			newEnemy.Position.y																=							10;
			newEnemy.CurrentDirection														=							DOWN;
			newEnemy.CurrentGhost															=							BLINKY;
			newEnemy.CurrentMode															=							MODE_SCATTER;
			newEnemy.Image																	=							147;
			newEnemy.InHouse																=							false;
			newEnemy.PositionDeltas															=							{0, 0};
			newEnemy.Speed																	=							4.0f;
			newEnemy.Vulnerability															=							false;
			newEnemy.TargetTile.y															=							2;
			newEnemy.TargetTile.x															=							0;
		}
		else if(enemyCount == PINKY) {
			newEnemy.Position.x																=							12;
			newEnemy.Position.y																=							10;
			newEnemy.CurrentDirection														=							DOWN;
			newEnemy.CurrentGhost															=							PINKY;
			newEnemy.CurrentMode															=							MODE_SCATTER;
			newEnemy.Image																	=							148;
			newEnemy.InHouse																=							true;
			newEnemy.PositionDeltas															=							{0, 0};
			newEnemy.Speed																	=							4.0f;
			newEnemy.Vulnerability															=							false;
			newEnemy.TargetTile.y															=							19;
			newEnemy.TargetTile.x															=							0;
		}
		else if(enemyCount == INKY) {
			newEnemy.Position.x																=							12;
			newEnemy.Position.y																=							9;
			newEnemy.CurrentDirection														=							DOWN;
			newEnemy.CurrentGhost															=							INKY;
			newEnemy.CurrentMode															=							MODE_SCATTER;
			newEnemy.Image																	=							149;
			newEnemy.InHouse																=							true;
			newEnemy.PositionDeltas															=							{0, 0};
			newEnemy.Speed																	=							4.0f;
			newEnemy.Vulnerability															=							false;
			newEnemy.TargetTile.y															=							0;
			newEnemy.TargetTile.x															=							26;
		}
		else if(enemyCount == CLYDE) {
			newEnemy.Position.x																=							12;
			newEnemy.Position.y																=							11;
			newEnemy.CurrentDirection														=							DOWN;
			newEnemy.CurrentGhost															=							CLYDE;
			newEnemy.CurrentMode															=							MODE_SCATTER;
			newEnemy.Image																	=							162;
			newEnemy.InHouse																=							true;
			newEnemy.PositionDeltas															=							{0, 0};
			newEnemy.Speed																	=							4.0f;
			newEnemy.Vulnerability															=							false;
			newEnemy.TargetTile.y															=							21;
			newEnemy.TargetTile.x															=							26;
		}

		gameObject->Map.TilesEnemy[newEnemy.Position.y][newEnemy.Position.x] = newEnemy.Image;
		gameObject->Enemies.push_back(newEnemy);
	}
}