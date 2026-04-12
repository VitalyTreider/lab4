#ifndef LIST_HPP
#define LIST_HPP
#include "circle.hpp"
#include "point.hpp"
#include <iostream>

class Node {
public:
  Node *pPrev;
  Node *pNext;
  Circle m_Data;

  Node();
  Node(Node *prev, const Circle *circle);
  ~Node();
};

class List {
private:
  Node Head;
  Node Tail;
  size_t m_size;

public:
  List();
  void add_head(const Circle *circle);
  void add_tail(const Circle *circle);
  bool delete_element(const Circle *circle);
  int delete_all(const Circle *circle);
  void empty_list();
  // anything else
};

#endif
