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
	//----------- Tests nouvelle classe de vecteur -------------------
	Dvector v(4, 0);
	v.getdata()[0][0] = 5; v.getdata()[0][1] = 3;
	v.getdata()[1][0] = 0; v.getdata()[1][1] = 2;
	v.getdata()[2][0] = 1; v.getdata()[2][1] = 3;
	v.getdata()[3][0] = 4; v.getdata()[3][1] = 4;
	Dvector v2(v);
	assert(v2 == v);
	cout << "Vecteur complexe OK\n";
	// ---------- Tests FFT et IFFT en 1D -----------------------------
	v.fft();
	v.ifft();
	assert(v == v2);
	cout << "FFT et IFFT 1D OK\n";
	// ---------- Tests FFT et IFFT en 2D -----------------------------
	v.fft2d(2, 2);
	v.ifft2d(2, 2);
	assert(v == v2);
	cout << "FFT et IFFT 2D OK\n";
	// ---------- Tests de PhilipsWave -------------------------------
	//Création des GerstnerWaves
	vector<PhilipsWave> waves;
	Dvector dir1(2, 0);
	Dvector dir2(2, 0);
	dir1(0) = 1.1; dir1(1) = 1.9;
	dir2(0) = 1.1; dir2(1) = 1.9;
	PhilipsWave pw1(8.0, dir1, 5.0);
	PhilipsWave pw2(4.0, dir2, 5.0);
	// Tests accesseurs
	assert((pw1.getAmpl() == 8.0) and (pw2.getWindSpeed() == 5.0) and (pw1.getWindDir())(0) == 1.1);
	// Test opérateur () difficile à cause de la part de random
	cout << "PhilipsWave OK\n";
	// -----------------  Test PhilipsWaveModel ---------------------
	//Création du modèle
	Dvector windDir(2, 0);
	windDir(0) = 1.1; windDir(1) = 1.9;
	waves.push_back(pw1);
	waves.push_back(pw2);
	PhilipsWaveModel pwm(windDir, 4, 2.5, 5, 6, 20.0, 5.0, 4, 1, waves);
	//Test accesseurs
	assert((pwm.getDir()(0) == 1.1) && (pwm.getAlign() == 4) && (pwm.getIntens() == 2.5));
	assert((pwm.getDir()(1) == 1.9) && (pwm.getLong() == 5) && (pwm.getAjust() == 6));
	//Test opérateur() difficile à cause de la part de random
	cout << "PhilipsWaveModel OK\n";
	cout << "OK\n";
}