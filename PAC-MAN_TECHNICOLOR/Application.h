#pragma once
#include "Game.h"
#include "ASCII_screen.h"
#include "Timer.h"

namespace pcapp {
	struct SApplication {
		::ftwlib::SScreenASCII													ScreenASCII							= {};
		int64_t																	FrameCounter						= 0;

		::ftwlib::STimer														Timer								= {};
		::pcgame::SGame															Game								= {};
	};

	::ftwlib::error_t														setup								(::pcapp::SApplication& applicationInstance);
	::ftwlib::error_t														update								(::pcapp::SApplication& applicationInstance);
	::ftwlib::error_t														render								(::pcapp::SApplication& applicationInstance);
	::ftwlib::error_t														cleanup								(::pcapp::SApplication& applicationInstance);
}