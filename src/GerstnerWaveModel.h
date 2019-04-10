#ifndef GerstnerWaveModelMODEL_H
#define GerstnerWaveModelMODEL_H

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include "Dvector.h"
#include "GerstnerWave.h"
#include "Height.h"

using namespace std;

class GerstnerWaveModel
{
	public :
		GerstnerWaveModel(double lx, double ly, int nx, int ny, const vector <GerstnerWave> waves);
		~GerstnerWaveModel();
		GerstnerWaveModel(const GerstnerWaveModel &waveModel);
		GerstnerWaveModel &operator=(const GerstnerWaveModel &waveModel);
		GerstnerWaveModel(GerstnerWaveModel &&waveModel);
		GerstnerWaveModel &operator=(GerstnerWaveModel &&waveModel);
		//Height operator()(double t);
		void add(GerstnerWave wave);
		double getLx();
		double getLy();
		int getNx();
		int getNy();
		const vector <GerstnerWave> getWaves();

	private:
		double lx;
		double ly;
		int nx;
		int ny;
		vector <GerstnerWave> waves;
};

#endif
