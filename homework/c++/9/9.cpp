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

// int compareStep(int result[], int *currentPointer, int workedArr[], int wArrLen, int step) {
//     result[step] = *workedArr[currentPointer];
//     currentPointer++;

//     if(currentPointer > wArrLen - 1) {
//         result[step + 1] = workedArr[currentPointer];
//         result[step + 2] = workedArr[currentPointer + 1];
//         return 0;
//     }
//     return 1;
// }

// void concatArrs(int* result, int* arr1, int* arr2, int firstLen, int secondLen) {
//     int firstPointer = 0;
//     int secondPointer = 0;
//     int isContinueCode = 1;

//     for(int i = 0; i < firstLen + secondLen; i++) {
//         if(arr1[firstPointer] < arr2[secondPointer]) {
//             int isContinue = compareStep(result, &firstPointer, arr1, firstLen, i);
//         } else {
//             int isContinue = compareStep(result, &secondPointer, arr2, secondLen, i);
//         }
//         if(isContinueCode == 0) {
//             return;
//         }
        
//     }
// }

void mergeArrs(int arr1[], int arr2[], int arr1Len, int arr2Len, int result[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < arr1Len && j < arr2Len) {
        /* code */
    }
    
}

// сортировка слиянием
void sortArrByMerge(int arr[], int len) {
    if(len > 1) {
        const int leftArrLen = len / 2;
        const int rightArrLen = len - len / 2;
        int* rightArr = &arr[leftArrLen];
        int result[len];

        sortArrByMerge(arr, leftArrLen);
        sortArrByMerge(rightArr, rightArrLen);

        mergeArrs(arr, rightArr, leftArrLen, rightArrLen, result);

        *arr = *result;
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