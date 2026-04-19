#ifndef LIST_HPP
#define LIST_HPP
#include "circle.hpp"
#include <iostream>
#include <ostream>

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
  Node *split(Node *head);
  Node *merge(Node *l1, Node *l2);
  Node *mergeSort(Node *head);

public:
  List();
  void add_head(const Circle *circle);
  void add_tail(const Circle *circle);
  bool delete_element(const Circle *circle);
  int delete_all(const Circle *circle);
  void empty_list();
  void sort(); // todo: merge sort
  friend std::ostream &operator<<(std::ostream &stream, const List &l);
  friend std::istream &operator>>(std::istream &is, List &l);
};

std::ostream &operator<<(std::ostream &stream, const List &l);
std::istream &operator>>(std::istream &is, List &l);

#endif
