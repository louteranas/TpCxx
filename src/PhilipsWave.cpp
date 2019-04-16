#include "PhilipsWave.h"

PhilipsWave::PhilipsWave(double amplitude, double phase, double direction, double frequence)
{
    this->amplitude = amplitude;
    this->phase = phase;
    this->direction = direction;
    this->frequence = frequence;
}

PhilipsWave::PhilipsWave(const PhilipsWave &wave) {
  this->amplitude = wave.amplitude;
  this->phase = wave.phase;
  this->direction = wave.direction;
  this->frequence = wave.frequence;
}

PhilipsWave::PhilipsWave(PhilipsWave &&wave) {
  std::swap(this->amplitude, wave.amplitude);
  std::swap(this->phase, wave.phase);
  std::swap(this->direction, wave.direction);
  std::swap(this->frequence, wave.frequence);
  }
PhilipsWave& PhilipsWave::operator=(PhilipsWave &&wave){
  std::swap(this->amplitude, wave.amplitude);
  std::swap(this->phase, wave.phase);
  std::swap(this->direction, wave.direction);
  std::swap(this->frequence, wave.frequence);
  return *this;
}

double PhilipsWave::getAmpl() {
  return this->amplitude;
}
double PhilipsWave::getDir() {
  return this->direction;
}
double PhilipsWave::getPhase() {
  return this->phase;
}
double PhilipsWave::getFreq() {
  return this->frequence;
}

PhilipsWave::~PhilipsWave() {

}

PhilipsWave &PhilipsWave::operator=(const PhilipsWave &wave) {
  this->amplitude = wave.amplitude;
  this->phase = wave.phase;
  this->direction = wave.direction;
  this->frequence = wave.frequence;
  return *this;
}
