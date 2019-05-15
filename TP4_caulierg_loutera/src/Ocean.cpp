#include "Ocean.h"

Ocean::Ocean(double lx, double ly, int nx, int ny, WaveModel &model)
:lx(lx), ly(ly), nx(nx), ny(ny),  t(0), model(model)
{
    this->h = Height(lx, ly, nx, ny);
    double **tab;
    tab = new double*[nx*ny];
    for(int i = 0; i < nx*ny; i++) {
        tab[i] = new double[3];
        tab[i][0] = 0;
        tab[i][1] = 0;
        tab[i][2] = 0;
    }
    this->vertices = tab;
}

Ocean::~Ocean() {

}

void Ocean :: generateHeight(){

}

void Ocean :: compute()
{
    this->h = model(this->t);
}

void Ocean ::gl_vertices(){
  for(int i = 0; i < nx*ny; i++) {
      this->vertices[i][0] = i/nx;
      this->vertices[i][1] = i%nx;
      this->vertices[i][2] = this->h.getDvect()(i);
  }
}

double Ocean::getT() {
  return this->t;
}
int Ocean::getNx() {
  return this->nx;
}
int Ocean::getNy() {
  return this->ny;
}
double Ocean::getLx() {
  return this->lx;
}
double Ocean::getLy() {
  return this->ly;
}
