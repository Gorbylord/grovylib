#pragma once

#include <string>
#include <vector>

struct STile {
	unsigned char						Image;
	unsigned char						Code;
	::std::string						Name;
	bool								Solid;
};


#define AXIS_Y							22
#define AXIS_X							27
#define INVALID_ENEMY					0xFF

struct SPoint {
	int32_t								x
		,								y
		;
	SPoint								operator +							(const SPoint& other) { return { x + other.x, y + other.y }; }
	SPoint								operator -							(const SPoint& other) { return { x - other.x, y - other.y }; }
};

struct SMap {
	SPoint								axis								= {}; 
	uint8_t								enemyTiles		[AXIS_Y][AXIS_X]	= {};
	uint8_t								maptiles		[AXIS_Y][AXIS_X]	= {};
	bool								solidMap		[AXIS_Y][AXIS_X]	= {};
};

struct SCharacter {
	SPoint								Position		= {};
	int32_t								direction		= 0
		,								score			= 0
		;
	uint8_t								icono			= 0;
	bool								vulnerability	= false,
										InHouse			= false
		;
};

struct SGame {
	SCharacter							Player			= {};	 
	SMap								Map				= {}; 
	std::vector<SCharacter>				Enemy			= {}; 
	bool								PowerUp			= false;
	uint32_t							GameLvl			= 0
		,								Lives			= 0
		,								CounterPoints	= 0
		,								CounterPower	= 0
		,								CounterSleep	= 0
		,								CounterFruit	= 0
		,								CounterCombo	= 0
		,								MaxFruit		= 0
		;
};
