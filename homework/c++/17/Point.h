#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Point {
    private:
        int x;
        int y;
        int z;
    public:
        string getCoords();
        void setCoords(int, int, int);
        int getX();
        int getY();
        int getZ();
        void input();
        double distanceTo(Point &);
        Point();
        Point(int, int, int);
        ~Point();
};