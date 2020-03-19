#include <iostream>
#include <ctime>
#include <string.h>
#include <cmath>

using namespace std;

//----------------------------------------------------------------
// структуры (классы)
// ----------------------------------------------------------------

struct Point2D {
    double x = 0.0;
    double y = 0.0;
};

struct NamedPoint {
    string name;
    Point2D point;
};

void printPoints(Point2D* test) {
    cout << "(" << test->x << "," << test->y << ")" << endl;
}

void readPoint(Point2D *test) {
    cout << "Enter x, y" << endl;
    cin >> test->x >> test->y;
}

void readNamedPoint(NamedPoint* p) {
    cout << "Enter point name" << endl;
    cin >> p->name;
    readPoint(&p->point);
}

void inputArrayNamedPoints(NamedPoint arr[], int len) {
    for(int i= 0; i < len; i++) {
        readNamedPoint(&arr[i]);
    }
}

void printNamedPoint(NamedPoint p) {
    cout << "Name: " << p.name << endl;
    printPoints(&p.point);
}

// формуля расстояния между двумя точками d=(x2−x1)2+(y2−y1)2
double calculateLengthFromPointToPoint(Point2D *point1, Point2D *point2) {
    double s = fabs((point1->x - point2->x)*2 + (point1->y - point2->y)*2);
    return fabs(sqrt(s));
};

int calculateLengthBetweenPoints(Point2D* list, const int listLen) {
    int fullLen = 0;
    for(int i = 0; i < listLen; i++) {
        for(int j = i + 1; j < listLen; j++) {
            cout.precision(2);
            cout << "point 1: ";
            printPoints(&list[i]);
            cout << "point 2: ";
            printPoints(&list[j]);
            const int distance = calculateLengthFromPointToPoint(&list[i], &list[j]);
            cout << "length: " << distance << endl;
            fullLen += distance;
        }
    }
    return fullLen;
}

Point2D* pointsFactory(const int count = 5) {
    Point2D* pointsList = new Point2D[count];
    for(int i = 0; i < count; ++i) {
        Point2D point;
        readPoint(&point);
        pointsList[i] = point;
    }
    return pointsList;
}

void test() {
    const int LEN = 4;
    Point2D* list = pointsFactory(LEN);
    for(int i = 0; i < LEN; i++) {
        printPoints(&list[i]);
    }
    int fullLen = calculateLengthBetweenPoints(list, LEN);
    cout << "full length = " << fullLen << endl;
    delete[] list;
}

void test2() {
    NamedPoint arr[5];
    for(int i = 0; i < 5; i++) {
        printNamedPoint(arr[i]);
    }
}

int main() {
    test();
    return 0;
}