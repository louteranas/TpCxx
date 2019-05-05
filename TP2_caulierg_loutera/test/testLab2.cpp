/*
 * main.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: loutera
 */

#include "Dvector.h"


int main (void)
{
	Dvector v1(2, 4);
	Dvector v2(2, 2);
	//Test Q1
	double access = v1(1);
	assert(access == 4);
	v1(0) = 6; v1(1) = 6;
	access = v1(1);
	assert(access == 6);
	cout << "Q1 OK !\n";
	//Test Q2
	v1 = v2;
	assert(v1(1) == 2 and v1(0) == 2);
	cout << "Q2 OK ! (une seule version de l'opérateur =)\n";
	//Test Q3
	v1 += v2;
	assert(v1(0) == 4 and v1(1) == 4);
	v1 += 1;
	assert(v1(0) == 5 and v1(1) == 5);
	v1 -= 1;
	assert(v1(0) == 4 and v1(1) == 4);
	v1 -= v2;
	assert(v1(0) == 2 and v1(1) == 2);
	v1 *= 2;
	assert(v1(0) == 4 and v1(1) == 4);
	v1 /= 2;
	assert(v1(0) == 2 and v1(1) == 2);
	cout << "Q3 OK !\n";
	//Test Q4
	Dvector v3(2);
	v3 = v1 + v2;
	assert(v3(0) == 4 and v3(1) == 4);
	v3 = v1 + 1;
	assert(v3(0) == 3 and v3(1) == 3);
	v3 = v1 - v2;
	assert(v3(0) == 0 and v3(1) == 0);
	v3 = v1 - 1;
	assert(v3(0) == 1 and v3(1) == 1);
	v3 = -v1;
	assert(v3(0) == -2 and v3(1) == -2);
	v3 = v1 * 3;
	assert(v3(0) == 6 and v3(1) == 6);
	v3 = v1 / 4;
	assert(v3(0) == 0.5 and v3(1) == 0.5);
	cout << "Q4 OK !\n";
	//Test Q5
	cout << v1;
	cout << "Q5 OK ! (Opérateur >> non testé)\n";
	//Test Q6
	assert(v1 == v2 and !(v1 == v3));
	cout << "Q6 OK !\n";
	//Test Q7
	v1.resize(1);
	assert((v1.size() == 1) and v1(0) == 2);
	v1.resize(2, 4);
	assert((v1.size() == 2) and v1(0) == 2 and v1(1) == 4);
	cout << "Q7 OK !\n";
}