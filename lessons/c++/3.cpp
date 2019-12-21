#include <iostream>;

using namespace std;

int printCounter (int max) {
    int counter = 1;

    while (counter <= max) {
        cout << "counter: " << counter << endl;
        counter++;
    }

    return 0;
}

int main() {
    int a, b, c, max;

    cout << "Введите 1е значение (А) : ";
    cin >> a;

    cout << "Введите 2е значение (B) : ";
    cin >> b;

    cout << "Введите 3е значение (C) : ";
    cin >> c;

    max = a;

    if(max < b) {
        max = b;
    }
    if(max < c) {
        max = c;
    }

    printCounter(max);

    cout << "Максимум: " << max << endl;
    
    return 0;
}