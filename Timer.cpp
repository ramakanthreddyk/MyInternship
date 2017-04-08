#include "stdafx.h"
#include "Timer.h"


Timer::Timer()
{
	QueryPerformanceFrequency(&frequency);
	startCount.QuadPart = 0;
	endCount.QuadPart = 0;

	stopped = 0;
	startTimeInMicroSec = 0;
	endTimeInMicroSec = 0;
}


Timer::~Timer()
{
}

void Timer::start()
{
	stopped = 0; // reset stop flag
	QueryPerformanceCounter(&startCount);
}

void Timer::stop()
{
	stopped = 1; // set timer stopped flag
	QueryPerformanceCounter(&endCount);

}

double Timer::getElapsedTime()
{
	return this->getElapsedTimeInSec();
}

double Timer::getElapsedTimeInSec()
{
	return this->getElapsedTimeInMicroSec() * 0.000001;
}

double Timer::getElapsedTimeInMilliSec()
{
	return this->getElapsedTimeInMicroSec() * 0.001;
}


double Timer::getElapsedTimeInMicroSec()
{
	if (!stopped)
		QueryPerformanceCounter(&endCount);

	startTimeInMicroSec = startCount.QuadPart * (1000000.0 / frequency.QuadPart);
	endTimeInMicroSec = endCount.QuadPart * (1000000.0 / frequency.QuadPart);

	return endTimeInMicroSec - startTimeInMicroSec;
}
