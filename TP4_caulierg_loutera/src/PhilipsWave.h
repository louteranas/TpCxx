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
#include <random>
#include <limits>
#include <math.h>
#include "Height.h"

using namespace std;

class PhilipsWave
{
	public :
	PhilipsWave(double amplitude, Dvector windDir, double windSpeed);
	~PhilipsWave();
	PhilipsWave(const PhilipsWave &wave);
	PhilipsWave &operator=(const PhilipsWave &wave);
	PhilipsWave(PhilipsWave &&wave);
	PhilipsWave &operator=(PhilipsWave &&wave);
	double getAmpl();
	Dvector getWindDir();
	double getWindSpeed();
	double ph(double kx, double ky) const;
	Height operator()(double t, Height &H, int Nx, int Ny, double Lx, double Ly) const;


	private:
		double amplitude;
		Dvector windDir;
		double windSpeed;
};

#endif
