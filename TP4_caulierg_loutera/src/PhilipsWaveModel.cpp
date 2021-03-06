#include "PhilipsWaveModel.h"

PhilipsWaveModel::PhilipsWaveModel(Dvector dir, double align, double intensite, double longueurOnde, double ajust, double lx, double ly, int nx, int ny, const vector <PhilipsWave> waves)
: WaveModel(dir, align, intensite, longueurOnde, ajust), lx(lx), ly(ly), nx(nx), ny(ny), waves(waves)
{

}

PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel &wave)
: WaveModel(wave), lx(wave.lx), ly(wave.ly), nx(wave.nx), ny(wave.ny), waves(wave.waves)
{

}
Height PhilipsWaveModel::operator()(double t)
{
  Height h(this->lx, this->ly, this->nx, this->ny);
  Height htemp(this->lx, this->ly, this->nx, this->ny);
  h.fill(0.0);
  for(PhilipsWave& wave : this->waves){
    h+=wave(t, htemp, this->nx, this->ny, this->lx, this->ly);
    // cout << "h00 : " << h(0, 0) << "\n";
  }
  return h;
}
//
// PhilipsWaveModel::PhilipsWaveModel(PhilipsWaveModel &&waveModel) {
//   std::swap(this->lx, waveModel.lx);
//   std::swap(this->ly, waveModel.ly);
//   std::swap(this->nx, waveModel.nx);
//   std::swap(this->ny, waveModel.ny);
//   std::swap(this->waves, waveModel.waves);
//   }
// PhilipsWaveModel& PhilipsWaveModel::operator=(PhilipsWaveModel &&waveModel){
//   std::swap(this->lx, waveModel.lx);
//   std::swap(this->ly, waveModel.ly);
//   std::swap(this->nx, waveModel.nx);
//   std::swap(this->ny, waveModel.ny);
//   std::swap(this->waves, waveModel.waves);
//   return *this;
// }

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

Dvector PhilipsWaveModel::getDir() const {
  return this->dir;
}
double PhilipsWaveModel::getIntens() const {
  return this->intensite;
}
double PhilipsWaveModel::getAlign() const {
  return this->align;
}
double PhilipsWaveModel::getLong() const {
  return this->longueurOnde;
}
double PhilipsWaveModel::getAjust() const {
  return this->ajust;
}


PhilipsWaveModel::~PhilipsWaveModel() {

}

PhilipsWaveModel &PhilipsWaveModel::operator=(const PhilipsWaveModel &waveModel) {
  this->dir = waveModel.getDir();
  this->intensite = waveModel.getIntens();
  this->align = waveModel.getAlign();
  this->longueurOnde = waveModel.getLong();
  this->ajust = waveModel.getAjust();
  this->lx = waveModel.lx;
  this->ly = waveModel.ly;
  this->nx = waveModel.nx;
  this->ny = waveModel.ny;
  this->waves = waveModel.waves;
  return *this;
}
