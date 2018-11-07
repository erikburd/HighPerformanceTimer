#include "Timer.h"

// high performance timer class
// inherent limitations of QueryPerformanceCounter discussed here:
// https://msdn.microsoft.com/en-us/library/windows/desktop/ms644904(v=vs.85).aspx
// https://stackoverflow.com/questions/1825720/c-high-precision-time-measurement-in-windows
// https://docs.microsoft.com/en-us/windows/desktop/SysInfo/acquiring-high-resolution-time-stamps
// http://www.songho.ca/misc/timer/timer.html

Timer::Timer()
{
	// initialize variables
	m_dElapsedTime = 0.0;
	m_StartTime.QuadPart = 0;
	m_EndTime.QuadPart = 0;

	// get ticks per second
	::QueryPerformanceFrequency(&m_frequency);
}

Timer::~Timer()
{
	// stop the timer
	Stop();
}

void Timer::Start()
{
	// start the timer
	::QueryPerformanceCounter(&m_StartTime);
}

void Timer::Stop()
{
	// stop the timer
	::QueryPerformanceCounter(&m_EndTime);
}

double Timer::GetElaspedTime()
{
	// return the total elasped time in ms
	return ((m_EndTime.QuadPart - m_StartTime.QuadPart) * 1000.0 / m_frequency.QuadPart);
}
