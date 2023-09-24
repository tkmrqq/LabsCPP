#ifndef LAB1_HEADER_H
#define LAB1_HEADER_H

#include <iostream>

#define PI 3.14159265358979

using namespace std;

double check();

class Circle {

  double radius = 0;

public:

  Circle(double radius_t){
    radius = radius_t;
  }

  ~Circle() {}

  double getRadius() { return radius; }

  void setRadius(double radius_t) { radius = radius_t; }

  double findSquare() { return (this->radius * this->radius * PI); }

  double findSquare(double angle) { return ((this->radius * this->radius * PI / 360) * angle);}

  double findLength() { return (2 * this->radius * PI); }

  double findLength(double angle) {return (2* this->radius * PI / 180 * angle);}

  Circle operator + (const Circle& circle) const {
    return Circle(radius + circle.radius);
  }

  Circle operator & (const Circle& circle) const {
    return Circle(radius + circle.radius);
  }

};

void menu(Circle circle);

#endif // LAB1_HEADER_H
