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
        Triangle(const int, const Point&, const Point&, const Point&);
        string getTitle();
        Point& getA();
        Point& getB();
        Point& getC();

        void printCoords();
        string coordsToString();
        double calculateSidesLength();
        double calculateSquare();
        double calculatePerimeter();
        bool compareWithTriangleEqual(const Triangle&);
        bool compareWithTriangle(const Triangle&);
};