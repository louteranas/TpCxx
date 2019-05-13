#ifndef GERSTNERWAVE_H
#define GERSTNERWAVE_H

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

class GerstnerWave
{
	public :
		GerstnerWave(double amplitude, double phase, double* direction, double frequence);
		~GerstnerWave();
		GerstnerWave(const GerstnerWave &wave);
		GerstnerWave &operator=(const GerstnerWave &wave);
		GerstnerWave(GerstnerWave &&wave);
		GerstnerWave &operator=(GerstnerWave &&wave);
		double getAmpl();
		double getPhase();
		double* getDir();
		double getFreq();
		Height operator()(double &t, Height &H, int &Nx, int &Ny, double &Lx, double &Ly);

	private:
		double amplitude;
		double phase;
		double* direction;
		double frequence;
};

#endif
