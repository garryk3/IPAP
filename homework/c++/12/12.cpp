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

void printPoints(Point2D *test) {
    cout << "(" << test->x << "," << test->y << ")" << endl;
}

void readPoint(Point2D *test) {
    cout << "Enter x, y" << endl;
    cin >> test->x >> test->y;
}

// формуля расстояния между двумя точками d=(x2−x1)2+(y2−y1)2
double calculateLengthFromPointToPoint(Point2D *point1, Point2D *point2) {
    double s = (point1->x - point2->x)*2 + (point1->y - point2->y)*2;
    return fabs(sqrt(s));
};

int calculateLengthBetweenPoints(Point2D *list, const int listLen) {
    int fullLen = 0;
    for(int i = 0; i < listLen; i++) {
        for(int j = i + 1; j < listLen; j++) {
            cout.precision(2);
            cout << "point 1: ";
            printPoints(&list[i]);
            cout << "point 2: ";
            printPoints(&list[j]);
            cout << " , length: " << calculateLengthFromPointToPoint(&list[i], &list[j]) << endl;
            fullLen += calculateLengthFromPointToPoint(&list[i], &list[j]);
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
    Point2D* list = pointsFactory(5);
    for(int i = 0; i < 5; i++) {
        printPoints(&list[i]);
    }
    int fullLen = calculateLengthBetweenPoints(list, 5);
    cout << "full length = " << fullLen << endl;
}

int main() {
    test();
    return 0;
}