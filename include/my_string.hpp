#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#include <cstddef>
#include <iostream>
#include <ostream>
class MyString {
private:
  char *str;

public:
  MyString();
  MyString(const char *s);
  ~MyString();
  MyString(const MyString &s);
  MyString &operator=(const MyString &s);
  MyString &operator+=(const MyString &s);
  MyString &operator+=(const char *s);
  friend MyString operator+(const MyString &s1, const MyString &s2);
  friend MyString operator+(const MyString &s1, const char *s2);
  MyString &operator=(MyString &&moved);
  MyString(MyString &&moved);
  friend bool operator==(const MyString &s1, const MyString &s2);
  friend bool operator!=(const MyString &s1, const MyString &s2);
  friend bool operator<=(const MyString &s1, const MyString &s2);
  friend bool operator<(const MyString &s1, const MyString &s2);
  char &operator[](const std::size_t a);
  friend std::ostream &operator<<(std::ostream &stream, const MyString &s);
  friend std::istream &operator>>(std::istream &is, MyString &s);
  char get(int i);
  void set(int i, char c);
  void set_new_string(const char *s);
  void print();
  void read_line(std::istream &is = std::cin);
  int lns();
};

MyString operator+(const MyString &s1, const MyString &s2);
MyString operator+(const MyString &s1, const char *s2);

bool operator==(const MyString &s1, const MyString &s2);
bool operator!=(const MyString &s1, const MyString &s2);
bool operator<=(const MyString &s1, const MyString &s2);
bool operator<(const MyString &s1, const MyString &s2);

std::ostream &operator<<(std::ostream &stream, const MyString &s);
std::istream &operator>>(std::istream &is, MyString &s);

#endif
