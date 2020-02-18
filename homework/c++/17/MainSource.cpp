#include <iostream>

#include "Point.cpp"

using namespace std;

class NamedPoint: public Point {
    protected:
        string name;
    public:
        NamedPoint();
        ~NamedPoint();
};

int main() {
    Point point;
    Point point2;
    point.setCoords(1, 2, 3);
    point2.setCoords(10, 20, 30);
    double distance = point.distanceTo(point2);
    cout << point.getCoords() << endl;
    cout << point2.getCoords() << endl;
    cout << "distance: " << to_string(distance) << endl;
    return 0;
}