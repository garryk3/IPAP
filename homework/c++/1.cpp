#include <iostream>;

using namespace std;

int transformNegative(int num) {
    if(num < 0) {
        return -num;
    }
    return num;
}

int calculateModulo(int a, int b) {
    a = transformNegative(a);
    b = transformNegative(b);

    while (a != 0 && b != 0) {
        if(a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    
    return a + b;
}

int main() {
    int x, y;

    cout << "Введите первое число" << endl;

    cin >> x;

    cout << "Введите второе число" << endl;

    cin >> y;

    if(x == 0 || y == 0) {
        cout << "Операция с нулем не имеет смысла" << endl;
        return 0;
    }

    int result = calculateModulo(x, y);

    cout << "Наибольший делитель двух чисел это " << result << endl;

    return 0;
}