/*
    Cài đặt lớp stack với các yêu cầu sau:
    Dùng mảng 1 chiều hoặc DSLK để minh họa stack:
    - 1. Thêm phần tử vào stack
    - 2. Xóa phần tử khỏi stack
    - 3. Lấy phần tử đầu stack
    - 4. Kiểm tra stack rỗng
    - 5. Lấy kích thước stack
*/

// ------ Dùng mảng 1 chiều cùng cấp phát động --------

#include <iostream>
#include <string.h>         // for using memmove func
using namespace std;

class Stack {
    private:
        int *arr;
        int size;
        int max;

    public:
        // constructor
        Stack () {
            size = 0;
            max = 0;
        }

        // destructor
        ~Stack () {
            delete[] arr;
        }

        // methods
        void setMax(int m);
        void add (int x);
        void del();
        int getTop();
        bool isEmpty();
        int getSize();

};

// set max elements for stack
void Stack::setMax (int m) {
            if (size == 0 && max == 0) {
                max = m;
                arr = new int[max];
            } else if (m > max) {
                int *dupArr = new int[max];
                memmove(dupArr, arr, max);

                delete[] arr;
                arr = new int[m];
                memmove(arr, dupArr, max);
                max = m;

                delete[] dupArr;
            } else {
                int *dupArr = new int[m];
                memmove(dupArr, arr, m);

                delete[] arr;
                arr = new int[m];
                memmove(arr, dupArr, m);

                max = m;
                size = m;
            }
} 

// 1. add an element to stack
void Stack::add (int x) {
            if (isEmpty()) {
                if (max == 0) {
                    arr = new int [1];
                    arr[0] = x;
                    max = 1;
                } else {
                    arr[0] = x;
                }
            } else {
                if (size == max) {
                    // reallocate 
                    int *dupArr = new int[max];
                    memmove(dupArr, arr, max);

                    delete[] arr;
                    arr = new int[max + 1];
                    memmove(arr, dupArr, max);
                    arr[max] = x;

                    delete[] dupArr;
                    max = max + 1;

                } else {
                    arr[size] = x;
                }
            }
            size++;
}

// 2. delete an element out of stack
void Stack::del() {
            if (size == 0) {
                return;
            }
            size--;
            setMax(size);
}

// 3. get an element in the top of stack
int Stack::getTop() {
            // suppose that stack is not empty
            return arr[size - 1];
}

// 4. check if whether stack is empty or not
bool Stack::isEmpty() {
            return size == 0 ? true : false;
}

// 5. get the size of stack
int Stack::getSize() {
            return size;
}


int main() {
    Stack s ;

    // check if whether stack is empty or not
    if ( ! s.isEmpty()) {
        cout << "Stack is not empty !" << endl;
        cout << "size of stack : " << s.getSize() << endl;
        cout << "top of stack: " << s.getTop() << endl;
    } else {
        cout << "stack is empty ! " << endl;
    }

    // set max for number of elements of stack: 20
    s.setMax(20);
    
    // add the elements to stack
    s.add(22);
    s.add(5);
    s.add(2003);
    s.add(11);
    s.add(4);
    s.add(2011);
    s.add(13);
    s.add(4);
    s.add(1999);

    // check if whether stack is empty or not
    cout << "-------- after adding the elements ------" << endl;
    if ( ! s.isEmpty()) {
        cout << "Stack is not empty !" << endl;
        cout << "size of stack : " << s.getSize() << endl;
        cout << "top of stack: " << s.getTop() << endl;
    } else {
        cout << "stack is empty ! " << endl;
    }

    // delete some elements of stack
    s.del();

    cout << "top of stack: " << s.getTop() << endl;

    s.del();
    cout << "top of stack: " << s.getTop() << endl;

    // check if whether stack is empty or not
    cout << "-------- after deleting the elements ------" << endl;
    if ( ! s.isEmpty()) {
        cout << "Stack is not empty !" << endl;
        cout << "size of stack : " << s.getSize() << endl;
        cout << "top of stack: " << s.getTop() << endl;
    } else {
        cout << "stack is empty ! " << endl;
    }

    // set max : 5
    s.setMax(5);

    cout << "-------- after set max : 5 ----------" << endl;
    // check if whether stack is empty or not
    if ( ! s.isEmpty()) {
        cout << "Stack is not empty !" << endl;
        cout << "size of stack : " << s.getSize() << endl;
        cout << "top of stack: " << s.getTop() << endl;
    } else {
        cout << "stack is empty ! " << endl;
    }


    return 225;
}
