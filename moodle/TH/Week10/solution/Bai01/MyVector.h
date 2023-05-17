#ifndef MyVector_H
#define MyVector_H

#include <iostream>
using namespace std;


template <class T>
class MyVector {
    private :
        T* ptr;
        int capacity;
        int sz;

    public:
        // constructors
        MyVector();
        MyVector(int cap);
        ~MyVector();

        // utilities methods
        // operator [] 
        T& operator[] (int index);

        // expand extra memory
        void reserve(int newAlloc);

        // input and output
        void push(const T& element);
        void print();
};

#endif