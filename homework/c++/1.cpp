#include <iostream>;

using namespace std;

int calculateModulo(int a, int b) {
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

    if(x < 0) {
        x = -x;
    }
    if(y < 0) {
        y = -y;
    }

    int result = calculateModulo(x, y);

    cout << "Наибольший делитель двух чисел это " << result << endl;

    return 0;
}