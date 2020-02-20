#include <iostream>

#include "Point.cpp"
#include "Triangle.cpp"

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

void initTriangle() {
    const string title = "Test";
    Point point1, point2, point3;
    point1.setCoords(2,5,3);
    point2.setCoords(20,50,30);
    point3.setCoords(12,54,32);
    // point1.input();
    // point2.input();
    // point3.input();
    Triangle triangle(point1, point2, point3);
    triangle.setTitle("Triangle 1");
    cout << "Side: " << triangle.calculateSideA() << endl;
    cout << "Square: " << to_string(triangle.calculateSquare()) << endl;
    cout << "Perimeter: " << to_string(triangle.calculatePerimeter()) << endl;
}

int main() {
    initTriangle();
    return 0;
}