#ifndef PHILIPSWAVE_H
#define PHILIPSWAVE_H

#define _USE_MATH_DEFINES
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <math.h>
#include "Height.h"

using namespace std;

class PhilipsWave
{
	public :
	PhilipsWave(double amplitude, double phase, double direction, double frequence);
	~PhilipsWave();
	PhilipsWave(const PhilipsWave &wave);
	PhilipsWave &operator=(const PhilipsWave &wave);
	PhilipsWave(PhilipsWave &&wave);
	PhilipsWave &operator=(PhilipsWave &&wave);
	double getAmpl();
	double getPhase();
	double getDir();
	double getFreq();

	private:
		double amplitude;
		double phase;
		double direction;
		double frequence;
};

#endif
