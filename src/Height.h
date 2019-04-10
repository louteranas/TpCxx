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

#include <limits>
using namespace std;

class Height{
	public :
	    Height(unsigned double lx, unsigned double ly, unsigned int nx, unsigned int ny, const Dvector vect);
	    ~Height();
	    Height(const Height &h);
      Height &operator=(const Height &sourceH);
	    Height(Height &&h);
      Height &operator=(Height &&sourceH);
      double &operator()(unsigned int x, unsigned int y);
      double operator()(unsigned int x, unsigned int y) const;
			unsigned double getLx();
			unsigned double getLy();
			unsigned int getNx();
			unsigned int getNy();
			Dvector getDvect();
	private:
			unsigned double lx;
			unsigned double ly;
			unsigned int nx;
			unsigned int ny;
			Dvector dvect;
};

#endif
