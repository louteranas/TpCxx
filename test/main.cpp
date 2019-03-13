/*
 * main.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: loutera
 */

#include "Dvector.h"
#include "Height.h"
#include <iostream>


int main (void)
{
	//double tab[3];
	//tab[0] = 1;
	//tab[1] = 2;
	//tab[2] = 3;
	//Dvector vecteur(3, tab);
	//vecteur.display(std::cout);
	//std::cout<<vecteur.size()<<'\n';
	//vecteur.fillRandomly();
	//vecteur.display(std::cout);
	//Dvector newVect = vecteur;
	//newVect.display(std::cout);
	//cout << vecteur(0) << '\n';
	//vecteur(0) = 5;
	//cout << vecteur(0) << '\n';
    Dvector newVector(12);
    Height h(4, 3, newVector);
    //cout << h;
    //cout << boolalpha;
    //cout << (vecteur == newVector)<<'\n';
    //newVector+=2;
    //cout << (vecteur == newVector)<<'\n';
    //(newVector + vecteur).display(cout);

}




