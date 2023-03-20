#include <iostream> 
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

#ifndef _SINHVIEN_H
#define _SINHVIEN_H

class SinhVien {
    private: 
        char *_fullname;
        char *_id;
        char *_birthday;
        float *_marks;
        float _avg_mark;

    public:
        // constructors
        SinhVien();     // default constructor
        SinhVien(char * , char * , char *, float* );

        // destructor
        ~SinhVien();

        // copy constructor
        SinhVien(const SinhVien& src);

        // assignment operator
        SinhVien& operator= (const SinhVien &);

        // methods
        // setters
        void setName(char* );

        void setId(char* );
         
        void setBirthday(char* );

        void setMarks(float* );

        void setMark_BT(float );

        void setMark_GK(float );

        void setMark_CK(float );

        void calcAvg();

        // getters
        char* fullname();

        char* id();

        char* birthday();

        float* marks();

        float mark_BT();

        float mark_GK();

        float mark_CK();

        float avg_mark();

        // friend functions
        friend istream& operator>> (istream&, SinhVien& );

        friend ostream& operator<< (ostream&, SinhVien );

        friend ifstream& operator>> (ifstream&, SinhVien& ); 

        friend ofstream& operator<< (ofstream&, SinhVien);



};

#endif