#ifndef _DYNAMIC_ARRAY_HPP
#define _DYNAMIC_ARRAY_HPP

#include <iostream>
using namespace std;

class DynamicArray {
    private:
        const int DEFAULT_LEN = 128;
    private: 
        int *_a;
        int _len;
        int _max;
    public:
        // constructors
        DynamicArray();
        DynamicArray(int len);

        // destructor
        ~DynamicArray();

        // getters
        int GetLen() { return _len; }
        int GetMax() { return _max; }

        // copy constructor
        DynamicArray(const DynamicArray& dynamicArray);

        // methods
        void PushBack(int value);
        int GetAt(int i);

};

#endif