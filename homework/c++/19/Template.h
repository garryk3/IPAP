#pragma once

template <class T>
class MyArray {
    public:
        int size = 0;
        T arr[];

        MyArray();
        ~MyArray();
        int setLength(int size);
        void pushBack(T element);
};