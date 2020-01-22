#include <common.h>

int* sortArray(int arr[], const int len) {
    for(int i = 0; i < len; i++) {
        int minElPos = i;

        for(int j = minElPos; j < len; j++) {
            if(arr[j] < arr[minElPos]) {
                minElPos = j;
            }
        }
        swap(arr[i], arr[minElPos]);
    }
}

int main() {
    srand(time(NULL));
    const int LEN = 9;
    int *arr = buildArrRand(LEN);
    int arr2[5] = {0, 1, 2, 3, 4};
    sortArray(arr, LEN);
    sortArray(arr2, 5);

    return 0;
}