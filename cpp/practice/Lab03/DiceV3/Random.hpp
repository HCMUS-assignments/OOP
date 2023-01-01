#ifndef _RANDOM_HPP
#define _RANDOM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
    public:
        // default constructor
        Random();

        // destructor
        ~Random();

        // methods
        int Next();
        int Next(int max);


};

#endif