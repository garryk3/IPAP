#include <iostream>
#include <ctime>

using namespace std;

const int N = 8;
const int M = 4;

void printMatr(int** matr, int row, int col) {}

void test0() {
    int matr[N][M];
    int counter = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            counter++;
            matr[i][j] = counter;
        }
    }
    for(int i = 0; i < N; i++) {
        cout << "elem: ";
        for(int j = 0; j < M; j++) {
            cout <<  matr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    test0();
    return 0;
}