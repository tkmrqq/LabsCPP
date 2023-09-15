#ifndef LAB1_HEADER_H
#define LAB1_HEADER_H

#include <iostream>

#define PI 3.14159265358979

using namespace std;

class Circle {
  double radius = 0;

public:

  Circle() {}

  Circle(const Circle& other) {
    radius = other.radius;
  }

  ~Circle() {}

  double getRadius() { return radius; }

  void setRadius(double radius_t) { radius = radius_t; }

  double findSquare() { return (this->radius * this->radius * PI); }

  double findLength() { return (2 * this->radius * PI); }

};

#endif // LAB1_HEADER_H
