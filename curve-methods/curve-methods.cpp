#include <iostream>

#include "Ellipsis.h"
#include "Section.h"
#include "SineWave.h"

int main() {
  using std::cout;
  //setlocale(LC_ALL, "Russian");

  cout << "Проверка класса Точка\n";
  Point a(1, 5);
  Point b(10, 12);
  cout << "Создана точка а(" << a.getX() << ", " << a.getY() << ")\n";
  cout << "Создана точка b(" << b.getX() << ", " << b.getY() << ")\n";
  cout << "Расстояние между точками: " << Point::getDistance(a, b) << "\n";
}
