#include "strlib.h"

size_t getLength(const char *str){
  size_t len = 0;
  for (int i = 0; str[i] != '\0' ; ++i) {
    len++;
  }
  return len;
}

void copyStr(char *str1, const char *str2){
  for (int i = 0; str1[i] != '\0' ; ++i) {
    str1[i] = str2[i];
  }
}

int main(){
  MyString str1("str1"), str2("str2"), str3;
  str3 = str1 + str2;
  MyString str4("str4");
  MyString str5("str5");
//  str1.print();
//  std::cout << '\n';
//  str2.print();
//  std::cout << '\n';
//  str3.print();
//  std::cout << '\n';

  str4 += str5;

  str4.print();
  std::cout << "\n";

  std::cout << "Ishodnaya stroka: " << str4 << std::endl << "Obrezanaya stroka: " << str4(0,1)<< std::endl;

//  std::cout << "str[i] = " << str4[8];

//  if(str5 == str4){
//    std::cout << "Strs equal" << std::endl;
//  }
//
//  if(str3 != str1){
//    std::cout << "Strs differ" << std::endl;
//  }

  return 0;
}