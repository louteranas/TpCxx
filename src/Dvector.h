#ifndef DVECTOR_H
#define DVECTOR_H

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ostream>
#include <cstdlib>
#include <ctime>


#include <limits>
using namespace std;

class Dvector{
	public :
		Dvector();
		Dvector(int size, const double* data = nullptr);
		Dvector(const Dvector &vector);
		Dvector(string file);
		~Dvector();
		void display(ostream& str)const;
		int size();
		int size()const;
		void fillRandomly();
		void resize(int newSize, double init = 0);
		double &operator()(int index);
		double operator()(int index) const;
		Dvector &operator=(const Dvector &sourceVecteur);
		Dvector &operator+=(const double op);
		Dvector &operator-=(const double op);
		Dvector &operator*=(const double op);
		Dvector &operator/=(const double op);
		Dvector &operator+=(const Dvector &sourceVecteur);
    Dvector &operator-=(const Dvector &sourceVecteur);
    bool operator==(const Dvector &v2);
		Dvector &operator=(Dvector &&d);

	private:
		/*Attributes*/
		int dim;
		double* data;

};
ostream &operator<<(ostream &out, const Dvector &vect);
istream &operator>>(istream &in, const Dvector &vect);
Dvector operator+(const Dvector &v1, const double op);
Dvector operator-(const Dvector &v1, const double op);
Dvector operator*(const Dvector &v1, const double op);
Dvector operator/(const Dvector &v1, const double op);
Dvector operator+(const Dvector &v1, const Dvector &v2);
Dvector operator-(const Dvector &v1, const Dvector &v2);
Dvector operator-(const Dvector &v1);

#endif /* end of include guard : DVECTOR_H */
