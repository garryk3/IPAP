#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Test {
    public:
        string name;
        void print();
        void setForce(int strong) {
            force = strong;
        };
        int getForce() {
            return force;
        };
    private:
        int force;
};

void Test::print() {
    cout << name << " " << force << endl;
}

int main() {
    Test test;
    test.name = "Test";
    test.setForce(3);
    test.print();
    return 0;
}