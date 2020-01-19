#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sstream>

using namespace std;

const int ERROR_CODE = -1;

int* buildArrRand(const int length, const int minElem = -5, const int maxElem = 100) {
    int* arr = new int[length];

    for(int i = 0; i < length; i++) {
        arr[i] = rand() % (maxElem - minElem + 1) + minElem;
    }
    return arr;
}

int requestArrLengthFor(string rule) {
    int len;
    cout << "Введите длину массива для " << rule << endl;
    cin >> len;
    return len;
}

string arrToString(const int* arr, int length) {
    string str = "";
    for(int i = 0; i < length; i++) {
        str += to_string(arr[i]) + (i != length - 1 ? ", " : "");
    }
    return str;
}

void calculateSum() {
    // сумма всех чисел в массиве
    int len = requestArrLengthFor("вычисления суммы чисел");
    const int* arr = buildArrRand(len);
    int result = 0;

    for(int i = 0; i < len; i++) {
        result += arr[i];
    }
    cout << "Сумма чисел массива: " << arrToString(arr, len) << "равна: " << to_string(result) << endl;
    delete[] arr;
}

void calculatePositiveCount() {
    // количество положительныых чисел
    int len = requestArrLengthFor("нахождения количества положительных чисел");
    const int* arr = buildArrRand(len);
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] > 0) {
            count += 1;
        }
    }
    cout << "Количество положительных чисел в массиве " << arrToString(arr, len) << "равно " << to_string(count) << endl;
    delete[] arr;
}

void calculateMiddleNegative() {
    // среднее по всем отрицательным числам
    int len = requestArrLengthFor("среднего по всем отрицательным числам");
    const int* arr = buildArrRand(len, -50, 60);
    int sum = 0;
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] < 0) {
            sum += arr[i];
            count += 1;
        }
    }

    if(sum != 0) {
        cout << "Среднее отрицательных чисело массива " << arrToString(arr, len) << "равно " << to_string(sum / count) << endl;
    } else {
        cout << "Все числа массива " << arrToString(arr, len) << "положительные, среднее не найдено" << endl;
    }
    delete[] arr;
}

void calculateMaxPosition() {
    // позиция максимального числа
    int len = requestArrLengthFor("вычисления позиции максимального числа");
    const int* arr = buildArrRand(len, -50, 60);
    int pos = 0;
    for(int i = 1; i < len; i++) {
        if(arr[i] > arr[i - 1] && arr[i] > arr[pos]) pos = i;
    }
    cout << "Позиция максимального числа массива " << arrToString(arr, len) << "равна " << to_string(pos) << endl;
    delete[] arr;
}

void calculateMinPositivePosition() {
    // позиция минимального положительного числа
    int len = requestArrLengthFor("вычисления позиции минимального положительного числа");
    const int* arr = buildArrRand(len, -50, 60);
    int pos = ERROR_CODE;
    for(int i = 0; i < len; i++) {
        if (arr[i] > 0 && (pos == ERROR_CODE || arr[i] < arr[pos])) {
            pos = i;
        }
    }
    if(pos != ERROR_CODE) {
        cout << "Позиция минимального положительного числа массива " << arrToString(arr, len) << " равна " << to_string(pos) << endl;
    } else {
        cout << "В массиве " << arrToString(arr, len) << " нет положительных чисел" << endl;
    }
    delete[] arr;
}

void printReverseArray() {
    // разворот массива
    int len = requestArrLengthFor("разворота массива");
    const int* arr = buildArrRand(len, -50, 60);
    int pos = ERROR_CODE;
    cout << "Элементы массива " << arrToString(arr, len) << " в обратном порядке: ";
    for(int i = len - 1; i >= 0; i--) {
        cout << to_string(arr[i]) << (i != 0 ? ", " : "");
    }
    cout << endl;
    
    delete[] arr;
}

void printSquareArrElements() {
    // вывод корней квадратныя элементов массива
    int len = requestArrLengthFor("разворота массива");
    const int* arr = buildArrRand(len, -5, 10);
    cout << "Квадратные корни элементов массива " << arrToString(arr, len) << " : ";
    for(int i = 0; i < len; i++) {
        double square;
        stringstream(to_string(sqrt(arr[i]))) >> square;
        cout << square << (i != len - 1 ? ", " : "");
    }
    cout << endl;
    
    delete[] arr;
}

void calculateSquareSumArrElements() {
    // сумма квадратов элемента массива
    int len = requestArrLengthFor("разворота массива");
    const int* arr = buildArrRand(len, -5, 0);
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += arr[i] * arr[i];
    }
    cout << "Сумма квадратов элементов массива " << arrToString(arr, len) << ": " << to_string(sum) << endl;
}

void calculateSumAndPosArrElemClosestToNum() {
    // найти значение и позицию числа, ближайшего к числу, введенному с консоли
    int len = requestArrLengthFor("разворота массива");
    const int* arr = buildArrRand(len, -5, 100);
    int num;
    cout << "Введите число для сравнения" << endl;
    cin >> num;
    int pos = 0;
    for(int i = 1; i < len; i++) {
        if(abs(num - arr[i]) < abs(num - arr[pos])) {
            pos = i;
        }
    }
    cout << "Ближайшее число к " << to_string(num) << " из массива " << arrToString(arr, len) << " это " << to_string(arr[pos]) << ", его позиция - " << to_string(pos) << endl;
}

int main() {
    srand(time(NULL));
    // calculateSum();
    //calculatePositiveCount();
    // calculateMiddleNegative();
    // calculateMaxPosition();
    calculateMinPositivePosition();
    // printReverseArray();
    // printSquareArrElements();
    // calculateSquareSumArrElements();
    // calculateSumAndPosArrElemClosestToNum();
    return 0;
}

