#include "SinhVien.h"
#include <string.h>

// constructors
SinhVien::SinhVien()
{
    _fullname = NULL;
    _id = NULL;
    _birthday = NULL;
    _avg_mark = 0;

    _marks = new float[3];
    for (int i = 0; i < 3; i++)
    {
        _marks[i] = 0;
    }
}

SinhVien::SinhVien(char *fullname, char *id, char *birthday, float *marks)
{
    _fullname = new char[strlen(fullname) + 1];
    if (fullname != NULL)
    {
        strcpy(_fullname, fullname);
    }

    _id = new char[strlen(id) + 1];
    if (_id != NULL)
    {
        strcpy(_id, id);
    }

    _birthday = new char[strlen(birthday) + 1];
    if (_birthday != NULL)
    {
        strcpy(_birthday, birthday);
    }

    _marks = new float[3];
    for (int i = 0; i < 3; i++)
    {
        _marks[i] = marks[i];
    }
}

// destructor
SinhVien::~SinhVien()
{
    delete _fullname;
    delete _id;
    delete _birthday;
    delete[] _marks;
}

// copy constructor
SinhVien::SinhVien(const SinhVien &src)
{
    _fullname = new char[strlen(src._fullname) + 1];
    strcpy(_fullname, src._fullname);

    _id = new char[strlen(src._id) + 1];
    strcpy(_id, src._id);

    _birthday = new char[strlen(src._birthday) + 1];
    strcpy(_birthday, src._birthday);

    _marks = new float[3];
    for (int i = 0; i < 3; i++)
    {
        _marks[i] = src._marks[i];
    }

    _avg_mark = src._avg_mark;
}

// assignment operator
SinhVien &SinhVien::operator=(const SinhVien &src)
{
    if (this != &src)
    {
        delete _fullname, _id, _birthday, _marks;

        _fullname = new char[strlen(src._fullname) + 1];
        strcpy(_fullname, src._fullname);

        _id = new char[strlen(src._id) + 1];
        strcpy(_id, src._id);

        _birthday = new char[strlen(src._birthday) + 1];
        strcpy(_birthday, src._birthday);

        _marks = new float[3];
        for (int i = 0; i < 3; i++)
        {
            _marks[i] = src._marks[i];
        }

        _avg_mark = src._avg_mark;
    }
    return *this;
}

// setters
void SinhVien::setName(char *name)
{
    if (_fullname != NULL)
    {
        delete _fullname;
    }
    _fullname = new char[strlen(name) + 1];
    strcpy(_fullname, name);
}

void SinhVien::setId(char *id)
{
    if (_id != NULL)
    {
        delete _id;
    }

    _id = new char[strlen(id) + 1];
    strcpy(_id, id);
}

void SinhVien::setBirthday(char *birthday)
{
    if (_birthday != NULL)
    {
        delete _birthday;
    }

    _birthday = new char[strlen(birthday) + 1];
    strcpy(_birthday, birthday);
}

void SinhVien::setMarks(float *marks)
{
    for (int i = 0; i < 3; i++)
    {
        _marks[i] = marks[i];
    }
}

void SinhVien::setMark_BT(float score)
{
    _marks[0] = score;
}

void SinhVien::setMark_GK(float score)
{
    _marks[1] = score;
}

void SinhVien::setMark_CK(float score)
{
    _marks[2] = score;
}

void SinhVien::calcAvg()
{
    _avg_mark = _marks[0] * 0.25 + _marks[1] * 0.25 + _marks[2] * 0.5;
}

// getters
char *SinhVien::fullname()
{
    return _fullname;
}

char *SinhVien::id()
{
    return _id;
}

char *SinhVien::birthday()
{
    return _birthday;
}

float *SinhVien::marks()
{
    return _marks;
}

float SinhVien::mark_BT()
{
    return _marks[0];
}

float SinhVien::mark_GK()
{
    return _marks[1];
}

float SinhVien::mark_CK()
{
    return _marks[2];
}

float SinhVien::avg_mark()
{
    calcAvg();
    return _avg_mark;
}


