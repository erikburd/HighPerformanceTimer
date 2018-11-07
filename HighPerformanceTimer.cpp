// HighPerformanceTimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Timer.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Timer t;

	int nTrials = 10;
	double d = 0.0;

	for (int i=0; i < nTrials; i++)
	{
		cout << "Timer - " << i << "\n";
		t.Start();
		::Sleep(1000);
		t.Stop();
		d += t.GetElaspedTime();
	}
	cout << "Average time in ms: " << d/nTrials << ".\n";
	return 0;
}

