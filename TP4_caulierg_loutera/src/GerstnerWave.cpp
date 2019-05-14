#include "GerstnerWave.h"

GerstnerWave::GerstnerWave(double amplitude, double phase, Dvector direction, double frequence)
{
    this->amplitude = amplitude;
    this->phase = phase;
    this->direction = direction;
    this->frequence = frequence;
}

GerstnerWave::GerstnerWave(const GerstnerWave &wave) {
  this->amplitude = wave.amplitude;
  this->phase = wave.phase;
  this->direction = wave.direction;
  this->frequence = wave.frequence;
}

GerstnerWave::GerstnerWave(GerstnerWave &&wave) {
  std::swap(this->amplitude, wave.amplitude);
  std::swap(this->phase, wave.phase);
  std::swap(this->direction, wave.direction);
  std::swap(this->frequence, wave.frequence);
  }
GerstnerWave& GerstnerWave::operator=(GerstnerWave &&wave){
  std::swap(this->amplitude, wave.amplitude);
  std::swap(this->phase, wave.phase);
  std::swap(this->direction, wave.direction);
  std::swap(this->frequence, wave.frequence);
  return *this;
}

double GerstnerWave::getAmpl() {
  return this->amplitude;
}
Dvector GerstnerWave::getDir() {
  return this->direction;
}
double GerstnerWave::getPhase() {
  return this->phase;
}
double GerstnerWave::getFreq() {
  return this->frequence;
}

GerstnerWave::~GerstnerWave() {

}

GerstnerWave &GerstnerWave::operator=(const GerstnerWave &wave) {
  this->amplitude = wave.amplitude;
  this->phase = wave.phase;
  this->direction = wave.direction;
  this->frequence = wave.frequence;
  return *this;
}

Height GerstnerWave::operator()(double t, Height &H, int Nx, int Ny, double Lx, double Ly) const {
  double dx = (double)Lx / Nx;
  double dy = (double)Ly / Ny;
  H.fill(0.0);
  for (int i=0; i<Ny; i++){
    for (int j=0; j<Nx; j++){
      // Calcul de X et Z avec les equations (13) et (14)
      // Ici onsuppose que K = (Ky,Kx)  et  k = | |K| |
      double Z, X[2];
      double norme = sqrt(pow(this->direction(0), 2) + pow(this->direction(1), 2));

      const double Xo[2]={i*dy, j*dx};
      const double kdotx0=this->direction(0)*Xo[0]+this->direction(1)*Xo[1];
      const double theta=(kdotx0-(this->frequence)*t+(this->phase) )* 3.1415926535 / 180;
      //cout << "theta = " << theta << "\n";

      X[0]=Xo[0]-(this->direction(0)/norme)*(this->amplitude)*sin(theta);
      X[1]=Xo[1]-(this->direction(1)/norme)*(this->amplitude)*sin(theta);

      Z=(this->amplitude)*cos(theta);

      // Calcul du nouveau couple (I,J) correspondant a X
      //  ( cela  correspond  au  point  de  la  g r i l l e  l e  plus  proche)
      int I, J;

      I=(int(round(X[0]/dy))+Ny)%Ny;
      J=(int(round(X[1]/dx))+Nx)%Nx;
      //cout << "(" << i << ", " << j << ") -> I = " << I << "; J = " << J << "\n";
      // Ajout de la contribution de hauteur de vague Zen (I,J)
      //cout << I << ", " << J << " += " << Z << "\n";
      H(I,J)+=Z;
    }
  }
  return H;
}
