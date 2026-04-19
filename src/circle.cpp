#include "circle.hpp"
#include "point.hpp"
#include <algorithm>
#include <cmath>
// todo: double values
Circle::Circle(double x_centr, double y_centr, double rad) {
  centr.set(x_centr, y_centr);
  radius = rad;
}

Circle::Circle(const Point &p, double rad) {
  centr = p;
  radius = rad;
}

Circle::Circle(const Circle &circle) {
  centr = circle.centr;
  radius = circle.radius;
}

void Circle::set_rad(double rad) { radius = rad; }

void Circle::set_center(double x_centr, double y_centr) {
  centr.set(x_centr, y_centr);
}

void Circle::set_center(const Point &p) { centr = p; }

void Circle::set(double x_centr, double y_centr, double rad) {
  centr.set(x_centr, y_centr);
  radius = rad;
}

void Circle::set(const Point &p, double rad) {
  centr = p;
  radius = rad;
}

Point &Circle::get_center() { return centr; }

double Circle::get_rad() { return radius; }
// todo: machine epsilon

bool Circle::almostEqual(double a, double b) {
  double eps = 1e-9;
  return std::abs(a - b) <=
         eps * std::max(1.0, std::max(std::abs(a), std::abs(b)));
}

Circle &Circle::operator=(const Circle &circle) {
  centr = circle.centr;
  radius = circle.radius;
  return *this;
}

bool Circle::operator==(const Circle &circle) {
  return (centr == circle.centr && almostEqual(radius, circle.radius));
}

Circle::~Circle() {
  centr.set(0, 0);
  radius = 0;
}
