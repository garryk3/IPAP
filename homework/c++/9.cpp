#include <helpers.cpp>

int* sortArray(int arr[], const int len) {
    for(int i = 0; i < len; i++) {
        int minElPos = i;

        for(int j = minElPos; j < len; j++) {
            if(arr[j] < arr[minElPos]) {
                minElPos = j;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    const int LEN = 9;
    int *arr = buildArrRand(LEN);
    sortArray(arr, LEN);

    return 0;
}