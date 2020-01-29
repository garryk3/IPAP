#include <iostream>
#include <ctime>

using namespace std;

const int N = 5;
const int M = 6;

void printMatr(int** matr, int row, int col) {}

void test0() {
    int matr[N][M];
    int counter = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            matr[i][j] = ++counter;
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

// матрица формата
// 1  8  9
// 2  7  10
// 3  6  11
// 4  5  12
void test1() {
    int matr[N][M];
    int counterRow = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 1; j < M; j++) {
            if(j == 0) {
                counterRow = i + 1;
            } else {
                if(j % 2 == 0) {
                    counterRow += i * 2 + 1;
                } else {
                    counterRow = N * (j + 1) - i;
                }
            }
            matr[i][j] = counterRow;
        }
    }
    for(int i = 0; i < N; i++) {
        cout << "row " << i << " : ";
        for(int j = 0; j < M; j++) {
            cout <<  matr[i][j] << "    ";
        }
        cout << endl;
    }
}

int** generateRandomSquareMatrix(int len) {
    int** result = new int*[len]; // массив указателей на int длины len
}

int main() {
    test1();
    return 0;
}