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
#include "Height.h"

using namespace std;

class WaveModel{
	public :
		WaveModel();
	    WaveModel(Dvector dir, double align, double intensite, double longueurOnde, double ajust);
	    virtual ~WaveModel();
	    WaveModel(const WaveModel &wave);
     	WaveModel &operator=(const WaveModel &wave) =delete;
	    WaveModel(WaveModel &&wave);
      	WaveModel &operator=(WaveModel &&wave) =delete;
		virtual Dvector getDir() const =0;
		virtual double getAlign() const =0;
		virtual double getIntens() const =0;
		virtual double getLong() const =0;
		virtual double getAjust() const =0;
		virtual Height operator()(double t) = 0;
	protected:
	  	Dvector dir;
	  	double align;
		double intensite;
		double longueurOnde;
		double ajust;
};

#endif
