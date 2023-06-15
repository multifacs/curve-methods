#pragma once
#include "Curve.h"

// ����� ���������
class SineWave : public Curve {
 private:
  double A;  // ���������
  double T;  // ������
  double C;  // �������� �� ��� Y

 public:
  // � ������������ �������� ����������� ������
  SineWave() : Curve() {
    A = 0;
    T = 0;
    C = 0;
    maxT = 3 * M_PI;  // ������ ������������ t ��� 3*PI
  };

  // ��������� ����������� �������� min max t
  void setMinT(double t) { minT = t; };
  void setMaxT(double t) { maxT = t; };

  // �������������� ������� ��������� x, y, x', y'
  double getX(double t) override { return t; }
  double getY(double t) override { return A + sin(M_PI * 2 / T * t) + C; }
  double getXDash(double t) override { return 1; }
  double getYDash(double t) override {
    return 2 * M_PI * cos(2 * M_PI * t / T) / T;
  }
};