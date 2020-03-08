#pragma once


struct SCursor {
	int				x
				,	y
				,	image
				;
};

template <size_t axis_x, size_t axis_y>
struct SMapEditor {
	int			mapTiles[axis_y][axis_x];
	SCursor		Cursor;
};


void				copyMap					(char* mapDst, const char* mapSrc, int size);