#ifndef LAB1_STRLIB_H
#define LAB1_STRLIB_H

#include <cstring>
#include <iostream>

size_t getLength(const char *str);

class MyString {
  char *str;
  size_t length;

public:
  MyString() : str(nullptr), length(0) {}

  explicit MyString(const char *str_t) {
    length = getLength(str_t);
    str = new char[length + 1];
    strcpy(str, str_t);
  }

  MyString(const MyString &other) {
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);
  }

  void print() {
    for (int i = 0; i < length; ++i) {
      printf("%c", str[i]);
    }
  }

  MyString &operator=(const MyString &other) {
    if (this == &other)
      return *this;
    delete[] str;

    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);

    return *this;
  }

  MyString operator+(const MyString &other) const {
    MyString result;
    result.length = length + other.length;
    result.str = new char[result.length + 1];

    strcpy(result.str, str);
    strcat(result.str, other.str);

    return result;
  }

  bool operator==(const MyString &other) const {
    if (strcmp(str, other.str) == 0) {
      return true;
    } else
      return false;
  }

  bool operator!=(const MyString &other) const { return !(*this == other); }

  MyString &operator+=(const MyString &other) {
    char *temp = new char[length + other.length + 1];
    strcpy(temp, str);
    strcat(temp, other.str);

    delete[] str;

    str = temp;
    length += other.length;

    return *this;
  }

  char operator[](int index) const{
    if (index < 0 || index > length - 1)
      throw std::invalid_argument(
          "You must to refer only to existing elements");
    return str[index];
  }

  MyString operator()(int start, int end) const {
    if (start < 0 || start >= length || end < 0 || end >=length || start > end){
      throw std::invalid_argument("Please input correct values");
    }

    int temp_length = end - start + 1;
    char *temp = new char[temp_length + 1];

    for (int i = 0; i<temp_length; i++) {
      temp[i] = str[start + i];
    }
    temp[temp_length] = '\0';

    MyString tempStr(temp);
    delete[] temp;
    return tempStr;
  }

  friend std::ostream &operator<<(std::ostream &os, const MyString &str_t) {
    os << str_t.str;
    return os;
  }

  ~MyString() { delete[] str; }
};

#endif // LAB1_STRLIB_H
