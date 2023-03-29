#include "Person.h"

Person::Person(long id) : identity(id)
{
    assert(identity >= 100000000 && identity <= 999999999);
}

// cài đặt các constructors và assignment operators

// constructors
Person::Person()
{
    identity = 0;
}

Person::~Person()
{
    identity = 0;
}

// copy constructor
Person::Person(const Person &person)
{
    identity = person.identity;
}

// getter
long Person::getId() const
{
    return identity;
}

// setter
void Person::setId(long id)
{
    identity = id;
}

// other methods
void Person::print()
{
    cout << "\nID: " << identity << endl;
}

// assignment operator
Person& Person:: operator=(const Person &p)
{
    if (this != &p) {
        identity = p.identity;
    }
    return *this;
}
