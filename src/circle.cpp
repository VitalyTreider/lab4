#include "circle.hpp"
#include "point.hpp"

Circle::Circle(int x_centr, int y_centr, unsigned int rad) {
  centr.set(x_centr, y_centr);
  radius = rad;
}

Circle::Circle(const Point &p, unsigned int rad) {
  centr = p;
  radius = rad;
}

Circle::Circle(const Circle &circle) {
  centr = circle.centr;
  radius = circle.radius;
}

void Circle::set_rad(unsigned rad) { radius = rad; }

void Circle::set_center(int x_centr, int y_centr) {
  centr.set(x_centr, y_centr);
}

void Circle::set_center(const Point &p) { centr = p; }

void Circle::set(int x_centr, int y_centr, unsigned int rad) {
  centr.set(x_centr, y_centr);
  radius = rad;
}

void Circle::set(const Point &p, unsigned int rad) {
  centr = p;
  radius = rad;
}

Point &Circle::get_center() { return centr; }

unsigned int Circle::get_rad() { return radius; }

Circle &Circle::operator=(const Circle &circle) {
  centr = circle.centr;
  radius = circle.radius;
  return *this;
}

Circle::~Circle() {
  centr.set(0, 0);
  radius = 0;
}
