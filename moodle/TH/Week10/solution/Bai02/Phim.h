#ifndef PHIM_H
#define PHIM_H

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


class Phim {
    private:
        char* _id;     // 5 ki tu so
        char* _name;  // ten phim
        char* _type;  // the loai phim
        char* _publisher; // hang san xuat
        int _year; // nam san xuat
        int _rank; // xep hang

    public:
        // constructors 
        Phim();
        Phim(char* id, char* name, char* type, char* publisher, int year, int rank);
        Phim(const Phim& other);
        ~Phim();

        // getters
        char* getId();
        char* getName();
        char* getType();
        char* getPublisher();
        int getYear();
        int getRank();

        // setters
        void setId(char* id);
        void setName(char* name);
        void setType(char* type);
        void setPublisher(char* publisher);
        void setYear(int year);
        void setRank(int rank);

        // operators
        Phim& operator= (const Phim& other);    

        // input and output
        friend istream& operator>> (istream& is, Phim& phim);
        friend ostream& operator<< (ostream& os, Phim& phim);
        friend ifstream& operator>> (ifstream& ifs, Phim& phim);
        friend ofstream& operator<< (ofstream& ofs, Phim& phim);

};

#endif