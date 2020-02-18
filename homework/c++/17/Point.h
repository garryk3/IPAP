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
        void setCoords(int x, int y, int z);
        int getX();
        int getY();
        int getZ();
        double distanceTo(Point &other);
        Point();
        ~Point();
};