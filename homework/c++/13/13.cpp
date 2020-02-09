#include <iostream>
#include <ctime>
#include <string.h>
#include <cmath>

using namespace std;

struct Element {
    int value;
    Element* pnext;
};

// @TODO need refactor
Element* pushElement(Element* phead) {
    if(phead != NULL) {
        Element* p = phead;
        while(p->pnext != NULL) {
            p = p->pnext;
        }
        p->pnext = new Element;
        p->pnext->pnext = NULL;
        cout << "\nEnter number ";
        cin >> p->pnext->value;
    } else {
        phead = new Element;
        cout << "\nEnter number ";
        cin >> phead->value;
        phead->pnext = NULL;
    }
    return phead;
};

Element* printElements(Element* phead) {
    while (phead != NULL) {
        cout << "Element value: " << phead->value << endl;
        phead = phead->pnext;
    }
}

Element* findMinElement(Element* phead) {
    int minElem = phead->value;
    while (phead != NULL) {
        if(phead->value < minElem) minElem = phead->value;
        phead = phead->pnext;
    }
    cout << "Min element value: " << minElem << endl;
}

Element* deleteElementsList(Element* phead) {
    Element* next = phead->pnext;
    delete phead;
    if(next != NULL) {
        deleteElementsList(next);
    }
}

void printElementsReverse(Element* phead) {
    int* values = new int[x];
    while (phead != NULL) {
        phead = phead->pnext;
    }
}

void test() {
    int LEN = 4;
    Element* phead = NULL;
    for(int i = 0; i < LEN; i++) {
        phead = pushElement(phead);
    }
    printElements(phead);
    cout << "after: " << endl;
    deleteElementsList(phead);
    printElements(phead);
}

int main() {
    test();
    return 0;
}