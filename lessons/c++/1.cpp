#include <iostream>

using  namespace std;

int calculate(int a, int b) {
    while (a!=b) {
        if(a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main() {
    cout << "enter numbers";
    int x, y, res;

    cin >> x >> y;
    res = calculate(x, y);

    return res;
}