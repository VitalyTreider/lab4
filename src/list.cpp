#include "list.hpp"
#include "circle.hpp"

Node::Node() {
  pPrev = nullptr;
  pNext = nullptr;
  m_Data.set(0, 0, 1);
}

Node::Node(Node *prev, const Circle *circle) {
  pPrev = prev;
  pNext = nullptr;
  if (circle != nullptr) {
    m_Data = *circle;
  } else {
    m_Data.set(0, 0, 1);
  }
}

Node::~Node() {
  if (pPrev != nullptr) {
    pPrev->pNext = pNext;
  }
  if (pNext != nullptr) {
    pNext->pPrev = pPrev;
  }
}

List::List() {
  Head.pNext = &Tail;
  Head.pPrev = nullptr;
  Tail.pPrev = &Head;
  Tail.pNext = nullptr;
  m_size = 0;
}

void List::add_head(const Circle *circle) {
  if (circle == nullptr)
    return;

  Node *newNode = new Node(nullptr, circle);
  newNode->pNext = Head.pNext;
  newNode->pPrev = &Head;

  if (Head.pNext != nullptr) {
    Head.pNext->pPrev = newNode;
  }
  Head.pNext = newNode;
  m_size++;
}

void List::add_tail(const Circle *circle) {
  if (circle == nullptr)
    return;

  Node *newNode = new Node(nullptr, circle);
  newNode->pPrev = Tail.pPrev;
  newNode->pNext = &Tail;

  if (Tail.pPrev != nullptr) {
    Tail.pPrev->pNext = newNode;
  }
  Tail.pPrev = newNode;
  m_size++;
}

bool List::delete_element(const Circle *circle) {
  if (circle == nullptr)
    return false;

  Node *current = Head.pNext;

  while (current != &Tail) {
    if (current->m_Data == *circle) {

      delete current;
      m_size--;
      return true;
    }
    current = current->pNext;
  }
  return false;
}

int List::delete_all(const Circle *circle) {
  if (circle == nullptr)
    return 0;

  Node *current = Head.pNext;
  int cnt = 0;

  while (current != &Tail) {
    Node *next = current->pNext;
    if (current->m_Data == *circle) {

      delete current;
      cnt++;
      m_size--;
    }
    current = next;
  }
  return cnt;
}

void List::empty_list() {
  Node *current = Head.pNext;

  while (current != &Tail) {
    Node *next = current->pNext;
    delete current;
    current = next;
  }

  Head.pNext = &Tail;
  Tail.pPrev = &Head;
  m_size = 0;
}

void List::sort() {
  if (m_size < 2)
    return;

  bool flag;
  do {
    flag = false;
    Node *current = Head.pNext;

    while (current != &Tail && current->pNext != &Tail) {
      if (current->m_Data.get_rad() > current->pNext->m_Data.get_rad()) {
        Circle temp = current->m_Data;
        current->m_Data = current->pNext->m_Data;
        current->pNext->m_Data = temp;
        flag = true;
      }
      current = current->pNext;
    }
  } while (flag);
}
