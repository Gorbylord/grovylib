#pragma once
#include "Grid.h"
#include "Error.h"

#ifndef TILEMAP_H
#define TILEMAP_H

namespace pcgame 
{
	struct STileASCII {
							uint8_t													Character;
							uint16_t												Color;
	};
	
	template <size_t _gridWidth, size_t _gridHeight>
	struct STileMapASCII {
		typedef				::ftwlib::SGrid<int32_t, _gridWidth, _gridHeight>		TTileIndexGrid;

		static constexpr	const uint32_t											Width						= (uint32_t)_gridWidth;
		static constexpr	const uint32_t											Depth						= (uint32_t)_gridHeight;

							TTileIndexGrid											Cells						= {};
							::ftwlib::array_view<const ::pcgame::STileASCII>		TileDescriptionTable		= {};
	};
}

#endif // TILEMAP_H