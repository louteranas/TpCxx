/*
 * main.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: loutera
 */

#include "GerstnerWaveModel.h"
#include <assert.h>
#include <iostream>


int main (void)
{
	// ---------------- Test Height ----------------------------
	Dvector v(4, 1);
	v(0) = 2; // v = (2, 1, 1, 1)
	Height h(20.0, 1.0, 4, 1, v);
	//Test de l'opérateur ()
	assert(h(0, 0) == 2 && h(0, 1) == 1);
	//Test des accesseurs de Height
	assert(h.getLx() == 20.0 && h.getLy() == 1.0 && h.getNx() == 4 && h.getNy() == 1);
	//Test du constructeur par copie et de l'opérateur +=
	Height h2(h);
	h2 += h;
	assert(h2(0, 0) == 4 && h2(0, 1) == 2);
	cout << "Height OK\n";
	// -----------------  Test GerstnerWave ---------------------
	//Création des GerstnerWaves
	vector<GerstnerWave> waves;
	double norme;
	Dvector dir1(2, 0);
	Dvector dir2(2, 0);
	dir1(0) = 1.1; dir1(1) = 1.9;
	dir2(0) = 0.8; dir2(1) = 1.8;
	norme = sqrt(pow(dir1(0), 2) + pow(dir1(1), 2));
	GerstnerWave gw1(6.0, 0.0, dir1, sqrt(9.81 * norme));
	norme = sqrt(pow(dir2(0), 2) + pow(dir2(1), 2));
	GerstnerWave gw2(5.0, 0.0, dir2, sqrt(9.81 * norme));
	// Tests accesseurs
	assert((gw1.getAmpl() == 6.0) & (gw2.getPhase() == 0.0) && (gw1.getDir())(0) == 1.1);
	// Test opérateur ()
	Height h_t0(20.0, 1.0, 4, 1);
	h_t0 = gw1(0.0, h, h.getNx(), h.getNy(), h.getLx(), h.getLy());
	assert(h_t0(0, 0) == 6.0);
	cout << "GerstnerWave OK\n";
	// -----------------  Test GerstnerWaveModel ---------------------
	//Création du modèle
	Dvector windDir(2, 0);
	windDir(0) = 1; windDir(1) = 2;
	waves.push_back(gw1);
	waves.push_back(gw2);
	GerstnerWaveModel gwm(windDir, 4, 2.5, 5, 6, 20.0, 5.0, 4, 1, waves);
	//Test accesseurs
	assert((gwm.getDir()(0) == 1) && (gwm.getAlign() == 4) && (gwm.getIntens() == 2.5));
	assert((gwm.getDir()(1) == 2) && (gwm.getLong() == 5) && (gwm.getAjust() == 6));
	//Test opérateur()
	h_t0 = gwm(0.0);
	assert (h_t0(0, 0) == 11);
	cout << "GerstnerWaveModel OK\n";
	cout << "TESTS TERMINÉS\n";
}