#include "Ocean.h"

Ocean::Ocean(double lx, double ly, int nx, int ny, int model)
{
    this->lx = lx;
    this->ly = ly;
    this->nx = nx;
    this->ny = ny;
    this->t = 0;
    this->model = model;
    this->h = Height(lx, ly, nx, ny);
}

Ocean::Ocean(const Ocean &oc) {
  this->lx = oc.lx;
  this->ly = oc.ly;
  this->nx = oc.nx;
  this->ny = oc.ny;
  this->t = oc.t;
  this->h = oc.h;
  this->model = oc.model;
  this->vertices = oc.vertices;
}

Ocean::~Ocean() {

}

void generateHeight(){

}

void compute(){

}

void gl_vertices(){

}
