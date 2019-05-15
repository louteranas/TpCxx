/*
 * main.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: loutera
 */

#include "PhilipsWaveModel.h"
#include <assert.h>
#include <iostream>

int main (void)
{
	Dvector v(4, 0);
	v(0) = 5; v(2) = 4; v(3) = -5;
	cout << v;
	v.fft2d(2, 2);
	cout << v;
	v.ifft2d(2, 2);
	cout << v;
	cout << "OK\n";
}