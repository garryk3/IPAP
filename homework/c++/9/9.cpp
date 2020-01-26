#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//#include "../helpers/helpers.h"

// using namespace Helpers;

string arrToString(const int* arr, int length) {
    string str = "";
    for(int i = 0; i < length; i++) {
        str += to_string(arr[i]) + (i != length - 1 ? ", " : "");
    }
    return str;
}

void swapNumbers(int& first, int& second) {
    int temp = second;
    second = first;
    first = temp;
}

int* sortArray(int arr[], const int len) {
    for(int i = 0; i < len; i++) {
        int minElPos = i;

        for(int j = minElPos; j < len; j++) {
            if(arr[j] < arr[minElPos]) {
                minElPos = j;
            }
        }
        if(minElPos != i) {
            swapNumbers(arr[i], arr[minElPos]);
        }
    }
    return arr;
}

int* sortArrayBubble(int arr[], const int len) {
    bool flag = true;
    for(int i = 0; i < len - 1 && flag; i++) { // сравнение последнего элемента 
        flag = false;
        for(int j = 0; j < len - (i + 1); j++) {
            if(arr[j + 1] < arr[j]) {
                swapNumbers(arr[j + 1], arr[j]);
                flag = true;
            }
        }
    }
    return arr;
}

int* sortMerge(int arr[], const int len) {
    while(len > 2) {
        int* result = new int(len);

        const int firstArrLen = len / 2;
        const int secondArrLen = len - len / 2;

        int* arr1 = new int[firstArrLen];
        int* arr2 = new int[secondArrLen];

        for(int i = 0; i < firstArrLen; i++) {
            arr1[i] = arr[i];
        }
        for(int i = 0; i < secondArrLen; i++) {
            arr2[i] = arr[i + firstArrLen];
        }
        arr1 = sortMerge(arr1, firstArrLen);
        arr2 = sortMerge(arr2, secondArrLen);
        int buffer = NULL;
        int resultIndex = 0;
        for(int i = 0; i < secondArrLen; i++) {
            if(buffer == NULL) {
                arr[resultIndex] = arr1[i] < arr2[i] ? arr1[i] : arr2[i];
                buffer = arr1[i] < arr2[i] ? arr2[i] : arr1[i];
                resultIndex++;
            } else if(arr1[i] == NULL) { // длина второго массива всегда будет больше из-за округления целочисленногг деления
                arr[resultIndex] = buffer < arr2[i] ? buffer : arr2[i];
            } else {
                bool isMinFirstEl = arr1[i] < arr2[i] && arr1[i] < buffer;
                bool isMinSecondEl = arr1[i] > arr2[i] && arr2[i] < buffer;
                bool isMinBuffer = buffer < arr2[i] && buffer < arr1[i];

                if(isMinFirstEl) {
                    arr[resultIndex] = arr1[i];
                    arr[resultIndex + 1] = buffer < arr2[i] ? buffer : arr2[i];
                    buffer = buffer > arr2[i] ? buffer : arr2[i];
                } else if(isMinSecondEl) {
                    arr[resultIndex] = arr2[i];
                    arr[resultIndex + 1] = buffer < arr1[i] ? buffer : arr1[i];
                    buffer = buffer > arr1[i] ? buffer : arr1[i];
                } else {
                    arr[resultIndex] = buffer;
                    arr[resultIndex + 1] = arr1[i] < arr2[i] ? arr1[i] : arr2[i];
                    buffer = arr1[i] > arr2[i] ? arr1[i] : arr2[i];
                }
                resultIndex++;
            }
            i++;
        }

        delete[] arr1;
        delete[] arr2;
        return result;
    }
    if(len == 2) {
        if(arr[0] > arr[1]) {
            swapNumbers(arr[0], arr[1]);
        }
        return arr;
    } else {
        return arr;
    }
}

void concatArrs(int* result, int* arr1, int* arr2, int firstLen, int secondLen) {
    int firstPointer = 0;
    int secondPointer = 0;

    for(int i = 0; i < firstLen + secondLen; i++) {
        if(arr1[firstPointer] < arr2[secondPointer]) {
            result[i] = arr1[firstPointer];
            firstPointer++;
            if(firstPointer > firstLen - 1) {
                result[i + 1] = arr2[secondPointer];
                result[i + 2] = arr2[secondPointer + 1];
                return;
            }
        } else {
            result[i] = arr2[secondPointer];
            secondPointer++;
            if(secondPointer > secondLen - 1) {
                result[i + 1] = arr1[firstPointer];
                result[i + 2] = arr1[firstPointer + 1];
                return;
            }
        }
    }
}

// сортировка слиянием
int sortArrByMerge(int* arr, int len) {
    if(len > 1) {
        const int firstArrLen = len / 2;
        const int secondArrLen = len - len / 2;

        int* arr1 = new int[firstArrLen];
        int* arr2 = new int[secondArrLen];

        for(int i = 0; i < firstArrLen; i++) {
            arr1[i] = arr[i];
        }
        for(int i = 0; i < secondArrLen; i++) {
            arr2[i] = arr[i + firstArrLen];
        }
        sortArrByMerge(arr1, firstArrLen);
        sortArrByMerge(arr2, secondArrLen);

        concatArrs(arr, arr1, arr2, firstArrLen, secondArrLen);
    }
}

// сортировка хоара
int sortArrByHoarBubble(int* arr, int len) {}

int* buildArrRand(const int length, const int minElem = 0, const int maxElem = 100) {
    int* arr = new int[length];

    for(int i = 0; i < length; i++) {
        arr[i] = rand() % (maxElem - minElem + 1) + minElem;
    }
    return arr;
}

int main() {
    srand(time(NULL));
    const int LEN = 9;
    int *arr = buildArrRand(LEN);
    cout << "array 1 before: " << arrToString(arr, LEN) << endl;
    // sortArrayBubble(arr, LEN);
    sortArrByMerge(arr, LEN);
    cout << "array 1 after: " << arrToString(arr, LEN) << endl;
    return 0;
}