#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

//----------------------------------------------------------------
// структуры (классы)
// ----------------------------------------------------------------

int main() {
    struct {
        int a;
        double b;
    } elem0, elem1;

    elem0.a = 10;
    elem0.b = 34.9;

    cout << "Enter fields a, b: " << endl;
    cin >> elem1.a >> elem1.b;
    return 0;
}