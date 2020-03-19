#include <iostream>

#include "helpers.h"

namespace Helpers {
    int* buildArrRand(const int length, const int minElem = -5, const int maxElem = 100) {
        int* arr = new int[length];

        for(int i = 0; i < length; i++) {
            arr[i] = rand() % (maxElem - minElem + 1) + minElem;
        }
        return arr;
    }

    void swapNumbers::swapNumbers(int& first, int& second) {
        int temp = second;
        second = first;
        first = temp;
    }
}
