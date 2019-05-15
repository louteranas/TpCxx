#include "WaveModel.h"


WaveModel::WaveModel()
:dir(Dvector()), align(0), intensite(0), longueurOnde(0), ajust(0)
{

}
WaveModel::WaveModel(Dvector direction, double alignement, double intens, double longueur, double ajuste)
: dir(direction), align(alignement), intensite(intens), longueurOnde(longueur), ajust(ajuste)
{

}

WaveModel::WaveModel(const WaveModel &wave)
: dir(wave.dir), align(wave.align), intensite(wave.intensite), longueurOnde(wave.longueurOnde), ajust(wave.ajust)
{

}

WaveModel::WaveModel(WaveModel &&wave) {
  std::swap(this->dir, wave.dir);
  std::swap(this->align, wave.align);
  std::swap(this->intensite, wave.intensite);
  std::swap(this->longueurOnde, wave.longueurOnde);
  std::swap(this->ajust, wave.ajust);
  }

Dvector WaveModel::getDir() {
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
