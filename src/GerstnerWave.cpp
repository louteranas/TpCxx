#include "GerstnerWave.h"

GerstnerWave::GerstnerWave(double amplitude, double phase, double direction, double frequence)
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
double GerstnerWave::getDir() {
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
