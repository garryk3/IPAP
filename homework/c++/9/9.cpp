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
        swapNumbers(arr[i], arr[minElPos]);
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
    const int LEN = 9;
    int *arr = buildArrRand(LEN);
    int arr2[5] = {4, 3, 2, 1, 0};
    cout << "array 1 before: " << arrToString(arr, LEN) << endl;
    cout << "array 2 before: " << arrToString(arr2, 5) << endl;

    sortArray(arr, LEN);
    sortArray(arr2, 5);

    cout << "array 1 after: " << arrToString(arr, LEN) << endl;
    cout << "array 2 after: " << arrToString(arr2, LEN) << endl;
    return 0;
}