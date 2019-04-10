#ifndef HEIGHT_H
#define HEIGHT_H

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include "Dvector.h"
#include "GerstnerWave.h"

#include <limits>
using namespace std;

class Height{
	public :
			Height(double lx, double ly, int nx, int ny, const Dvector vect);
			Height(double lx, double ly, int nx, int ny);
	    ~Height();
	    Height(const Height &h);
			Height &operator=(const Height &sourceH);
			Height &operator+=(const Height h);
	    Height(Height &&h);
      Height &operator=(Height &&sourceH);
      double &operator()(int x, int y);
      double operator()(int x, int y) const;
			void fill(double nb);
			double getLx();
			double getLy();
			int getNx();
			int getNy();
			Dvector getDvect();
	private:
			double lx;
			double ly;
			int nx;
			int ny;
			Dvector dvect;
};

#endif
