#include <math.h>
#include "Triangle.h"

Triangle::Triangle(Point& A, Point& B, Point& C) {
    this->A = A;
    this->B = B;
    this->C = C;
};
string Triangle::getTitle() {
    return title;
};
void Triangle::setTitle(const string title) {
    this->title = title;
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
double Triangle::calculateSideA() {
    return sqrt(fabs((A.getX() - B.getX()) * 2 + (A.getY() - B.getY()) * 2 + (A.getZ() - B.getZ())));
};

double Triangle::calculateSideB() {
    // p=\sqrt{(x_1-x_2)^2+(y_1-y_2)^2+(z_1-z_2)^2}
    return sqrt(fabs((A.getX() - B.getX()) * 2 + (A.getY() - B.getY()) * 2 + (A.getZ() - B.getZ())));
};

double Triangle::calculateSideC() {
    return sqrt(fabs((C.getX() - B.getX()) * 2 + (C.getY() - B.getY()) * 2 + (C.getZ() - B.getZ())));
};

double Triangle::calculateSquare() {
    double halfPerimetr = calculatePerimeter() / 2; 
    return sqrt(fabs(halfPerimetr * (halfPerimetr - calculateSideA()) * (halfPerimetr - calculateSideB() * (halfPerimetr - calculateSideC()))));
};
double Triangle::calculatePerimeter() {
    return calculateSideA() + calculateSideB() + calculateSideC();
};
bool Triangle::compareWithTriangleEqual(const Triangle&) {};
bool Triangle::compareWithTriangle(const Triangle&) {};