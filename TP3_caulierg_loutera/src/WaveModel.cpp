#include "WaveModel.h"

WaveModel::WaveModel(double dir, double align, double intensite, double longueurOnde, double ajust)
{
    this->dir = dir;
    this->align = align;
    this->intensite = intensite;
    this->longueurOnde = longueurOnde;
    this->ajust = ajust;
}

WaveModel::WaveModel(const WaveModel &wave) {
  this->dir = wave.dir;
  this->align = wave.align;
  this->intensite = wave.intensite;
  this->longueurOnde = wave.longueurOnde;
  this->ajust = wave.ajust;
}

WaveModel::WaveModel(WaveModel &&wave) {
  std::swap(this->dir, wave.dir);
  std::swap(this->align, wave.align);
  std::swap(this->intensite, wave.intensite);
  std::swap(this->longueurOnde, wave.longueurOnde);
  std::swap(this->ajust, wave.ajust);
  }
WaveModel& WaveModel::operator=(WaveModel &&wave){
  std::swap(this->dir, wave.dir);
  std::swap(this->align, wave.align);
  std::swap(this->intensite, wave.intensite);
  std::swap(this->longueurOnde, wave.longueurOnde);
  std::swap(this->ajust, wave.ajust);
  return *this;
}

double WaveModel::getDir() {
  return this->dir;
}
double WaveModel::getIntens() {
  return this->intensite;
}
double WaveModel::getAlign() {
  return this->align;
}
double WaveModel::getLong() {
  return this->longueurOnde;
}
double WaveModel::getAjust() {
  return this->ajust;
}

WaveModel::~WaveModel() {

}

WaveModel &WaveModel::operator=(const WaveModel &wave) {
  this->dir = wave.dir;
  this->align = wave.align;
  this->intensite = wave.intensite;
  this->longueurOnde = wave.longueurOnde;
  this->ajust = wave.ajust;
  return *this;
}
