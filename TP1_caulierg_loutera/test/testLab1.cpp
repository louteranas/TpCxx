/*
 * main.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: loutera
 */

#include "Dvector.h"
#include <assert.h>
#include <iostream>


int main (void)
{
	Dvector vide = Dvector();
	assert( vide.size() == 0 );
	Dvector v(3,2.5);
	assert( v.size() == 3 );
	assert( v(2) == 2.5 );
	v.display(cout);
	Dvector vcopie(v);
	assert( vcopie.size() == 3 );
	assert( vcopie(2) == 2.5 );
	Dvector vFile("dvectorInit.txt");
	vFile.display(cout);
	assert( vFile.size() == 3 );
	assert( vFile(0) == 5 and vFile(1) == 4 and vFile(2) == 12);
	cout << "OK\n";
}