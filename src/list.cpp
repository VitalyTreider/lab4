#include "list.hpp"
#include "circle.hpp"
#include "my_string.hpp"

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

Node *List::split(Node *head) {
  Node *slow = head;
  Node *fast = head;

  while (fast->pNext && fast->pNext->pNext) {
    slow = slow->pNext;
    fast = fast->pNext->pNext;
  }
  Node *second = slow->pNext;
  slow->pNext = nullptr;
  if (second)
    second->pPrev = nullptr;

  return second;
}

Node *List::merge(Node *l1, Node *l2) {
  if (!l1)
    return l2;
  if (!l2)
    return l1;

  if (l1->m_Data.get_rad() < l2->m_Data.get_rad()) {
    l1->pNext = merge(l1->pNext, l2);
    if (l1->pNext)
      l1->pNext->pPrev = l1;
    l1->pPrev = nullptr;
    return l1;
  } else {
    l2->pNext = merge(l1, l2->pNext);
    if (l2->pNext)
      l2->pNext->pPrev = l2;
    l2->pPrev = nullptr;
    return l2;
  }
}

Node *List::mergeSort(Node *head) {
  if (!head || !head->pNext)
    return head;

  Node *second = split(head);

  head = mergeSort(head);
  second = mergeSort(second);

  return merge(head, second);
}

void List::sort() {
  if (m_size < 2)
    return;

  Node *first = Head.pNext;

  Tail.pPrev->pNext = nullptr;

  Node *newHead = mergeSort(first);

  Head.pNext = newHead;
  newHead->pPrev = &Head;

  Node *cur = newHead;
  while (cur->pNext) {
    cur = cur->pNext;
  }
  cur->pNext = &Tail;
  Tail.pPrev = cur;

  // if (m_size < 2)
  //   return;
  //
  // bool flag;
  // do {
  //   flag = false;
  //   Node *current = Head.pNext;
  //
  //   while (current != &Tail && current->pNext != &Tail) {
  //     if (current->m_Data.get_rad() > current->pNext->m_Data.get_rad()) {
  //       Circle temp = current->m_Data;
  //       current->m_Data = current->pNext->m_Data;
  //       current->pNext->m_Data = temp;
  //       flag = true;
  //     }
  //     current = current->pNext;
  //   }
  // } while (flag);
}

std::ostream &operator<<(std::ostream &stream, const List &l) {
  Node *current = l.Head.pNext;
  int cnt = 0;
  while (current != &l.Tail) {
    stream << cnt << " element. Radius: " << current->m_Data.get_rad()
           << "; Centr: " << current->m_Data.get_center().get_x() << " ; "
           << current->m_Data.get_center().get_y() << "\n";
    cnt++;
    current = current->pNext;
  }
  return stream;
}

std::istream &operator>>(std::istream &is, List &l) {
  int rad, x, y;
  int cnt;
  MyString temp;
  char semicolon;
  char dot;

  while (is >> cnt >> rad >> x >> y) {
    Circle *circle = new Circle(Point(x, y), rad);
    l.add_tail(circle);
  }

  return is;
}
