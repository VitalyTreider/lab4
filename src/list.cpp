#include "list.hpp"

Node::Node() {
  pPrev = this;
  pNext = nullptr;
  m_Data.set(0, 0, 1);
}

Node::Node(Node *prev, const Circle *circle) {
  pPrev = prev;
  prev->pNext = this;
  m_Data = *circle;
}

Node::~Node() {
  pPrev->pNext = pNext;
  pNext->pPrev = pPrev;
}

List::List() {
  Head.pNext = &Tail;
  Tail.pPrev = &Head;
  m_size = 2;
}

void List::add_head(const Circle *circle) { Head.m_Data = *circle; }

void List::add_tail(const Circle *circle) { Tail.m_Data = *circle; }

bool List::delete_element(const Circle *circle) {
  Node *address = &Head;
  for (int i = 0; i < m_size; i++) {
    if (address->m_Data == *circle) {
      address->pPrev->pNext = address->pNext;
      address->pNext->pPrev = address->pPrev;
      return true;
    } else {
      address = address->pNext;
    }
  }
  return false;
}

int List::delete_all(const Circle *circle) {
  Node *address = &Head;
  int cnt = 0;
  for (int i = 0; i < m_size; i++) {
    if (address->m_Data == *circle) {
      address->pPrev->pNext = address->pNext;
      address->pNext->pPrev = address->pPrev;
      cnt++;
    }
    address = address->pNext;
  }
  return cnt;
}

void List::empty_list() {
  Head.pNext = nullptr;
  Tail.pPrev = nullptr;
  m_size = 0;
}
