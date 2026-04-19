#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "point.hpp"

class Circle {
private:
  Point centr;
  double radius;

public:
  Circle() : radius(1) {}
  Circle(const Circle &circle);
  Circle(double x_centr, double y_centr, double rad);
  Circle(const Point &p, double rad);
  void set_rad(double rad);
  void set_center(double x_centr, double y_centr);
  void set_center(const Point &p);
  void set(double x_centr, double y_centr, double rad);
  void set(const Point &p, double rad);
  Point &get_center();
  double get_rad();
  bool almostEqual(double a, double b);
  Circle &operator=(const Circle &circle);
  bool operator==(const Circle &circle);
  ~Circle();
};

#endif
