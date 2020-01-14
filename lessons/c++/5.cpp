#include <iostream>

using namespace std;

// передача параметра копированием
int test(int y) {
    return y / 2;
}

// динамические массивы
int main() {
    int x;
    cout << "Введите длину массива ";
    cin >> x;

    int* arr = new int[x];

    for(int i = 0; i < x; i++) {
        arr[i] += i;
    }

    int* arrCopy = new int[x];
    *arrCopy = *arr;
    for(int i = 0; i < x; i++) {
        // arrCopy[i] = arr[i];
        cout << "item: " << arrCopy[i] << " prevIteM: " << arr[i] << endl;
    }
    cout << to_string(test(x));

    delete[] arr;
    delete[] arrCopy;
    return 0;
}