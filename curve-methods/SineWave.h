#pragma once
#include "Curve.h"

class SineWave : public Curve {
 private:
  double A;
  double T;
  double C;

 public:
  SineWave() : Curve() {
    A = 0;
    T = 0;
    C = 0;
    maxT = 3 * M_PI;
  };

  void setMinT(double t) { minT = t; };
  void setMaxT(double t) { maxT = t; };

  double getX(double t) override {
    return t;
  }
  double getY(double t) override {
    return A + sin(M_PI * 2 / T * t) + C;
  }
  double getXDash(double t) override {
    return 1;
  }
  double getYDash(double t) override {
    return 2 * M_PI * cos(2 * M_PI * t / T) / T;
  }
};