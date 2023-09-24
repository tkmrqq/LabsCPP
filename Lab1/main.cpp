#include "header.h"

double check() {
  double radius;
  cout << "Input radius: ";
  while (true) {
    cin >> radius;
    if (!cin.good() || radius <= 0) {
      cout << "Invalid value, try again!" << endl;
      cin.clear();
      fflush(stdin);
    } else return radius;
  }
}

double inputAngle(){
  cout << "Input angle of the sector: ";
  double angle;
  while(true){
    cin >> angle;
    if (angle < 0) angle *=-1;
    if(!cin.good()){
      cout << "Invalid value, try again!" << endl;
      cin.clear();
      fflush(stdin);
    }
    else return angle;
  }
}

void menu(Circle circle) {
  int choice;
  double radius;
  double angle;

  while (true) {
    cout << "==========\nMenu:\n1) Change radius\n2) Show radius\n3) Find "
            "length\n4) Find arc length\n5) Find square\n6) Find area of the sector\n7) Exit\n";
    cin >> choice;
    if (!cin.good() || choice <= 0 || choice > 5) {
      cin.clear();
      fflush(stdin);
    }

    switch (choice) {
    case 1:
      radius = check();
      circle.setRadius(radius);
      break;
    case 2:
      cout << "Current Radius = " << circle.getRadius() << endl;
      break;
    case 3:
      cout << "Length of circle = " << circle.findLength() << endl;
      break;
    case 4:
      angle = inputAngle();
      cout << "Length of arc = " << circle.findLength(angle) << endl;
      break;
    case 5:
      cout << "Square of circle = " << circle.findSquare() << endl;
      break;
    case 6:
      angle = inputAngle();
      cout << "Area of the sector = " << circle.findSquare(angle) << endl;
      break;
    case 7:
      exit(EXIT_SUCCESS);
    default:
      cout << "Invalid input!";
    }
  }
}

int main() {
  double radius = check();
  Circle circle(radius);
  Circle circle3 = circle + 30;
  menu(circle3);
  return 0;
}
