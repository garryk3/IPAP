#include <iostream>

using namespace std;

int main() {
    int n;
    float f;
    float result;

    cout << "Enter f: ";
    cin >> f;
    cout << "Enter n: ";
    cin >> n;

    if (f == 0 && n == 0) {
        cout << "zero result" << endl;
        return 0;
    }

    if (f == 0 || f == 1) {
        result = f;
    } else {
        result = 1;

        if (n >= 0) {
            for (int i = 0; i < n; i++) {
                result = result * f;
            }
        } else {
            for (int i = 0; i > n; i--) {
                result = result / f;
            }
        }
    }

    cout << "res = " << result << endl;

    return 0;
}