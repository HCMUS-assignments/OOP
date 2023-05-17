#ifndef Vector_H
#define Vector_H

#include <iostream>
using namespace std;


template <class T>
class Vector {
    private :
        T* ptr;
        int capacity;
        int sz;

    public:
        // constructors
        Vector();
        Vector(int cap);
        ~Vector();

        // utilities methods
        // operator [] 
        T& operator[] (int index);

        // expand extra memory
        void reserve(int newAlloc);

        // input and output
        void push(const T& element);
        void print();

        // getter
        int size() { return sz; }

        void insert(int pos, const T& element);
        void resize(int sz);

};

#endif