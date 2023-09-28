#include "strlib.h"

void testEqual(MyString str, const MyString &str2) {
  std::cout << "First string: " << str << std::endl;
  std::cout << "Second string: " << str2 << std::endl;
  str = str2;
  std::cout << "Str: " << str;
}

void testSum(const MyString &str, const MyString &str2) {
  MyString str3;
  std::cout << "First string: " << str << std::endl;
  std::cout << "Second string: " << str2 << std::endl;

  str3 = str + str2;

  std::cout << "Result string: " << str3;
}

void testEqSum(MyString str, const MyString &str2) {
  std::cout << "First string: " << str << std::endl;
  std::cout << "Second string: " << str2 << std::endl;

  str += str2;

  std::cout << "Result string: " << str;
}

void testEq(const MyString& str) {
  MyString str2 ("Hello");

  if (str == str2) {
    std::cout << "Strings are the same" << std::endl;
  }

  if (str != str2) {
    std::cout << "Strings are different" << std::endl;
  }

}

void testSquares(const MyString& str){
  std::cout << "Current string " << str << std::endl;

  std::cout << "Input index: ";
  int index;
  std::cin >> index;

  std::cout << "Str: " << str[index];
}

void testBrackets(const MyString& str){
  std::cout << "Current string " << str << std::endl;
  std::cout << "Input interval (for example: 0 3)" << std::endl;
  int start, end;
  std::cin >> start >> end;
  std::cout << "Interval: " << str(start, end);

}

void menu(const MyString &str, const MyString &str2) {
  int choice;
  do {
    std::cout << "\n1) =\n2) +\n3) +=\n4) ==\n5) !=\n6) []\n7) ()" << std::endl;
    std::cin >> choice;
    switch (choice) {
    case 1:
      testEqual(str, str2);
      break;
    case 2:
      testSum(str, str2);
      break;
    case 3:
      testEqSum(str, str2);
      break;
    case 4:
      testEq(str);
      break;
    case 5:
      testEq(str2);
      break;
    case 6:
      testSquares(str);
      break;
    case 7:
      testBrackets(str2);
      break;
    default:
      break;
    }
  }
  while (std::cin.good());
}

int main(){
  MyString str("Hello");
  MyString str2("World!");
  menu(str, str2);
  return 0;
}