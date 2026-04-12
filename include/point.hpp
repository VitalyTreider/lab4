#ifndef POINT_HPP
#define POINT_HPP

class Point {
private:
  int x;
  int y;

public:
  Point() : x(0), y(0) {}
  Point(int x0, int y0) : x(x0), y(y0) {};
  void set_x(int x0);
  void set_y(int y0);
  void set(int x0, int y0);
  int get_x();
  int get_y();
  Point &operator=(const Point &p);
  bool operator==(const Point &p);
};

#endif
