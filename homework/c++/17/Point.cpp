#include "Point.h"

using namespace std;

Point::Point() {
    cout << "init" << endl;
};

Point::Point(int x, int y, int z) {
    setCoords(x, y, z);
};

Point::~Point() {
    cout << "delete Point" << endl;
};

string Point::getCoords() {
    return "x: " + to_string(x) + " y: " + to_string(y) + " z: " + to_string(z);
};

void Point::setCoords(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
};

int Point::getX() {
    return this->x;
}

int Point::getY() {
    return this->y;
}

int Point::getZ() {
    return this->z;
}

double Point::distanceTo(Point &other) {
    int dd =  x - other.getX();
    return sqrt(fabs((x - other.getX()) * (y - other.getY()) * (z - other.getZ())));
};

void Point::input() {
    cout << "Enter coordinates x, y, z: ";
    cin >> x >> y >> z;
}