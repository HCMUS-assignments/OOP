#include "Phim.h"

Phim::Phim()
{
    _id = NULL;
    _name = NULL;
    _type = NULL;
    _proceducer = NULL;
    _year = 0;
    _rank = 0;
}

Phim::Phim(const char *id, const char *name, const char *type, const char *proceducer, int year, int rank)
{
    if (strlen(id) != 5)
    {
        cout << "ID phai co 5 ki tu so" << endl;
        return;
    }
    _id = new char[strlen(id) + 1];
    strcpy(_id, id);

    _name = new char[strlen(name) + 1];
    strcpy(_name, name);

    _type = new char[strlen(type) + 1];
    strcpy(_type, type);

    _proceducer = new char[strlen(proceducer) + 1];
    strcpy(_proceducer, proceducer);

    _year = year;
    _rank = rank;
    cout << "Da tao phim " << _name << " co ID " << _id << endl;
}

Phim::Phim(const Phim &other)
{
    _id = new char[strlen(other._id) + 1];
    strcpy(_id, other._id);

    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);

    _type = new char[strlen(other._type) + 1];
    strcpy(_type, other._type);

    _proceducer = new char[strlen(other._proceducer) + 1];
    strcpy(_proceducer, other._proceducer);

    _year = other._year;
    _rank = other._rank;
}

Phim::~Phim()
{
    if (_id != NULL)
        delete[] _id;
    if (_name != NULL)
        delete[] _name;
    if (_type != NULL)
        delete[] _type;
    if (_proceducer != NULL)
        delete[] _proceducer;
}

char *Phim::getId()
{
    return _id;
}

char *Phim::getName()
{
    return _name;
}

char *Phim::getType()
{
    return _type;
}

char *Phim::getProceducer()
{
    return _proceducer;
}

int Phim::getYear()
{
    return _year;
}

int Phim::getRank()
{
    return _rank;
}

void Phim::setId(char *id)
{
    if (strlen(id) != 5)
    {
        cout << "ID phai co 5 ki tu so" << endl;
        return;
    }
    if (_id != NULL)
        delete[] _id;
    _id = new char[strlen(id) + 1];
    strcpy(_id, id);
}

void Phim::setName(char *name)
{
    if (_name != NULL)
        delete[] _name;
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
}

void Phim::setType(char *type)
{
    if (_type != NULL)
        delete[] _type;
    _type = new char[strlen(type) + 1];
    strcpy(_type, type);
}

void Phim::setProceducer(char *proceducer)
{
    if (_proceducer != NULL)
        delete[] _proceducer;
    _proceducer = new char[strlen(proceducer) + 1];
    strcpy(_proceducer, proceducer);
}

void Phim::setYear(int year)
{
    _year = year;
}

void Phim::setRank(int rank)
{
    _rank = rank;
}

Phim &Phim::operator=(const Phim &other)
{
    if (_id != NULL)
        delete[] _id;
    _id = new char[strlen(other._id) + 1];
    strcpy(_id, other._id);

    if (_name != NULL)
        delete[] _name;
    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);

    if (_type != NULL)
        delete[] _type;
    _type = new char[strlen(other._type) + 1];
    strcpy(_type, other._type);

    if (_proceducer != NULL)
        delete[] _proceducer;
    _proceducer = new char[strlen(other._proceducer) + 1];
    strcpy(_proceducer, other._proceducer);

    _year = other._year;
    _rank = other._rank;

    return *this;
}

istream &operator>>(istream &is, Phim &phim)
{
    string id;
    fflush(stdin);
    do
    {
        cout << "Nhap ma so phim (5 ki tu so): ";
        getline(cin, id);
    } while (id.length() != 5);

    cout << "Nhap ten phim: ";
    string name;
    getline(cin, name);
    cout << "Nhap the loai phim: ";
    string type;
    getline(cin, type);
    cout << "Nhap hang san xuat: ";
    string proceducer;
    getline(cin, proceducer);
    cout << "Nhap nam san xuat: ";

    int year;
    cin >> year;
    cout << "Nhap xep hang: ";
    int rank;
    cin >> rank;
    Phim temp(id.c_str(), name.c_str(), type.c_str(), proceducer.c_str(), year, rank);
    phim = temp;
    return is;
}

ostream &operator<<(ostream &os, Phim &phim)
{
    os << "------------------------------------------" << endl;
    os << "Ma so phim: " << phim._id << endl;
    os << "Ten phim: " << phim._name << endl;
    os << "The loai phim: " << phim._type << endl;
    os << "Hang san xuat: " << phim._proceducer << endl;
    os << "Nam san xuat: " << phim._year << endl;
    os << "Xep hang: " << phim._rank << endl;
    return os;
}

ifstream &operator<<(ifstream &fin, Phim &phim)
{
    string line;
    getline(fin, line);
    stringstream ss(line);
    string token;
    getline(ss, token, ',');
    phim.setId((char *)token.c_str());
    getline(ss, token, ',');
    phim.setName((char *)token.c_str());
    getline(ss, token, ',');
    phim.setType((char *)token.c_str());
    getline(ss, token, ',');
    phim.setProceducer((char *)token.c_str());
    getline(ss, token, ',');
    phim.setYear(atoi(token.c_str()));
    getline(ss, token, ',');
    phim.setRank(atoi(token.c_str()));
    return fin;

}

ofstream &operator<<(ofstream &fout, Phim &phim)
{
    fout << phim._id << "," << phim._name << "," << phim._type << "," << phim._proceducer << "," << phim._year << "," << phim._rank << endl;
    return fout;
}
