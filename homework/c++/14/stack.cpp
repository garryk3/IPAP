#include <iostream>
#include <ctime>
#include <string.h>
#include <cmath>

using namespace std;

// ----------------------------------------------------------------
// реалзовать стек LIFO int чисел
// ----------------------------------------------------------------

int MAX_STACK_SIZE = 10;

struct Stack {
    int size = 0;
    int* data = nullptr;
};

int push(Stack* phead, const int value) {
    if(phead->size < MAX_STACK_SIZE) {
        int* newData = new int[phead->size + 1];
        newData[0] = value;
        for(int i = 1; i < phead->size + 1; ++i) {
            newData[i] = phead->data[i - 1];
        }
        delete[] phead->data;
        phead->data = newData;
        phead->size++;
    } else {
        cout << "Stack overflow, operation failed" << endl;
    }
}

int pop(Stack* phead) {
    if(phead->size != 0) {
        int* newData = new int[phead->size - 1];
        for(int i = 0; i < phead->size - 1; ++i) {
            newData[i] = phead->data[i + 1];
        }
        delete[] phead->data;
        phead->data = newData;
        phead->size--;
    } else {
        cout << "Stack empty, operation failed" << endl;
    }
}

void print(Stack* phead) {
    cout << "Stack: ";
    for(int i = 0; i < phead->size; i++) {
        cout << phead->data[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack* st = new Stack;
    print(st);
    for(int i = 0; i < 4; i++) {
        push(st, i);
    }
    print(st);
    pop(st);
    pop(st);
    print(st);
    return 0;
}