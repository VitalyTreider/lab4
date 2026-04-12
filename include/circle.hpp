#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "point.hpp"

class Circle {
private:
  Point centr;
  unsigned int radius;

public:
  Circle() : radius(1) {}
  Circle(const Circle &circle);
  Circle(int x_centr, int y_centr, unsigned int rad);
  Circle(const Point &p, unsigned int rad);
  void set_rad(unsigned rad);
  void set_center(int x_centr, int y_centr);
  void set_center(const Point &p);
  void set(int x_centr, int y_centr, unsigned int rad);
  void set(const Point &p, unsigned int rad);
  Point &get_center();
  unsigned int get_rad();
  Circle &operator=(const Circle &circle);
  bool operator==(const Circle &circle);
  ~Circle();
};

#endif
