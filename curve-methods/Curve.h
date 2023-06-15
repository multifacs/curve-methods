#pragma once

#include "Point.h"

class Curve {
 private:
  double minT;
  double maxT;

 public:
  Curve() {
    minT = 0;
    maxT = 1;
  };
  Curve(double minT, double maxT) {
    this->minT = minT;
    this->maxT = maxT;
  }

  virtual double getX(double t) { return 0; };
  virtual double getY(double t) { return 0; };
  virtual double getXDash(double t) { return 0; };
  virtual double getYDash(double t) { return 0; };

  Point getTInfo() { return Point(minT, maxT); };

  double getDerivative(double t) {
    if (getXDash(t) == 0) return 0;
    return getYDash(t) / getXDash(t);
  }
  double getLength(int n) {
    double len = 0;
    double sec = (maxT - minT) / (double)n;
    for (int i = 0; i < n - 1; i++) {
      double a = sec * i;
      double b = sec * (i + 1);
      Point p1(getX(a), getY(a));
      Point p2(getX(b), getY(b));
      len += Point::getDistance(p1, p2);
    }
    return len;
  };
  Point getProjection(Point p, int n){
    Point closestPoint(getX(minT), getY(minT));
    double sec = (maxT - minT) / (double)n;
    for (int i = 0; i < n; i++) {
      double t = sec * i;
      Point temp(getX(t), getY(t));

      if (Point::getDistance(p, temp) < Point::getDistance(p, closestPoint)) {
        closestPoint = temp;
      }
    }
    return closestPoint;
  };
};