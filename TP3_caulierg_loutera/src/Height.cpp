#include "Height.h"

Height::Height(double lx, double ly, int nx, int ny, const Dvector dvect)
{
    this->lx = lx;
    this->ly = ly;
    this->nx = nx;
    this->ny = ny;
    assert(nx * ny == dvect.size());
    this->dvect = dvect;
}
Height::Height(double lx, double ly, int nx, int ny)
{
    this->lx = lx;
    this->ly = ly;
    this->nx = nx;
    this->ny = ny;
    this->dvect = Dvector(nx * ny);
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
}

Height& Height::operator=(Height &&sourceH){
  std::swap(this->lx, sourceH.lx);
  std::swap(this->ly, sourceH.ly);
  std::swap(this->nx, sourceH.nx);
  std::swap(this->ny, sourceH.ny);
  std::swap(this->dvect, sourceH.dvect);
  return *this;
}

 double Height::getLx() {
  return this->lx;
}
 double Height::getLy() {
  return this->ly;
}
 int Height::getNx() {
  return this->nx;
}
 int Height::getNy() {
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

Height &Height::operator+=(Height h) {
    for(int i = 0; i < this->dvect.size(); i++) {
      (this->dvect)(i) += (h.getDvect())(i);
    }
    return *this;
}
double &Height::operator()( int x,  int y){
    return this->dvect(x * this->nx + y);
}

double Height::operator()( int x,  int y) const{
    return this->dvect(x * this->nx + y);
}
void Height::fill(double nb) {
  int size = this->dvect.size();
  for(int i =0; i < size; i++){
    (this->dvect)(i) = nb;
  }
}
