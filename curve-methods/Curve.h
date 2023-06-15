#pragma once

#include "Point.h"

// Базовый класс кривой
class Curve {
 protected:
  double minT;  // Минимальная граница t
  double maxT;  // Максимальная граница t

 public:
  // Конструктор
  Curve() {
    minT = 0;
    maxT = 1;
  };

  // Виртуальные методы получения x, y, x', y'
  virtual double getX(double t) { return 0; };
  virtual double getY(double t) { return 0; };
  virtual double getXDash(double t) { return 0; };
  virtual double getYDash(double t) { return 0; };

  // Метод получения точки на кривой
  Point getPoint(double t) { return Point(getX(t), getY(t)); }
  // Метод получения информации об области определения t
  Point getTInfo() { return Point(minT, maxT); };

  // Метод получения точки на кривой
  double getDerivative(double t) {
    if (getXDash(t) == 0)
      return 0;  // Если производная x == 0, производной не существует
    return getYDash(t) / getXDash(t);  // По формуле
  }
  // Метод получения длины кривой
  // Принимает на вход число разделений
  double getLength(int n = 100) {
    double len = 0;  // Переменная для длины
    double sec = (maxT - minT) / (double)n;  // Длина одного разделения
    for (int i = 0; i < n - 1; i++) {  // В цикле по разделениям
      double a = sec * i;              // Начало отрезка
      double b = sec * (i + 1);        // Конец отрезка
      Point p1(getX(a), getY(a));      // Первая точка
      Point p2(getX(b), getY(b));      // Вторая точка
      len += Point::getDistance(p1, p2);  // Прибаляем длину отрезка
    }
    return len;  // Возвращаем длину
  };
  // Метод получения проекции точки на кривой
  // Принимает на вход точку и число разделений
  Point getProjection(Point p, int n = 100) {
    Point closestPoint(getX(minT),
                       getY(minT));  // Переменная для ближайшей точки
    double sec = (maxT - minT) / (double)n;  // Длина разделения
    for (int i = 0; i < n; i++) {  // В цикле по разделениям
      double t = sec * i;          // Текущий t
      Point temp(getX(t), getY(t));  // Точка для проверки
      // Если длина до текущей точки меньше длины ближайшей точки
      if (Point::getDistance(p, temp) < Point::getDistance(p, closestPoint)) {
        closestPoint = temp;  // Перезаписываем ближайшую точку
      }
    }
    return closestPoint;  // Возвращаем ближайшую точку
  };
};