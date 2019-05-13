#include "PhilipsWaveModel.h"

PhilipsWaveModel::PhilipsWaveModel(double lx, double ly, int nx, int ny, const vector <PhilipsWave> waves)
{
    this->lx = lx;
    this->ly = ly;
    this->nx = nx;
    this->ny = ny;
    this->waves = waves;
}

PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel &waveModel) {
  this->lx = waveModel.lx;
  this->ly = waveModel.ly;
  this->nx = waveModel.nx;
  this->ny = waveModel.ny;
  this->waves = waveModel.waves;
}

PhilipsWaveModel::PhilipsWaveModel(PhilipsWaveModel &&waveModel) {
  std::swap(this->lx, waveModel.lx);
  std::swap(this->ly, waveModel.ly);
  std::swap(this->nx, waveModel.nx);
  std::swap(this->ny, waveModel.ny);
  std::swap(this->waves, waveModel.waves);
  }
PhilipsWaveModel& PhilipsWaveModel::operator=(PhilipsWaveModel &&waveModel){
  std::swap(this->lx, waveModel.lx);
  std::swap(this->ly, waveModel.ly);
  std::swap(this->nx, waveModel.nx);
  std::swap(this->ny, waveModel.ny);
  std::swap(this->waves, waveModel.waves);
  return *this;
}

int PhilipsWaveModel::getNx() {
  return this->nx;
}
int PhilipsWaveModel::getNy() {
  return this->ny;
}
double PhilipsWaveModel::getLx() {
  return this->lx;
}
double PhilipsWaveModel::getLy() {
  return this->ly;
}
const vector <PhilipsWave> PhilipsWaveModel::getWaves() {
  return this->waves;
}

void PhilipsWaveModel::add(PhilipsWave wave){
  (this->waves).push_back(wave);
}


PhilipsWaveModel::~PhilipsWaveModel() {

}

PhilipsWaveModel &PhilipsWaveModel::operator=(const PhilipsWaveModel &waveModel) {
  this->lx = waveModel.lx;
  this->ly = waveModel.ly;
  this->nx = waveModel.nx;
  this->ny = waveModel.ny;
  this->waves = waveModel.waves;
  return *this;
}
