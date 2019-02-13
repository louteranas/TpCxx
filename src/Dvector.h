#ifndef DVECTOR_H
#define DVECTOR_H

#include <ostream>

class Dvector{
	public :
		Dvector();
		Dvector(unsigned int size, const double* data = nullptr);
		~Dvector();
		void display(std::ostream& str)const;
	private:
		/*Attributes*/
		unsigned int size;
		double* data;

};


#endif /* end of include guard : DVECTOR_H */
