#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

// Класс точки
class Point {
 private:
  double x;
  double y;

 public:
  // Конструкторы
  Point() {
    x = 0;
    y = 0;
  }
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
  // Сеттеры и геттеры
  double setX(double x) { this->x = x; };
  double setY(double y) { this->y = y; };
  double getX() const { return x; };
  double getY() const { return y; };

  // Статический метод получения расстояния между точками
  static double getDistance(Point a, Point b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
  }

  virtual ~Point(){};
};