#ifndef GERSTNERWAVE_H
#define GERSTNERWAVE_H

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ostream>
#include <cstdlib>
#include <ctime>

#include <limits>
using namespace std;

class GerstnerWave
{
	public :
	GerstnerWave(double amplitude, double phase, double direction, double frequence);
	~GerstnerWave();
	GerstnerWave(const GerstnerWave &wave);
	GerstnerWave &operator=(GerstnerWave &wave);
	GerstnerWave(const GerstnerWave &&wave);
	GerstnerWave &operator=(GerstnerWave &&wave);
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
