#include "Sir_timer.h"
#include <windows.h>

void							::ftwlib::STimer::Reset											()								{
	QueryPerformanceFrequency( ( LARGE_INTEGER* )&CountsPerSecond );
	SecondsPerCount					= (1.0 / (CountsPerSecond));
	QueryPerformanceCounter( ( LARGE_INTEGER* )&PrevTimeStamp );		
	LastTimeSeconds 						= 0;
}

void							::ftwlib::STimer::Frame											()								{
	QueryPerformanceCounter( ( LARGE_INTEGER* ) &CurrentTimeStamp );
	LastTimeSeconds						=  (float)(( CurrentTimeStamp - PrevTimeStamp )* SecondsPerCount);
	PrevTimeStamp					= CurrentTimeStamp;
}
