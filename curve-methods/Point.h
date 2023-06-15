#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

class Point {
 private:
  double x;
  double y;

 public:
  Point() {
    x = 0;
    y = 0;
  }
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
  double setX(double x) { this->x = x; };
  double setY(double y) { this->y = y; };
  double getX() const { return x; };
  double getY() const { return y; };

  static double getDistance(Point a, Point b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
  }

  virtual ~Point(){};
};