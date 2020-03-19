#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Point3D {
    private:
        int x;
        int y;
        int z;
    public:
        Point3D();
        void setCoords(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        int getX() {
            return x;
        }
        int getY() {
            return y;
        }
        int getZ() {
            return z;
        }
        void print();
        string getCoords();
};

Point3D::Point3D() {
    cout << "Init class Point3D" << endl;
};

void Point3D::print() {
    cout << "Point3D coords is " << getCoords() << endl;
};

string Point3D::getCoords() {
    return "x: " + to_string(getX()) + " , y: " + to_string(getY()) + " , z: " + to_string(getZ());
}

class ChildPoint: public Point3D {
    public:
        ChildPoint();
        ~ChildPoint();
};

ChildPoint::ChildPoint() {
    cout << "ChildPoint constructor init" << endl;
};

ChildPoint::~ChildPoint() {
    cout << "ChildPoint destructor" << endl;
};

int main() {
    Point3D point;
    ChildPoint* child = new ChildPoint();
    point.setCoords(2, 5, 8);
    point.print();
    delete child;
    return 0;
}