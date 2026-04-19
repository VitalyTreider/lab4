#include "circle.hpp"
#include "list.hpp"
#include <fstream>
#include <iostream>
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

  std::cout << l << std::endl;
  std::cout << "";
  char ar1[80];
  char ar2[80];
  std::cin >> ar1;
  std::cin >> ar2;

  std::ifstream fin(ar1);
  if (!fin.is_open()) {
    std::cout << "Ошибка открытия файла!" << std::endl;
  }
  List l_from;
  fin >> l_from;
  fin.close();
  std::cout << l_from << std::endl;

  std::ofstream fout(ar2);
  fout << l_from;
  fout.close();

  l.delete_all(&circle1);
  l.empty_list();
  return 0;
}
