#include <iostream>

#include "Point.cpp"

using namespace std;

class NamedPoint: public Point {
    protected:
        string name;
    public:
        void input() {
            cout << "Name: " << name;
            cin >> name;
            Point::input();
        };
        NamedPoint() {
            cout << "Init named point: " << name << endl;
        };
        NamedPoint(string name, int x, int y, int z) : Point(x, y, z) {
            this->name = name;
        };
        ~NamedPoint() {
            cout << "NamedPoint with name " << name << " deleted" << endl;
        };
};

int main() {
    Point point;
    Point point2;
    NamedPoint point3;
    point.input();
    point3.input();
    double distance = point.distanceTo(point2);
    cout << "distance: " << to_string(distance) << endl;
    return 0;
}