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
	    Height(unsigned int lx, unsigned int ly, const Dvector vect);
	    ~Height();
	    Height(const Height &h);
        Height &operator=(const Height &sourceH);
	    Height(const Height &&h);
        Height &operator=(const Height &&sourceH);

        double &operator()(unsigned int x, unsigned int y);
        double operator()(unsigned int, unsigned int y) const;

	private:
	    unsigned int lx;
	    unsigned int ly;
		Dvector dvect;
};

#endif
