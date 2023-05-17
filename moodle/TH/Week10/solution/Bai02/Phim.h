#ifndef PHIM_H
#define PHIM_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;


class Phim {
    private:
        char* _id;     // 5 ki tu so
        char* _name;  // ten phim
        char* _type;  // the loai phim
        char* _proceducer ; // hang san xuat
        int _year; // nam san xuat
        int _rank; // xep hang

    public:
        // constructors 
        Phim();
        Phim(const char* id, const char* name, const char* type, const char* proceducer, int year, int rank);
        Phim(const Phim& other);
        ~Phim();

        // getters
        char* getId();
        char* getName();
        char* getType();
        char* getProceducer();
        int getYear();
        int getRank();

        // setters
        void setId(char* id);
        void setName(char* name);
        void setType(char* type);
        void setProceducer(char* publisher);
        void setYear(int year);
        void setRank(int rank);

        // operators
        Phim& operator= (const Phim& other);    

        // input and output
        friend istream& operator>> (istream& is, Phim& phim);
        friend ostream& operator<< (ostream& os, Phim& phim);
        friend ifstream& operator>> (ifstream& fin, Phim& phim);
        friend ofstream& operator<< (ofstream& fout, Phim& phim);

};

#endif