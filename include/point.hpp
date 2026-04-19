#ifndef POINT_HPP
#define POINT_HPP

class Point {
private:
  double x;
  double y;

public:
  Point() : x(0), y(0) {}
  Point(double x0, double y0) : x(x0), y(y0) {};
  void set_x(double x0);
  void set_y(double y0);
  void set(double x0, double y0);
  double get_x();
  double get_y();
  bool almostEqual(double a, double b);
  Point &operator=(const Point &p);
  bool operator==(const Point &p);
};

#endif
