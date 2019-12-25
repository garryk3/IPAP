#include <iostream>

using namespace std;

// y = x*x; парабола
// x*x + y*y = 1 радиус круга
// y = -|x| нижний треугольник

bool detectedOut(int x, int y) {
    return x * x + y * y > 1;
}
bool detectM1Area(int x, int y) {
    bool isXInArea = x >= y / x;
    bool isYInArea = y >= x * x;
    return isXInArea && isYInArea;
}
bool detectM2Area(int x, int y) {
    if(y >= 0 || x <= 0) {
        return false;
    }
    bool isXInArea = x <= -y;
    bool isYInArea = y <= -x;
    return isXInArea && isYInArea;
}
bool detectM3Area(int x, int y) {
    bool isXInArea = x <= 0;
    bool isYInArea = y <= 0;
    return isXInArea && isYInArea;
}
bool detectM4Area(int x, int y) {
    bool isXInArea = (x <= 0 && x >= y/x) || (x >= 0 && x >= y/x) || (x >= 0 && x >= -y);
    bool isYInArea = (y >= 0 && y <= x*x) || (y <= 0 && y >= -x);
    return isXInArea && isYInArea;
}
bool detectZero(int x, int y) {
    return x == 0 && y == 0;
}
string handleResult(bool includedArea, string name) {
    return includedArea ? name + " " : "";
}

void printResult(int x, int y) {
    bool isOut = detectedOut(x, y);
    if(isOut) {
        cout << "Вы попали вне круга";
        return;
    }
    bool isNull = detectZero(x, y);
    if(isNull) {
        cout << "Вы попали в начало координат, точка принадлежит всем зонам";
        return;
    }

    bool hasM1 = detectM1Area(x, y);
    bool hasM2 = detectM1Area(x, y);
    bool hasM3 = detectM1Area(x, y);
    bool hasM4 = detectM1Area(x, y);

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