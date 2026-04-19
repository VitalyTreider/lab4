#include "my_string.hpp"
#include <cstring>
#include <iostream>
#include <istream>
#include <ostream>

MyString::MyString() {
  str = new char[1];
  str[0] = '\0';
}

MyString::MyString(const char *s) {
  str = new char[strlen(s) + 1];
  strcpy(str, s);
}

MyString::MyString(const MyString &s) {
  str = new char[strlen(s.str) + 1];
  strcpy(str, s.str);
}

MyString &MyString::operator=(const MyString &s) {
  if (this != &s) {
    delete[] str;

    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
  }
  return *this;
}

MyString &MyString::operator+=(const MyString &s) {
  char *str1 = new char[strlen(str) + strlen(s.str) + 1];
  strcpy(str1, str);
  strcat(str1, s.str);
  delete[] str;
  str = new char[strlen(str1) + 1];
  strcpy(str, str1);
  delete[] str1;
  return *this;
}

MyString &MyString::operator+=(const char *s) {
  char *str1 = new char[strlen(str) + strlen(s) + 1];
  strcpy(str1, str);
  strcat(str1, s);
  delete[] str;
  str = new char[strlen(str1) + 1];
  strcpy(str, str1);
  delete[] str1;
  return *this;
}

MyString operator+(const MyString &s1, const MyString &s2) {
  char *str1 = new char[strlen(s1.str) + strlen(s2.str) + 1];
  strcpy(str1, s1.str);
  strcat(str1, s2.str);
  MyString s3(str1);
  delete[] str1;
  return s3;
}

MyString operator+(const MyString &s1, const char *s2) {
  char *str1 = new char[strlen(s1.str) + strlen(s2) + 1];
  strcpy(str1, s1.str);
  strcat(str1, s2);
  MyString s3(str1);
  delete[] str1;
  return s3;
}

MyString &MyString::operator=(MyString &&moved) {
  if (&moved != this) {
    delete[] str;
    str = moved.str;
    moved.str = nullptr;
  }
  return *this;
}

MyString::MyString(MyString &&moved) : str(moved.str) { moved.str = nullptr; }

bool operator==(const MyString &s1, const MyString &s2) {
  return std::strcmp(s1.str, s2.str) == 0;
}

bool operator!=(const MyString &s1, const MyString &s2) {
  return std::strcmp(s1.str, s2.str) != 0;
}

bool operator<=(const MyString &s1, const MyString &s2) {
  return std::strcmp(s1.str, s2.str) <= 0;
}

bool operator<(const MyString &s1, const MyString &s2) {
  return std::strcmp(s1.str, s2.str) < 0;
}

char &MyString::operator[](const std::size_t a) { return str[a]; }

std::ostream &operator<<(std::ostream &stream, const MyString &s) {
  stream << s.str;
  return stream;
};

std::istream &operator>>(std::istream &is, MyString &s) {
  s.read_line(is);
  return is;
}

MyString::~MyString() { delete[] str; }

char MyString::get(int i) { return str[i]; };

void MyString::set(int i, char c) { str[i] = c; }

void MyString::set_new_string(const char *s) {
  delete[] str;
  str = new char[strlen(s) + 1];
  strcpy(str, s);
}

void MyString::print() { std::cout << "String: " << str << std::endl; }

void MyString::read_line(std::istream &is) {
  delete[] str;

  char k;
  if (is.peek() == '\n') {
    is.ignore();
  }

  int cap = 10;
  str = new char[cap];
  int ln = 0;

  char c;
  while (is.get(c) && c != '\n') {
    if (ln + 1 > cap) {
      cap = cap * 2;
      char *str_new = new char[cap];
      for (int i = 0; i < ln; i++) {
        str_new[i] = str[i];
      }
      delete[] str;
      str = str_new;
    }
    str[ln++] = c;
  }
  str[ln] = '\0';
}

int MyString::lns() { return strlen(str); }
