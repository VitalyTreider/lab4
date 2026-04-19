#include "point.hpp"
#include <algorithm>
#include <cmath>
void Point::set_x(double x0) { x = x0; }

void Point::set_y(double y0) { y = y0; }

void Point::set(double x0, double y0) {
  x = x0;
  y = y0;
}

double Point::get_x() { return x; }

double Point::get_y() { return y; }

bool Point::almostEqual(double a, double b) {
  double eps = 1e-9;
  return std::abs(a - b) <=
         eps * std::max(1.0, std::max(std::abs(a), std::abs(b)));
}

Point &Point::operator=(const Point &p) {
  x = p.x;
  y = p.y;
  return *this;
}

bool Point::operator==(const Point &p) {
  return almostEqual(x, p.x) && almostEqual(y, p.y);
}
