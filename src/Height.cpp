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

Height::Height(Height &&h) {
    std::swap(this->lx, h.lx);
    std::swap(this->ly, h.ly);
    std::swap(this->dvect, h.dvect);

  }
Height& Height::operator=(Height &&sourceH){
  std::swap(this->lx, sourceH.lx);
  std::swap(this->ly, sourceH.ly);
  std::swap(this->dvect, sourceH.dvect);
  return *this;
}

unsigned int Height::getLx() {
  return this->lx;
}
unsigned int Height::getLy() {
  return this->ly;
}
Dvector Height::getDvect() {
  return this->dvect;
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
