#pragma once

#include <string>
#include "Point.h"

using namespace std;

class Triangle {
    private:
        string title;
        Point A;
        Point B;
        Point C;
    public:
        Triangle(Point&, Point&, Point&);
        string getTitle();
        void setTitle(const string);
        Point& getA();
        Point& getB();
        Point& getC();

        void printCoords();
        string coordsToString();
        double calculateSideA();
        double calculateSideB();
        double calculateSideC();
        double calculateSquare();
        double calculatePerimeter();
        bool compareWithTriangleEqual(const Triangle&);
        bool compareWithTriangle(const Triangle&);
};

inline bool operator==(const Triangle& x, const Triangle& y) {
    // compare logic
};