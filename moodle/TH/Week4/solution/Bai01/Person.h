#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

class Person {
    private:
        long identity;

    public:
        // constructors
        Person();
        Person(long id);

        // destructors
        ~Person();

        // copy constructor
        Person(const Person &);

        // getter
        long getId() const;
        
        // setter
        void setId(long id);

        // other methods
        void print();

        // assignment operator
        Person & operator= (const Person &);
};

#endif