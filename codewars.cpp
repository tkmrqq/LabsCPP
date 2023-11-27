#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

bool is_isogram(std::string str) {

  for (char &i : str) {
    i = (char)tolower(i);
  }

  for (size_t i = 0; i < str.size() - 1; ++i) {
    for (size_t j = i + 1; j < str.size(); ++j) {
      if (str[i] == str[j])
        return false;
      else
        continue;
    }
  }
  return true;
}

std::string highAndLow(const std::string &numbers) {
  std::vector<int> numArr;
  std::istringstream iss(numbers);

  int num;
  while (iss >> num) {
    numArr.push_back(num);
  }

  int minValue = *std::min_element(numArr.begin(), numArr.end());
  int maxValue = *std::max_element(numArr.begin(), numArr.end());

  std::string result;
  result += std::to_string(maxValue) + ' ' + std::to_string(minValue);
  return result;
}

// (1 2 3 4 5)

int main() {
  //  std::string str;
  //  str = "moose";
  //  std::cout << is_isogram(str);
  std::string numbers = "1 2 -3 4 5";
  std::cout << highAndLow(numbers);
}