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

Element* createElement(Element* phead) {
    phead = new Element;
    phead->pnext = NULL;
    cout << "\nEnter number ";
    cin >> phead->value;
    return phead;
}

Element* popElement(Element* phead) {
    Element* newElement = createElement(phead);
    newElement->pnext = phead;
    return newElement;
}

int deleteElementByValue(Element** phead, int value) {
    int deleted = 0;
    Element* p = *phead;
    while (p != NULL) {
        if(p->value == value) {
            deleted++;
        }
        p = p->pnext;
    }
    return deleted;
}

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
    if(phead != NULL) {
        printElementsReverse(phead->pnext);
        cout << "Element value " << phead->value << endl;
    }
}

void enterUntil2Zero() {
    cout << "Entering 2 zero to finish\n";
    Element* p = NULL;
    int zeroCount = 0;
    while(zeroCount < 2) {
        p = popElement(p);
        if(p->value == 0) {
            zeroCount++;
        } else {
            zeroCount = 0;
        }
    }
    printElements(p);
}

void test() {
    int LEN = 3;
    Element* phead = NULL;
    for(int i = 0; i < LEN; i++) {
        phead = pushElement(phead);
    }
    printElements(phead);
    // printElementsReverse(phead);
    phead = popElement(phead);
    cout << "after: " << endl;
    printElementsReverse(phead);
}

int main() {
    enterUntil2Zero();
    return 0;
}