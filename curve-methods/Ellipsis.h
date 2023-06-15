#pragma once
#include "Curve.h"

// Класс эллипса
class Ellipsis : public Curve {
 private:
  Point c;     // Центр эллипса
  double a;    // Ось A
  double b;    // Ось B
  double phi;  // Наклон эллипса в радианах

 public:
  // В конструкторе вызываем конструктор предка
  Ellipsis() : Curve() {
    a = 0;
    b = 0;
    phi = 0;
    maxT = 2 * M_PI;
  };
  Ellipsis(Point c, double a, double b, double phi) : Curve() {
    this->c = c;
    this->a = a;
    this->b = b;
    this->phi = phi;
  };

  // Переопределяем функции получения x, y, x', y'
  double getX(double t) override {
    return c.getX() + a * cos(t) * cos(phi) - b * sin(t) * sin(phi);
  }
  double getY(double t) override {
    return c.getY() + a * cos(t) * sin(phi) + b * sin(t) * cos(phi);
  }
  double getXDash(double t) override {
    return (-1) * a * sin(t) * cos(phi) - b * cos(t) * sin(phi);
  }
  double getYDash(double t) override {
    return (-1) * a * sin(t) * sin(phi) - b * cos(t) * cos(phi);
  }
};