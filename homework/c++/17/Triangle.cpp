#include <math.h>
#include "Triangle.h"

Triangle::Triangle(const int title, const Point& A, const Point& B, const Point& C) {
    this->title = title;
    this->A = A;
    this->B = B;
    this->C = C;
};
string Triangle::getTitle() {
    return title;
};
Point& Triangle::getA() {
    return A;
};
Point& Triangle::getB() {
    return B;
};
Point& Triangle::getC() {
    return C;
};

void Triangle::printCoords() {
    cout << coordsToString() << endl;
};
string Triangle::coordsToString() {
    return "Point A: " + this->A.getCoords() + ", Point B: " + this->B.getCoords() + ", Point C: " + this->C.getCoords();
};
double Triangle::calculateSidesLength() {
    // p=\sqrt{(x_1-x_2)^2+(y_1-y_2)^2+(z_1-z_2)^2}
    double sideA = sqrt((A.getX() - B.getX()) * 2 + (A.getY() - B.getY()) * 2 + (A.getZ() - B.getZ));
    double sideB = sqrt((A.getX() - C.getX()) * 2 + (A.getY() - C.getY()) * 2 + (A.getZ() - C.getZ));
    double sideA = sqrt((C.getX() - B.getX()) * 2 + (C.getY() - B.getY()) * 2 + (C.getZ() - B.getZ));
};

double Triangle::calculateSquare() {
    return;
};
double Triangle::calculatePerimeter() {};
bool Triangle::compareWithTriangleEqual(const Triangle&) {};
bool Triangle::compareWithTriangle(const Triangle&) {};