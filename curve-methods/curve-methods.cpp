#include <iostream>

#include "Ellipsis.h"
#include "Section.h"
#include "SineWave.h"

int main() {
  using std::cout;
  setlocale(LC_ALL, "Russian");

  cout << "�������� ������ �����\n";
  Point a(1, 5);
  Point b(10, 12);
  cout << "������� ����� �(" << a.getX() << ", " << a.getY() << ")\n";
  cout << "������� ����� b(" << b.getX() << ", " << b.getY() << ")\n";
  cout << "���������� ����� �������: " << Point::getDistance(a, b) << "\n";
}
