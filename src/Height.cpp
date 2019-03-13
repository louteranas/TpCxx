#include "Height.h"

Height::Height(unsigned int lx, unsigned int ly, const Dvector dvect)
{
    this->lx = lx;
    this->ly = ly;
    this->dvect = dvect;
}

Height::Height(const Height &h) {
    this->lx = h.lx;
    this->ly = h.ly;
    this->dvect = h.dvect;
}

Height::Height(const Height &&h) {
    /*swap();
    swap();*/
}

Height::~Height() {

}

Height &Height::operator=(const Height &sourceH) {
    this->lx = sourceH.lx;
    this->ly = sourceH.ly;
    this->dvect = sourceH.dvect;
    return *this;
}

double &Height::operator()(unsigned int x, unsigned int y){
    return this->dvect(x * this->ly + y);
}

double Height::operator()(unsigned int x, unsigned int y) const{
    return this->dvect(x * this->ly + y);
}