#ifndef UTILS_H
#define UTILS_H


#include <vector>
#include <string>
#include <string.h>
#include <iomanip>
#include <iostream>
using namespace std;

class Utils {
    public:
        // menu app
        static int Menu();

        // split char* into vector string, delimeter = ", "
        static vector<char*> Split(char* str) ;

        // standardized the string
        static char* standardized(char *src);
};


#endif
