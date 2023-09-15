#include "header.h"

double check() {
  double radius;
  while(true){
    try {
      cout << "Input value: ";
      cin >> radius;
      if (radius < 0 || cin.fail() || cin.peek() != '\n') {
        fflush(stdin);
        cin.clear();
        radius = 0;
        throw invalid_argument("Error! Invalid Input! Enter double or int value(positive value); Try again!");
      }
      else break;
    } catch (const invalid_argument &e) {
      cerr << e.what() << endl;
    }
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
    if(!cin.good()){
      cin.clear();
      fflush(stdin);
    }
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

int main() {
  int n;
  Circle *circle = new Circle[n];
  delete[] circle;
  
  menu();
  return 0;
}
