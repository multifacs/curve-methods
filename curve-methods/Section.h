#pragma once
#include "Curve.h"

class Section : public Curve {
 private:
   Point a;
   Point b;

  public:
    Section() : Curve() {};

    double getX(double t) override {
      return a.getX() + t * (b.getX() - a.getX());
    }
    double getY(double t) override {
      return a.getY() + t * (b.getY() - a.getY());
    }
    double getXDash(double t) override {
      return b.getX() - a.getX();
    }
    double getYDash(double t) override {
      return b.getY() - a.getY();
    }
};