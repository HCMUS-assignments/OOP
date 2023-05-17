#include "Phim.h"

Phim::Phim() {
    _id = NULL;
    _name = NULL;
    _type = NULL;
    _publisher = NULL;
    _year = 0;
    _rank = 0;
}

Phim::Phim(char *id, char* name, char* type, char* publisher, int year, int rank) {
    if (strlen(id) != 5) {
        cout << "ID phai co 5 ki tu so" << endl;
        return;
    }
    _id = new char[strlen(id) + 1];
    strcpy(_id, id);

    _name = new char[strlen(name) + 1];
    strcpy(_name, name);

    _type = new char[strlen(type) + 1];
    strcpy(_type, type);

    _publisher = new char[strlen(publisher) + 1];
    strcpy(_publisher, publisher);

    _year = year;
    _rank = rank;
}

Phim::Phim(const Phim& other) {
    _id = new char[strlen(other._id) + 1];
    strcpy(_id, other._id);

    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);

    _type = new char[strlen(other._type) + 1];
    strcpy(_type, other._type);

    _publisher = new char[strlen(other._publisher) + 1];
    strcpy(_publisher, other._publisher);

    _year = other._year;
    _rank = other._rank;
}

Phim::~Phim() {
    if (_id != NULL) delete[] _id;
    if (_name != NULL) delete[] _name;
    if (_type != NULL) delete[] _type;
    if (_publisher != NULL) delete[] _publisher;
}

char* Phim::getId() {
    return _id;
}

char* Phim::getName() {
    return _name;
}

char* Phim::getType() {
    return _type;
}

char* Phim::getPublisher() {
    return _publisher;
}

int Phim::getYear() {
    return _year;
}

int Phim::getRank() {
    return _rank;
}

void Phim::setId(char* id) {
    if (strlen(id) != 5) {
        cout << "ID phai co 5 ki tu so" << endl;
        return;
    }
    if (_id != NULL) delete[] _id;
    _id = new char[strlen(id) + 1];
    strcpy(_id, id);
}

void Phim::setName(char* name) {
    if (_name != NULL) delete[] _name;
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
}

void Phim::setType(char* type) {
    if (_type != NULL) delete[] _type;
    _type = new char[strlen(type) + 1];
    strcpy(_type, type);
}

void Phim::setPublisher(char* publisher) {
    if (_publisher != NULL) delete[] _publisher;
    _publisher = new char[strlen(publisher) + 1];
    strcpy(_publisher, publisher);
}

void Phim::setYear(int year) {
    _year = year;
}

void Phim::setRank(int rank) {
    _rank = rank;
}

Phim& Phim::operator= (const Phim& other) {
    if (_id != NULL) delete[] _id;
    _id = new char[strlen(other._id) + 1];
    strcpy(_id, other._id);

    if (_name != NULL) delete[] _name;
    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);

    if (_type != NULL) delete[] _type;
    _type = new char[strlen(other._type) + 1];
    strcpy(_type, other._type);

    if (_publisher != NULL) delete[] _publisher;
    _publisher = new char[strlen(other._publisher) + 1];
    strcpy(_publisher, other._publisher);

    _year = other._year;
    _rank = other._rank;

    return *this;
}

istream& operator>> (istream& is, Phim& phim) {

}

ostream& operator<< (ostream& os, Phim& phim) {

}

ifstream& operator<< (ifstream& fin, Phim& phim) {

}

ofstream& operator<< (ofstream& fout, Phim& phim) {

}

