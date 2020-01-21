#include "8.h";

int main() {
    printFib();
    return 0;
}

unsigned int findFibNum(unsigned int pos) {
    if(pos == 0 || pos == 1) {
        return pos;
    }
    return findFibNum(pos - 1) + findFibNum(pos - 2);
}

void printFib() {
    unsigned int pos;
    cout << "Введите позицию числа фибоначчи ";
    cin >> pos; 
    const int num = findFibNum(pos);
    cout << "Число фибоначии равно " << num << endl;
}

double calculateSquare(int accuracy) {
    int y = x * x + sin(x);
}