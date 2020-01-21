#include "8.h"

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

    cout << "Введите точку А ";
    cin >> params[0];
    cout << "Введите точку Б ";
    cin >> params[1];
    cout << "Введите степерь точности подсчета площади ";
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

void calculateSquare() {
    const double* userParams = requestParams();
    const double startPointer = userParams[0];
    const double finishPointer = userParams[1];
    const double stepWidth = userParams[2] ;
    double height = 0;
    double square = 0;

    for(double x = startPointer; x < finishPointer; x += stepWidth) {
        height = x * x + sin(x);
        square += stepWidth * height;
    }
    cout << "Площадь фигуры шириной " << finishPointer - startPointer << " и высотой " << height << " равна " << square << endl;
}