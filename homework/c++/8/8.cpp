#include "8.h"
#include "../common.h"

int main() {
    // printFib();
    calculateSquare();
    return 0;
}

unsigned int findFibNum(unsigned int pos) {
    if(pos == 0 || pos == 1) {
        return pos;
    }
    return findFibNum(pos - 1) + findFibNum(pos - 2);
}

const double* requestParams() {
    static double params[3];

    cout << "Введите координату X начала отрезка ";
    cin >> params[0];
    cout << "Введите координату Y конца отрезка ";
    cin >> params[1];
    while(params[0] > params[1]) {
        cout << "Координата X должен быть больше Y. Введите Y еще раз... ";
        cin >> params[1];
    }
    cout << "Введите шаг точности подсчета площади ";
    cin >> params[2];

    return params;
}

void printFib() {

    unsigned int pos;
    cout << "Введите позицию числа фибоначчи ";
    cin >> pos; 
    const int num = findFibNum(pos);
    cout << "Число фибоначии равно " << num << endl;
}

double calculateHeight(double x) {
    return x * x + sin(x);
}

void calculateSquare() {
    const double* userParams = requestParams();
    const double startPointer = userParams[0];
    const double finishPointer = userParams[1];
    const double stepWidth = userParams[2] ;
    double height = 0;
    double square = 0;

    for(double x = startPointer; x < finishPointer; x += stepWidth) {
        height = calculateHeight(x);
        square += fabs(stepWidth * height);
    }
    cout << "Площадь фигуры шириной " << finishPointer - startPointer << " и высотой " << height << " равна " << square << endl;
}