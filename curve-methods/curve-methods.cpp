#include <iostream>

#include "Ellipsis.h"
#include "Section.h"
#include "SineWave.h"

int main() {
  using std::cout;
  // setlocale(LC_ALL, "Russian");

  cout << "Проверка класса Точка\n";
  Point a(1, 5);
  Point b(10, 12);
  cout << "Создана точка а(" << a.getX() << ", " << a.getY() << ")\n";
  cout << "Создана точка b(" << b.getX() << ", " << b.getY() << ")\n";
  cout << "Расстояние между точками: " << Point::getDistance(a, b) << "\n";

  cout << "\n";

  cout << "Проверка класса Отрезок\n";
  Section s(a, b);
  cout << "Создан отрезок с началом (" << s.getA().getX() << ", "
       << s.getA().getY() << ") и концом (" << s.getB().getX() << ", "
       << s.getB().getY() << ")\n";
  cout << "Информация об области определения t: min = " << s.getTInfo().getX()
       << ", max = " << s.getTInfo().getY() << "\n";
  cout << "Длина отрезка: " << s.getLength(1000) << "\n";
  double t = 0.3;
  cout << "Получаем точку с параметром t = " << t << ": ("
       << s.getPoint(t).getX() << ", " << s.getPoint(t).getY() << ")\n";
  Point p1(4, 4);
  cout << "Получаем проекцию точки (" << p1.getX() << ", " << p1.getY()
       << "): (" << s.getProjection(p1).getX() << ", "
       << s.getProjection(p1).getY() << ")\n";

  cout << "\n";

  cout << "Проверка класса Эллипс\n";
  Point c(5, 5);
  Ellipsis e(c, 3, 5, 0.2 * M_PI);
  cout << "Создан эллипс с центром (" << e.getC().getX() << ", "
       << e.getC().getY() << "), осью А = " << e.getA()
       << ", осью B = " << e.getB() << ", phi = " << e.getPhi() << "\n";
  cout << "Информация об области определения t: min = " << e.getTInfo().getX()
       << ", max = " << e.getTInfo().getY() << "\n";
  cout << "Длина эллипса: " << e.getLength(1000) << "\n";
  t = 0.3;
  cout << "Получаем точку с параметром t = " << t << ": ("
       << e.getPoint(t).getX() << ", " << e.getPoint(t).getY() << ")\n";
  Point p2(4, 4);
  cout << "Получаем проекцию точки (" << p2.getX() << ", " << p2.getY()
       << "): (" << e.getProjection(p2).getX() << ", "
       << e.getProjection(p2).getY() << ")\n";

  cout << "\n";

  cout << "Проверка класса Синусоида\n";
  SineWave sw(3, 5, 1);
  cout << "Создана синусоида с амлитудой = " << sw.getA()
       << ", периодом = " << sw.getT() << ", смещением = " << sw.getC() << "\n";
  cout << "Информация об области определения t: min = " << sw.getTInfo().getX()
       << ", max = " << sw.getTInfo().getY() << "\n";
  sw.setMinT(-1);
  sw.setMaxT(4 * M_PI);
  cout << "Изменяем t: min = " << sw.getTInfo().getX()
       << ", max = " << sw.getTInfo().getY() << "\n";
  cout << "Длина синусоиды: " << sw.getLength(1000) << "\n";
  t = 0.3;
  cout << "Получаем точку с параметром t = " << t << ": ("
       << sw.getPoint(t).getX() << ", " << sw.getPoint(t).getY() << ")\n";
  Point p3(4, 4);
  cout << "Получаем проекцию точки (" << p3.getX() << ", " << p3.getY()
       << "): (" << sw.getProjection(p3).getX() << ", "
       << sw.getProjection(p3).getY() << ")\n";
}
