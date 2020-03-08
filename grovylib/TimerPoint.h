#pragma once

#include <cstdint>

struct STimer {
	float				LastTime;
						STimer				()				{ Reset(); }
	void				Reset				();
	void				Frame				();

private:
	int64_t				CountsPerSecond			=	0;
	int64_t				PrevTimeStamp			=	0;
	int64_t				CurrentTimeStamp		=	0;
	double				SecondsPerCount			=	0;
	double				MillisecondsPerCount	=	0;
};

typedef struct SVector2D {
	float					x
		,					y
		;
} SPoint2D;

typedef SVector2D SVelocity2D;