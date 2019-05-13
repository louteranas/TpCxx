#include "PhilipsWave.h"

PhilipsWave::PhilipsWave(double amplitude, double windDir, double windSpeed, int Lx, int Ly, int Nx, int Ny)
{
  this->amplitude = amplitude;
  this->windDir = windDir;
  this->windSpeed = windSpeed;
  this->Lx = Lx;
  this->Ly = Ly;
  this->Nx = Nx;
  this->Ny = Ny;
}

PhilipsWave::PhilipsWave(const PhilipsWave &wave) {
  this->amplitude = wave.amplitude;
  this->windDir = wave.windDir;
  this->windSpeed = wave.windSpeed;
  this->Lx = wave.Lx;
  this->Ly = wave.Ly;
  this->Nx = wave.Nx;
  this->Ny = wave.Ny;
}

PhilipsWave::PhilipsWave(PhilipsWave &&wave) {
  std::swap(this->amplitude, wave.amplitude);
  std::swap(this->windDir, wave.windDir);
  std::swap(this->windSpeed, wave.windSpeed);
  std::swap(this->Lx, wave.Lx);
  std::swap(this->Ly, wave.Ly);
  std::swap(this->Nx, wave.Nx);
  std::swap(this->Ny, wave.Ny);
  }
PhilipsWave& PhilipsWave::operator=(PhilipsWave &&wave){
  std::swap(this->amplitude, wave.amplitude);
  std::swap(this->windDir, wave.windDir);
  std::swap(this->windSpeed, wave.windSpeed);
  std::swap(this->Lx, wave.Lx);
  std::swap(this->Ly, wave.Ly);
  std::swap(this->Nx, wave.Nx);
  std::swap(this->Ny, wave.Ny);
  return *this;
}

double PhilipsWave::getAmpl() {
  return this->amplitude;
}
double PhilipsWave::getWindDir() {
  return this->windDir;
}
double PhilipsWave::getWindSpeed() {
  return this->windSpeed;
}
int PhilipsWave::getLx() {
  return this->Lx;
}
int PhilipsWave::getLy() {
  return this->Ly;
}
int PhilipsWave::getNx() {
  return this->Nx;
}
int PhilipsWave::getNy() {
  return this->Ny;
}

PhilipsWave::~PhilipsWave() {

}

PhilipsWave &PhilipsWave::operator=(const PhilipsWave &wave) {
  this->amplitude = wave.amplitude;
  this->windSpeed = wave.windSpeed;
  this->windDir = wave.windDir;
  this->Lx = wave.Lx;
  this->Ly = wave.Ly;
  this->Nx = wave.Nx;
  this->Ny = wave.Ny;
  return *this;
}
