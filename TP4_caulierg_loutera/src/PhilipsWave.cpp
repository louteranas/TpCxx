#include "PhilipsWave.h"

PhilipsWave::PhilipsWave(double amplitude, Dvector windDir, double windSpeed)
{
  this->amplitude = amplitude;
  this->windDir = windDir;
  this->windSpeed = windSpeed;
}

PhilipsWave::PhilipsWave(const PhilipsWave &wave) {
  this->amplitude = wave.amplitude;
  this->windDir = wave.windDir;
  this->windSpeed = wave.windSpeed;
}

PhilipsWave::PhilipsWave(PhilipsWave &&wave) {
  std::swap(this->amplitude, wave.amplitude);
  std::swap(this->windDir, wave.windDir);
  std::swap(this->windSpeed, wave.windSpeed);
  }
PhilipsWave& PhilipsWave::operator=(PhilipsWave &&wave){
  std::swap(this->amplitude, wave.amplitude);
  std::swap(this->windDir, wave.windDir);
  std::swap(this->windSpeed, wave.windSpeed);
  return *this;
}

double PhilipsWave::getAmpl() {
  return this->amplitude;
}
Dvector PhilipsWave::getWindDir() {
  return this->windDir;
}
double PhilipsWave::getWindSpeed() {
  return this->windSpeed;
}

PhilipsWave::~PhilipsWave() {

}

PhilipsWave &PhilipsWave::operator=(const PhilipsWave &wave) {
  this->amplitude = wave.amplitude;
  this->windSpeed = wave.windSpeed;
  this->windDir = wave.windDir;
  return *this;
}

Height PhilipsWave::operator()(double t, Height &H, int Nx, int Ny, double Lx, double Ly) const {
  double kx, ky, reel, imag, phk, phmk, ei, er, wk;
  double pi = 3.14159265358979;
  // random device class instance, source of 'true' randomness for initializing random seed
  std::random_device rd; 

  // Mersenne twister PRNG, initialized with seed from previous random device instance
  std::mt19937 gen(rd()); 
  for(int x = -Nx/2; x < Nx/2; x++) {
    for(int y = -Ny/2; y < Ny/2; y++) {
      kx = 2.0 * pi * (double)x / Lx;
      ky = 2.0 * pi * (double)y / Ly;
      wk = sqrt(9.81 * sqrt(kx*kx + ky*ky));
      //Calcul de Ph(k) et Ph(-k)
      phk = this->ph(kx, ky);
      phmk = this->ph(-kx, -ky);
      //Tirage Epsilon_i et Epsilon_r
      std::normal_distribution<double> d(0, 1); 
      ei = d(gen);
      er = d(gen);
      //calculs partie réelle et imaginaire de htilde
      reel = ((sqrt(phk) + sqrt(phmk))/sqrt(2))*(er*cos(wk*t) - ei*sin(wk*t));
      imag = ((sqrt(phk) - sqrt(phmk))/sqrt(2))*(er*sin(wk*t) + ei*cos(wk*t));
      //Insertion dans htilde
      H.getDvect().getdata()[(y+(Ny/2))*Nx + x+(Nx/2)][0] = reel;
      H.getDvect().getdata()[(y+(Ny/2))*Nx + x+(Nx/2)][1] = imag;
    }
  }
  return H;
}

double PhilipsWave::ph(double kx, double ky) const {
  double norme = kx*kx + ky*ky;
  double ans = this->amplitude / norme; //ans = A/k²
  double scal = pow(kx * this->windDir(0) + ky * this->windDir(1), 2); //scal = |k.w|²
  double expo = exp(-pow(9.81, 2)/(norme * pow(this->windSpeed, 4))); 
  ans = ans * scal * expo;
  return ans;
}