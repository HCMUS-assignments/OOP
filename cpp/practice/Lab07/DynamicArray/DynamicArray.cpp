#include "DynamicArray.hpp"

DynamicArray::DynamicArray() {
    _a = new int[DEFAULT_LEN];
    _len = 0;
    _max = DEFAULT_LEN;
}

DynamicArray::DynamicArray(int len) {
    if (len <= 0) {
        len = DEFAULT_LEN;
    }

    _a = new int[len];
    _len = 0;
    _max = len;
}

DynamicArray::~DynamicArray() {
    if (_a != nullptr) {
        delete[] _a;
        _a = nullptr;
    }
}


DynamicArray::DynamicArray(const DynamicArray& dynamicArray) {
    _len = dynamicArray._len;
    _max = dynamicArray._max;

    _a = new int[_max];
    for (int i = 0; i < _len; i++) {
        _a[i] = dynamicArray._a[i];
    }
}

void DynamicArray::PushBack(int value) {
    if (_len == _max) {
        int* temp = new int[_max + DEFAULT_LEN];
        for (int i = 0; i < _len; i++) {
            temp[i] = _a[i];
        }
        delete[] _a;
        _a = temp;
        _max += DEFAULT_LEN;
    }
    _a[_len] = value;
    _len++;
}

int DynamicArray::GetAt(int i) {
    try {
        if (i < 0 || i >= _len) {
            throw "Index out of range";
        }
        return _a[i];
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
}

string DynamicArray::toString() const {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < _len; i++) {
        ss << _a[i];
        if (i < _len - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}

istream& operator>>(istream& is, DynamicArray* dynamicArray) {
    cout << "Enter the length of the array: ";
    is >> dynamicArray->_len;
    cout << "Enter the max of the array: ";
    is >> dynamicArray->_max;

    dynamicArray->_a = new int[dynamicArray->_max];
    for (int i = 0; i < dynamicArray->_len; i++) {
        cout << "Enter the value at index " << i << ": ";
        is >> dynamicArray->_a[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const DynamicArray* dynamicArray) {
    os << dynamicArray->toString();
    return os;
}