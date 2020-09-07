#include <iostream>

using namespace std;

template <class T> void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
};

template <class T, int N>
void swap() { }

void main() {};