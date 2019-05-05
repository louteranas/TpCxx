#include "GerstnerWaveModel.h"

GerstnerWaveModel::GerstnerWaveModel(double lx, double ly, int nx, int ny, const vector <GerstnerWave> waves)
{
    this->lx = lx;
    this->ly = ly;
    this->nx = nx;
    this->ny = ny;
    this->waves = waves;
}

GerstnerWaveModel::GerstnerWaveModel(const GerstnerWaveModel &waveModel) {
  this->lx = waveModel.lx;
  this->ly = waveModel.ly;
  this->nx = waveModel.nx;
  this->ny = waveModel.ny;
  this->waves = waveModel.waves;
}

GerstnerWaveModel::GerstnerWaveModel(GerstnerWaveModel &&waveModel) {
  std::swap(this->lx, waveModel.lx);
  std::swap(this->ly, waveModel.ly);
  std::swap(this->nx, waveModel.nx);
  std::swap(this->ny, waveModel.ny);
  std::swap(this->waves, waveModel.waves);
  }
GerstnerWaveModel& GerstnerWaveModel::operator=(GerstnerWaveModel &&waveModel){
  std::swap(this->lx, waveModel.lx);
  std::swap(this->ly, waveModel.ly);
  std::swap(this->nx, waveModel.nx);
  std::swap(this->ny, waveModel.ny);
  std::swap(this->waves, waveModel.waves);
  return *this;
}

int GerstnerWaveModel::getNx() {
  return this->nx;
}
int GerstnerWaveModel::getNy() {
  return this->ny;
}
double GerstnerWaveModel::getLx() {
  return this->lx;
}
double GerstnerWaveModel::getLy() {
  return this->ly;
}
const vector <GerstnerWave> GerstnerWaveModel::getWaves() {
  return this->waves;
}

void GerstnerWaveModel::add(GerstnerWave wave){
  (this->waves).push_back(wave);
}

Height GerstnerWaveModel::operator()(double t){
  Height h(this->lx, this->ly, this->nx, this->ny);
  h.fill(0.0);
  for(GerstnerWave& wave : this->waves){
    h+=wave(t, h, this->nx, this->ny, this->lx, this->ly);
  }
  return h;
}

GerstnerWaveModel::~GerstnerWaveModel() {

}

GerstnerWaveModel &GerstnerWaveModel::operator=(const GerstnerWaveModel &waveModel) {
  this->lx = waveModel.lx;
  this->ly = waveModel.ly;
  this->nx = waveModel.nx;
  this->ny = waveModel.ny;
  this->waves = waveModel.waves;
  return *this;
}
