#ifndef OCEAN_H
#define OCEAN_H

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include "PhilipsWaveModel.h"
#include "GerstnerWaveModel.h"

using namespace std;

class Ocean
{
	public :
		Ocean(double lx, double ly, int nx, int ny, WaveModel &model);
		~Ocean();
		double getT();
		double getLx();
		double getLy();
		int getNx();
		int getNy();
		void generateHeight();
		void compute();
		void gl_vertices();

	private:
		double lx;
		double ly;
		int nx;
		int ny;
		double t;
		Height h;
		WaveModel &model;
		double** vertices;
};

#endif
