#include "MyVector.h"

template <class T>
MyVector<T>::MyVector() {
    ptr = NULL;
    capacity = 0;
    sz = 0;
}

template <class T>
MyVector<T>::MyVector(int cap) {
    capacity = cap;
    sz = 0;
    ptr = new T[capacity];
}

template <class T>
MyVector<T>::~MyVector() {
    delete[] ptr;
}

template <class T>
T& MyVector<T>::operator[] (int index) {
    return ptr[index];
}

template <class T>
void MyVector<T>::reserve(int newAlloc) {
    if (newAlloc <= capacity) return;
    T *temp = new T[newAlloc];
    for (int i = 0; i < sz; i++) {
        temp[i] = ptr[i];
    }
    if (ptr != NULL) delete[] ptr;
    ptr = temp;
    capacity = newAlloc;
}

template <class T>
void MyVector<T>::push(const T& element) {
    if (sz == capacity) {
        if (capacity == 0) {
            reserve(10);
        } else {
            reserve(2 * capacity);
        }
    }
    ptr[sz] = element;
    sz++;

}

template <class T>
void MyVector<T>::print() {
    for (int i = 0; i < sz; i++) {
        cout << ptr[i] << " ";
    }
}


template class MyVector<int>;
