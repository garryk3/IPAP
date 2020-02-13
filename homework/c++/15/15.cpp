#include <iostream>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

// -------------------------------
// string
// -------------------------------

void test(const string &str  /*  string* str */) {
    cout << "str: " << str << endl;
};

void test2(const int val) {
    cout << "val: " << val << endl;
}

void swapByLink(string &s1, string &s2) {
    const string temp = s1;
    s1 = s2;
    s2 = temp;
}

void newZeroArray(int* &arr, int k) {
    delete[] arr;
    arr = new int[k];
    for (int i = 0; i < k; ++i) arr[i] = 0;
}

string arrToString(const int* arr, int length) {
    string str = "array: ";
    for(int i = 0; i < length; i++) {
        str += to_string(arr[i]) + (i != length - 1 ? ", " : "");
    }
    cout << endl;
    return str;
}

void arrPush(int* &arr, int len) {
    int* newArr = new int[len + 1];
    for(int i = 0; i < len; ++i) {
        newArr[i] = arr[i];
    }
    newArr[len ] = 999999999;
    arr = newArr;
}

int main() {
    string name;
    // char chararray[256];
    // cout << "Enter your name ";
    // cin.getline(chararray, 256);
    // name = chararray;
    // cout << endl << "Name " << name << " has length " << name.length();
    // string* pstr;
    // pstr = &name;
    // *pstr = "p_" + * pstr;
    // string &ls = name;
    // test(name + "valur");
    // int testVal = 9;
    // test2(testVal + 1);
    int LEN = 10;
    int* arr = new int[LEN];
    for(int i = 0; i < LEN; ++i) {
        arr[i] = i;
    }
    cout << arrToString(arr, LEN) << endl;
    arrPush(arr, LEN);
    cout << arrToString(arr, LEN + 1) << endl;
    return 0;
}