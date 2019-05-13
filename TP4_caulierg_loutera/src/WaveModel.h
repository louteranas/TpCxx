#ifndef WAVE_H
#define WAVE_H

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ostream>
#include <cstdlib>
#include <ctime>

#include <limits>
using namespace std;

class WaveModel{
	public :
	    WaveModel(double* dir, double align, double intensite, double longueurOnde, double ajust);
	    virtual ~WaveModel();
	    WaveModel(const WaveModel &wave);
     	WaveModel &operator=(const WaveModel &wave) =delete;
	    WaveModel(WaveModel &&wave);
      	WaveModel &operator=(WaveModel &&wave) =delete;
		virtual double* getDir();
		virtual double getAlign();
		virtual double getIntens();
		virtual double getLong();
		virtual double getAjust();
	protected:
	    double* dir;
	    double align;
		double intensite;
		double longueurOnde;
		double ajust;
};

#endif
