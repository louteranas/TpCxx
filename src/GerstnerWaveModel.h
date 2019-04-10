#ifndef GerstnerWaveModelMODEL_H
#define GerstnerWaveModelMODEL_H

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ostream>
#include <cstdlib>
#include <ctime>

#include <limits>
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
		Height operator()(double t);
		void add(GerstnerWave wave);
		double getLx();
		double getLy();
		double getNx();
		double getNy();
		const vector <GerstnerWave> getWaves();

	private:
		double lx;
		double ly;
		double nx;
		double ny;
		const vector <GerstnerWave> waves;
};

#endif
