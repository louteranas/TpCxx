#include "GerstnerWaveModel.h"

GerstnerWaveModel::GerstnerWaveModel(Dvector dir, double align, double intensite, double longueurOnde, double ajust, double lx, double ly, int nx, int ny, const vector <GerstnerWave> waves)
: WaveModel(dir, align, intensite, longueurOnde, ajust), lx(lx), ly(ly), nx(nx), ny(ny), waves(waves)
{

}

GerstnerWaveModel::GerstnerWaveModel(const GerstnerWaveModel &wave) 
: WaveModel(wave), lx(wave.lx), ly(wave.ly), nx(wave.nx), ny(wave.ny), waves(wave.waves)
{

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

Dvector GerstnerWaveModel::getDir() const {
  return this->dir;
}
double GerstnerWaveModel::getIntens() const {
  return this->intensite;
}
double GerstnerWaveModel::getAlign() const {
  return this->align;
}
double GerstnerWaveModel::getLong() const {
  return this->longueurOnde;
}
double GerstnerWaveModel::getAjust() const {
  return this->ajust;
}

void GerstnerWaveModel::add(GerstnerWave wave){
  (this->waves).push_back(wave);
}

Height GerstnerWaveModel::operator()(double t){
  Height h(this->lx, this->ly, this->nx, this->ny);
  Height htemp(this->lx, this->ly, this->nx, this->ny);
  h.fill(0.0);
  for(GerstnerWave& wave : this->waves){
    h+=wave(t, htemp, this->nx, this->ny, this->lx, this->ly);
    // cout << "h00 : " << h(0, 0) << "\n";
  }
  return h;
}

GerstnerWaveModel::~GerstnerWaveModel() {

}
