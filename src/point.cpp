#include "point.hpp"

void Point::set_x(int x0) { x = x0; }

void Point::set_y(int y0) { y = y0; }

void Point::set(int x0, int y0) {
  x = x0;
  y = y0;
}

int Point::get_x() { return x; }

int Point::get_y() { return y; }

Point &Point::operator=(const Point &p) {
  x = p.x;
  y = p.y;
  return *this;
}
