#include "circle.hpp"
#include "list.hpp"
#include "point.hpp"

int main() {
  Circle circle1(0, 0, 1);
  Circle circle2(0, 0, 1);
  Circle circle3(0, 0, 3);
  Circle circle4(0, 0, 4);
  List l;
  l.add_head(&circle2);
  l.add_head(&circle3);
  l.add_head(&circle4);
  l.add_tail(&circle1);
  l.sort();
  l.delete_all(&circle1);
  l.empty_list();
  return 0;
}
