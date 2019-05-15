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
#include "GerstnerWave.h"
#include "WaveModel.h"

using namespace std;

class GerstnerWaveModel : public WaveModel
{
	public :
		GerstnerWaveModel(Dvector dir, double align, double intensite, double longueurOnde, double ajust, double lx, double ly, int nx, int ny, const vector <GerstnerWave> waves);
		~GerstnerWaveModel();
		GerstnerWaveModel(const GerstnerWaveModel &waveModel);
		Height operator()(double t);
		void add(GerstnerWave wave);
		double getLx();
		double getLy();
		int getNx();
		int getNy();
		Dvector getDir() const;
		double getAlign() const;
		double getIntens() const;
		double getLong() const;
		double getAjust() const;
		const vector <GerstnerWave> getWaves();

	private:
		double lx;
		double ly;
		int nx;
		int ny;
		vector <GerstnerWave> waves;
};

#endif
