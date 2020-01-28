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

void mergeArrs(int arr1[], int arr2[], int arr1Len, int arr2Len, int result[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < arr1Len && j < arr2Len) {
        if(arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    if(i == arr1Len) {
        while (j < arr2Len) {
            result[k++] = arr2[j++];
        }
    } else {
        while(i < arr1Len) {
            result[k++] = arr1[i++];
        }
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

        // if(len == 2) {
        //     if(arr[0] > arr[1]) {
        //         swapNumbers(arr[0], arr[1]);
        //     }
        // }

        mergeArrs(arr, rightArr, leftArrLen, rightArrLen, result);

        *arr = *result;
    }
}

int* buildArrRand(const int length, const int minElem = 0, const int maxElem = 100) {
    int* arr = new int[length];

    for(int i = 0; i < length; i++) {
        arr[i] = rand() % (maxElem - minElem + 1) + minElem;
    }
    return arr;
}

int main() {
    srand(time(NULL));
    const int LEN = 5;
    int *arr = buildArrRand(LEN);
    cout << "array 1 before: " << arrToString(arr, LEN) << endl;
    // sortArrayBubble(arr, LEN);
    sortArrByMerge(arr, LEN);
    cout << "array 1 after: " << arrToString(arr, LEN) << endl;
    return 0;
}