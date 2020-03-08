#pragma once
#include "Coord.h"
#include "Grid.h"
#include "Tilemap.h"
#include <string>
#include <vector>

#ifndef GAME_H_90237409238740923749023
#define GAME_H_90237409238740923749023

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
#define INVALID_ENEMY			0xFF

namespace															pcgame{
	typedef	::ftwlib::SCoord2<float>									SVector2;
	typedef	::ftwlib::SCoord2<int32_t>									STileCoord2;

	static constexpr		const int32_t								AXIS_X										= 27;
	static constexpr		const int32_t								AXIS_Y										= 22;

	struct																STile {
		unsigned char														Image;
		unsigned char														Code;
		::std::string														Name;
		bool																Solid;
	};

	struct																SAnimatedObject {
		STileCoord2															Position									= {};
		SVector2															PositionDeltas								= {};
		double																Speed										= {};
		int32_t																Direction									= 0;
	};

	enum																GHOST_MODE {
																			CHASER
		,																	SCATERED
		,																	FRIGHTNED
	};

	struct																SGhosts : public SAnimatedObject {
		GHOST_MODE															CurrentMode									= {};
		bool																Vulnerability								= false;
		bool																InHouse										= false;
	};

	struct																SMap {
		::ftwlib::SCoord2<uint32_t>											Size;
		::pcgame::STileMapASCII<AXIS_X, AXIS_Y>								TileMap;
		::pcgame::STileMapASCII<AXIS_X, AXIS_Y>								Enemy;
		bool																solidMap [AXIS_Y][AXIS_X]					= {};
	};

	struct																SFrameInfo {
		uint32_t															FrameNumber									= 0;
		double																LastFrameTime								= 0;
		double																TotalTime									= 0;
	};

	struct																SGame {
		SAnimatedObject														PacMan										= {};
		SMap																Map											= {};
		std::vector<SGhosts>												Ghosts										= {};
		SFrameInfo															FrameInfo									= {};
		bool																PowerUp										= false;
		uint32_t															GameLvl										= 0
			,																Lives										= 0
			,																Score										= 0
			,																CounterPoints								= 0
			,																CounterPower								= 0
			,																CounterSleep								= 0
			,																CounterFruit								= 0
			,																CounterCombo								= 0
			,																MaxFruit									= 0
			;
	};

	::ftwlib::error_t													setup										(::pcgame::SGame& gameObject);
	::ftwlib::error_t													cleanup										(::pcgame::SGame& gameObject);
	::ftwlib::error_t													update										(::pcgame::SGame& gameObject, uint64_t timeElapsedMicroseconds);
	::ftwlib::error_t													draw										(const ::pcgame::SGame& gameObject, uint32_t targetWidth, uint8_t* targetCharacterGrid, uint16_t* targetColorGrid);
}

#endif //GAME_H_90237409238740923749023