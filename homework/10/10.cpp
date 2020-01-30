#include <iostream>
#include <ctime>

using namespace std;

//----------------------------------------------------------------
// работа с матрицами
// ---------------------------------------------------------------

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
        for(int j = 0; j < M; j++) {
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
    if(len > 0) {
        srand(time(0));
        int** result = new int*[len]; // массив указателей на int длины len
        for(int i = 0; i < len; i++) {
            result[i] = new int[len];
            for(int j = 0; j < len; j++) {
                result[i][j] = rand() % 50;
            }
        }
        return result;
    }
    return NULL;
}

void deleteMatrix(int*** mat, int len) {
    for(int i = 0; i < len; i++) {
        delete[] (* mat)[i];
    }
    delete[] (* mat);
    *mat = NULL;
}

void printMatrix() {
    int len = 10;
    int** mat = generateRandomSquareMatrix(len);
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            cout.width(4);
            cout << mat[i][j];
        }
        cout << endl << endl;
    }
    deleteMatrix(&mat, len);
}

int main() {
    // test1();
    printMatrix();
    return 0;
}