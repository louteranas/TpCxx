#include "Ocean.h"

Ocean::Ocean(double lx, double ly, int nx, int ny, WaveModel &model)
:lx(lx), ly(ly), nx(nx), ny(ny),  t(0), model(model)
{
    this->h = Height(lx, ly, nx, ny);
}

Ocean::~Ocean() {

}

void generateHeight(){

}

void compute(){

}

void gl_vertices(){

}
