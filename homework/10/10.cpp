#include <iostream>
#include <ctime>
#include <string.h> 

using namespace std;

//----------------------------------------------------------------
// работа с матрицами
// ---------------------------------------------------------------

const int N = 5;
const int M = 6;

void swapNumbers(int& first, int& second) {
    int temp = second;
    second = first;
    first = temp;
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

int** generateRandomSquareMatrix(int len, int step = 500) {
    if(len > 0) {
        srand(time(0));
        int** result = new int*[len]; // массив указателей на int длины len
        for(int i = 0; i < len; i++) {
            result[i] = new int[len];
            for(int j = 0; j < len; j++) {
                result[i][j] = rand() % step;
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

void printMatrix(int** mat, int len, int printLength = 4) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            cout.width(printLength);
            cout << mat[i][j];
        }
        cout << endl;
    }
    cout << endl << "____________________" << endl;
}

int** transposeMatrix(int** matrix, int row, int col) {
    int** result = NULL;
    result = new int*[col];
    for(int i = 0; i < col; i++) {
        result[i] = new int[row];
        for(int j = 0; j < row; j++) {
            result[i][j] = matrix[j][i];
        }
    } 
    return result;
}

int calculateMatrixElementWidth(int** matrix, int col, int row) {
    int result = 0;
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            int elemSize = to_string(matrix[i][j]).length();
            if(elemSize > result) {
                result = elemSize;
            }
        }

    }
    return result;
}

int calculateMatrixPallindrome(int** matrix, int col, int row) {
    int pallindromeCount = 0;
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            string stringElement = to_string(matrix[i][j]);
            int finishIndex = stringElement.length() - 1;
            int startIndex = 0;
            int isNeedContinue = true;
            int detectedCompare = 0;
            while(finishIndex != startIndex && isNeedContinue) {
                if(stringElement[finishIndex--] == stringElement[startIndex++]) {
                    detectedCompare++;
                } else {
                    isNeedContinue = false;
                }
            }
            if(detectedCompare != 0 && detectedCompare == stringElement.length() / 2) {
                pallindromeCount++;
                cout << "Detected: " << stringElement << endl;
            }
        }
    }
    return pallindromeCount;
}

int sortMatrixByHier(int** matrix, int col, int row) {

}

// 1(простая) сортировка матрицы 
// распаковать матрицу в линейный массив
// отсортировать массив
// запаковать массив обратно

int** getSortedMatrixBubble(int** matrix, int col, int row) {
    bool flag = true;
    const int commonLength = col * row - 1;

    for(int i = 0; i < commonLength && flag; i++) {
        flag = false;
        for(int j = 0; j < commonLength - i; j++) {
            const int colIndexNext = (j + 1) / row;
            const int colIndex = j / row;
            const int rowIndex = j % row;
            const int rowIndexNext = (j + 1) % row;
     
            if(matrix[colIndexNext][rowIndexNext] < matrix[colIndex][rowIndex]) {
                swapNumbers(matrix[colIndexNext][rowIndexNext], matrix[colIndex][rowIndex]);
            }
            flag = true;
        }
    }
    return matrix;
}

int main() {
    // test1();
    int len = 20;
    int** matrix = generateRandomSquareMatrix(len, 500);
    printMatrix(matrix, len);
    int** sortedMatrix = getSortedMatrixBubble(matrix, len, len); 
    printMatrix(sortedMatrix, len);
    deleteMatrix(&matrix, len);
    return 0;
}