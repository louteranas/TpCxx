#ifndef PhilipsWaveModelMODEL_H
#define PhilipsWaveModelMODEL_H

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include "PhilipsWave.h"
#include "WaveModel.h"

using namespace std;

class PhilipsWaveModel : public WaveModel
{
	public :
		PhilipsWaveModel(Dvector dir, double align, double intensite, double longueurOnde, double ajust, double lx, double ly, int nx, int ny, const vector <PhilipsWave> waves);
		~PhilipsWaveModel();
		PhilipsWaveModel(const PhilipsWaveModel &waveModel);
		PhilipsWaveModel &operator=(const PhilipsWaveModel &waveModel);
		PhilipsWaveModel(PhilipsWaveModel &&waveModel);
		PhilipsWaveModel &operator=(PhilipsWaveModel &&waveModel);
		void add(PhilipsWave wave);
		double getLx();
		double getLy();
		int getNx();
		int getNy();
		Dvector getDir() const;
		double getAlign() const;
		double getIntens() const;
		double getLong() const;
		double getAjust() const;
		Height operator()(double t);

		const vector <PhilipsWave> getWaves();

	private:
		double lx;
		double ly;
		int nx;
		int ny;
		vector <PhilipsWave> waves;
};

#endif
