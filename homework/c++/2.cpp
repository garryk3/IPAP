#include <iostream>
#include <cmath>

using namespace std;
// нахождение введенных координат относительно круга, нарисованного в центре координат радиусом 1,
// разделенного на части параболой, прямой, и системой координат (рис в description)
// y = x*x; парабола
// x*x + y*y = 1 радиус круга
// y = -|x| нижний треугольник

bool detectedOut(double x, double y) {
    return x * x + y * y > 1;
}
bool detectZero(double x, double y) {
    return x == 0 && y == 0;
}
bool detectM1Area(double x, double y) {
    return y >= 0 && y >= x * x;
}
bool detectM2Area(double x, double y) {
    return x >= 0 && y <= 0 && y >= -abs(x);
}
bool detectM3Area(double x, double y) {
    return x <= 0 && y <= 0;
}
bool detectM4Area(double x, double y) {
    return (y >= 0 && y <= x * x) || (x >= 0 && y <= 0 && y <= -abs(x));
}

string handleResult(bool includedArea, string name) {
    return includedArea ? name + " " : "";
}

void printResult(double x, double y) {
    bool isNull = detectZero(x, y);
    if(isNull) {
        cout << "Вы попали в начало координат, точка принадлежит всем зонам" << endl;
        return;
    }

    bool isOut = detectedOut(x, y);
    if(isOut) {
        cout << "Вы попали вне круга" << endl;
        return;
    }

    bool hasM1 = detectM1Area(x, y);
    bool hasM2 = detectM2Area(x, y);
    bool hasM3 = detectM3Area(x, y);
    bool hasM4 = detectM4Area(x, y);

    if(!hasM1 && !hasM2 && !hasM3 && !hasM4) {
        cout << "Сбой программы!" << endl;
    }

    cout << "Вы попали в следующие зоны: " << handleResult(hasM1, "M1") << handleResult(hasM2, "M2") << handleResult(hasM3, "M3") << handleResult(hasM4, "M4") << endl; 
}

int main() {
    cout << "enter float x and y" << endl;

    double x, y;

    cin >> x >> y;

    cout << "x = " << x << ", y = " << y << endl;

    printResult(x, y);

    return 0;
}