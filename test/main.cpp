/*
 * main.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: loutera
 */

#include "Dvector.h"
#include <iostream>


int main (void)
{
	double tab[3];
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	Dvector vecteur(3, tab);
	vecteur.resize(3);
	vecteur.display(cout);

	vecteur.resize(2);
	vecteur.display(cout);

	vecteur.resize(4, 4.0);
	vecteur.display(cout);
}




