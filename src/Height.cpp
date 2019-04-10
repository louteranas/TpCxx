#include "Height.h"

Height::Height(unsigned double lx, unsigned double ly, unsigned int nx, unsigned int ny, const Dvector dvect)
{
    this->lx = lx;
    this->ly = ly;
    this->nx = nx;
    this->ny = ny;
    this->dvect = dvect;
}

Height::Height(const Height &h) {
    this->lx = h.lx;
    this->ly = h.ly;
    this->nx = h.nx;
    this->ny = h.ny;
    this->dvect = h.dvect;
}

Height::Height(Height &&h) {
    std::swap(this->lx, h.lx);
    std::swap(this->ly, h.ly);
    std::swap(this->nx, h.nx);
    std::swap(this->ny, h.ny);
    std::swap(this->dvect, h.dvect);

  }( double t
Height& Height::operator=(Height &&sourceH){
  std::swap(this->lx, sourceH.lx);
  std::swap(this->ly, sourceH.ly);
  std::swap(this->nx, sourceH.nx);
  std::swap(this->ny, sourceH.ny);
  std::swap(this->dvect, sourceH.dvect);
  return *this;
}

unsigned double Height::getLx() {
  return this->lx;
}
unsigned double Height::getLy() {
  return this->ly;
}
unsigned int Height::getNx() {
  return this->nx;
}
unsigned int Height::getNy() {
  return this->ny;
}
Dvector Height::getDvect() {
  return this->dvect;
}

Height::~Height() {

}

Height &Height::operator=(const Height &sourceH) {
    this->lx = sourceH.lx;
    this->ly = sourceH.ly;
    this->nx = sourceH.nx;
    this->ny = sourceH.ny;
    this->dvect = sourceH.dvect;
    return *this;
}

double &Height::operator()(unsigned int x, unsigned int y){
    return this->dvect(x * this->nx + y);
}

double Height::operator()(unsigned int x, unsigned int y) const{
    return this->dvect(x * this->nx + y);
}
