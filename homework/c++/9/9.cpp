#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//#include "../helpers/helpers.h"

// using namespace Helpers;

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
    for(int i = 0; i < len - 1; i++) { // сравнение последнего элемента 
        for(int j = 0; j < len - (i + 1); j++) {
            if(arr[j + 1] < arr[j]) {
                swapNumbers(arr[j + 1], arr[j]);
            }
        }
    }
    return arr;
}

int* buildArrRand(const int length, const int minElem = 0, const int maxElem = 100) {
    int* arr = new int[length];

    for(int i = 0; i < length; i++) {
        arr[i] = rand() % (maxElem - minElem + 1) + minElem;
    }
    return arr;
}

string arrToString(const int* arr, int length) {
    string str = "";
    for(int i = 0; i < length; i++) {
        str += to_string(arr[i]) + (i != length - 1 ? ", " : "");
    }
    return str;
}

int main() {
    srand(time(NULL));
    const int LEN = 90;
    int *arr = buildArrRand(LEN);
    cout << "array 1 before: " << arrToString(arr, LEN) << endl;
    sortArrayBubble(arr, LEN);
    cout << "array 1 after: " << arrToString(arr, LEN) << endl;
    return 0;
}