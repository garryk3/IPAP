#include "Template.h"

MyArray<class T>::MyArray() {
    arr = nullptr;
};

MyArray<class T>::~MyArray() {
    if(arr != nullptr) {
        delete[] arr;
    }
};

template <class T> int MyArray<T>::setLength(int newSize) {
    if(newSize < 0) {
        newSize = 0;
    }
    T *temp = nullptr;
    if(newSize > 0 && arr != nullptr) {
        temp = arr;
    }
    this->arr = new T[newSize];
    for(int i = 0; i < newSize; ++i) {
        arr[i] = temp[i];
    }
    if(temp != nullptr) {
        delete[] temp;
    }
    this->size = newSize;
};

template <class T> void MyArray<T>::pushBack(T element) {
    this->setLength(this->size + 1);
    this->arr[this->size - 1] = element;
};

template <class T> T& MyArray<T>::at(int index) {
    return arr[index];
}