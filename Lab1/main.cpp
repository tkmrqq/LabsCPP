#include <cstdio>
#include <iostream>

#define PI 3.14159265358979

using namespace std;

class Circle {
  double radius = 0;

public:
  double getRadius() { return radius; }

  void setRadius(double radius_t) { radius = radius_t; }

  double findSquare() { return (this->radius * this->radius * PI); }

  double findLength() { return (2 * this->radius * PI); }
};

double check() {
  double radius;
  try {
    cout << "Input value: ";
    cin >> radius;
    if (radius < 0 || cin.fail() || cin.peek() != '\n') {
      fflush(stdin);
      cin.clear();
      throw invalid_argument("Error! Invalid Input! Enter double or int value");
    }
  } catch (const invalid_argument &e) {
    cerr << e.what() << endl;
  }
  return radius;
}

void menu() {
  Circle circle;
  int choice;

  while (true) {
    cout << "==========\nMenu:\n1) Set Radius\n2) Show Radius\n3) Show "
            "Length\n4) Show Square\n5) Exit\n";
    cin >> choice;
    switch (choice) {
    case 1:
      circle.setRadius(check());
    case 2:
      cout << "Current Radius = " << circle.getRadius() << endl;
      break;
    case 3:
      cout << "Length of circle = " << circle.findLength() << endl;
      break;
    case 4:
      cout << "Square of circle = " << circle.findSquare() << endl;
      break;
    case 5:
      exit(EXIT_SUCCESS);
    default:
      cout << "Invalid input!";
    }
  }
}

int main() { menu(); }
