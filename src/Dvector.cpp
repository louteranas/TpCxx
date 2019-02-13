#include "Dvector.h"
#include <iomanip>

Dvector::Dvector()
{
	size = 0;
	data = nullptr;
}

Dvector::Dvector(unsigned int size, const double* data)
{
	this->size = size;
	this->data = new double[size];
	if(this->data != nullptr){
		for(unsigned int i = 0; i < size; i++){
			this->data[i] = data[i];
		}
	}

}

Dvector::~Dvector(){
	if(this->data != nullptr){
		delete[] this->data;
	}
	this->data = nullptr;

}

void Dvector::display(std::ostream& str) const{
	str << std::setprecision(6) << std::fixed;
	for (unsigned int i = 0; i<this->size; i++){
		str << this->data[i] << '\n';
	}
}
