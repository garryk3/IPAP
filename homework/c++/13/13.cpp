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
        cout << "\nEnter number";
        cin >> p->pnext->value;
    } else {
        phead = new Element;
        phead->pnext->pnext = NULL;
        cout << "\nEnter number";
        cin >> phead->pnext->value;
    }
    return phead;
};

void test() {
    int LEN = 4;
}

int main() {
    Element* phead = NULL;
    return 0;
}