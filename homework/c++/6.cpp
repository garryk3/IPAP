#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ERROR_CODE = -1;

int* buildArrRand(const int length, const int minElem = -5, const int maxElem = 100) {
    int arr[length];

    for(int i = 0; i < length; i++) {
        arr[i] = rand() % (maxElem - minElem + 1) + minElem;
    }
    return arr;
}

int requestArrLength(string rule) {
    int len;
    cout << "Введите длину массива для " << rule << endl;
    cin >> len;
    while(!len) {
        len = requestArrLength(rule);
    }
    return len;
}

void calculateSum() {
    int len = requestArrLength("вычисления суммы чисел");
    const int* arr = buildArrRand(len);
    string str;
    int result = 0;

    for(int i = 0; i < len; i++) {
        result += arr[i];
        str += arr[i] + ", ";
    }
    cout << "Сумма чисел массива: " << str << "равна: " << to_string(result) << endl;
}

int main() {
    srand(time(NULL));
    calculateSum();
    return 0;
}