/*
    Cài đặt queue với các yêu cầu sau:
    Dùng mảng 1 chiều hoặc DSLK để minh họa queue:
    - 1. Thêm phần tử vào queue
    - 2. Xóa phần tử khỏi queue
    - 3. Lấy phần tử đầu queue
    - 4. Kiểm tra queue rỗng
    - 5. Lấy kích thước queue
*/

// --------- Dùng DSLK ----------

#include <iostream>
using namespace std;

// struct node 
struct Node {
    int key;
    Node *pNext;
};

class Queue {
    private:
        Node *pHead;
        Node *pTail;
        int size;

    public:
        // constructor
        Queue () {
            pHead = NULL;
            pTail = NULL;
            size = 0;
        }

        // destructor
        ~ Queue () {
            delete pHead;
            delete pTail;
        }

        // methods
        // 1. add an element to queue
        void add (int x);

        // 2. delete an element out of queue
        void del ();

        // 3. get the element which is in head of queue
        int getHead();

        // 4. check whether queue is empty or not
        bool isEmpty();

        // 5. get size of queue
        int getSize();

};

// definition methods

// 1. add an element to queue
void Queue::add(int x) {
    // create new node has value x
    Node *pNode = new Node;
    pNode->key = x;
    pNode->pNext = NULL;

    if (isEmpty()) {
        pHead = pNode;
        pTail = pNode;
    } else {
        pTail->pNext = pNode;
        pTail = pNode;
    }

    size++;

    pNode = NULL;
    delete pNode;
}

// 2. delete an element out of queue (head element)
void Queue::del() {
    if (size == 0) {
        return ;
    }

    Node *pNode = pHead;
    pHead = pHead->pNext;

    size--;
    delete pNode;

}

// 3. get the element which is in head of queue
int Queue::getHead() {
    return pHead->key;
}

// 4. check whether queue is empty or not
bool Queue::isEmpty() {
    return size == 0 ? true : false;
}

// 5. get size of queue
int Queue::getSize() {
    return size;
}

int main() {
    Queue *q = new Queue;

    cout << "-------- before adding --------------" << endl;
    if ( ! q->isEmpty()) {
        cout << "queue is not empty !" << endl;
        cout << "head of queue: " << q->getHead() << endl;
        cout << "size of queue: " << q->getSize() << endl;
    } else {
        cout << "queue is empty ! " << endl;
    }

    // adding the elements to queue
    q->add(22);
    q->add(5);
    q->add(2003);
    q->add(11);
    q->add(4);
    q->add(2011);
    q->add(13);
    q->add(4);
    q->add(2011);

    cout << "---------- after adding --------" << endl;
    if ( ! q->isEmpty()) {
        cout << "queue is not empty !" << endl;
        cout << "head of queue: " << q->getHead() << endl;
        cout << "size of queue: " << q->getSize() << endl;
    } else {
        cout << "queue is empty ! " << endl;
    }

    // delete some elements
    q->del();
    q->del();

    cout << "-------- after deleting -------" << endl;
    if ( ! q->isEmpty()) {
        cout << "queue is not empty !" << endl;
        cout << "head of queue: " << q->getHead() << endl;
        cout << "size of queue: " << q->getSize() << endl;
    } else {
        cout << "queue is empty ! " << endl;
    }


    return 225;
}