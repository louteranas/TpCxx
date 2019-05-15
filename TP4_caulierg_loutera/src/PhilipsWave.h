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
	PhilipsWave(double amplitude, double windDir, double windSpeed, int Lx, int Ly, int Nx, int Ny);
	~PhilipsWave();
	PhilipsWave(const PhilipsWave &wave);
	PhilipsWave &operator=(const PhilipsWave &wave);
	PhilipsWave(PhilipsWave &&wave);
	PhilipsWave &operator=(PhilipsWave &&wave);
	double getAmpl();
	double getWindDir();
	double getWindSpeed();
	int getLy();
	int getLx();
	int getNx();
	int getNy();
	Height operator()(double t, Height &H, int Nx, int Ny, double Lx, double Ly) const;


	private:
		double amplitude;
		double windDir;
		double windSpeed;
		int Lx;
		int Ly;
		int Nx;
		int Ny;
};

#endif
