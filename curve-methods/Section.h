#pragma once
#include "Curve.h"

// Класс отрезка
class Section : public Curve {
 private:
  Point a;  // Начало отрезка
  Point b;  // Конец отрезка

 public:
  // В конструкторе вызываем конструктор предка
  Section() : Curve(){};
  Section(Point a, Point b) : Curve() {
    this->a = a;
    this->b = b;
  };

  // Геттеры и сеттеры
  Point getA() const { return a; };
  Point getB() const { return b; };
  void setA(Point a) { this->a = a; };
  void setB(Point b) { this->b = b; };

  // Переопределяем функции получения x, y, x', y'
  double getX(double t) override {
    return a.getX() + t * (b.getX() - a.getX());
  }
  double getY(double t) override {
    return a.getY() + t * (b.getY() - a.getY());
  }
  double getXDash(double t) override { return b.getX() - a.getX(); }
  double getYDash(double t) override { return b.getY() - a.getY(); }
};
