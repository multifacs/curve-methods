#pragma once
#include "Curve.h"

// Класс синусоиды
class SineWave : public Curve {
 private:
  double A;  // Амплитуда
  double T;  // Период
  double C;  // Смещение по оси Y

 public:
  // В конструкторе вызываем конструктор предка
  SineWave() : Curve() {
    A = 0;
    T = 0;
    C = 0;
    maxT = 3 * M_PI;  // Задаем максимальный t как 3*PI
  };
  SineWave(double A, double T, double C) : Curve() {
    this->A = A;
    this->T = T;
    this->C = C;
    maxT = 3 * M_PI;
  };

  // Геттеры и сеттеры
  double getA() const { return A; };
  double getT() const { return T; };
  double getC() const { return C; };
  void setA(double A) { this->A = A; };
  void setT(double T) { this->T = T; };
  void setC(double C) { this->C = C; };

  // Добавляем возможность изменять min max t
  void setMinT(double t) { minT = t; };
  void setMaxT(double t) { maxT = t; };

  // Переопределяем функции получения x, y, x', y'
  double getX(double t) override { return t; }
  double getY(double t) override { return A + sin(M_PI * 2 / T * t) + C; }
  double getXDash(double t) override { return 1; }
  double getYDash(double t) override {
    return 2 * M_PI * cos(2 * M_PI * t / T) / T;
  }
};