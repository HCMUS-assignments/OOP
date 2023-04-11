#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <string.h>
using namespace std;

class Utils {
    public:
        // menu app
        static void Menu();

        // split char* into vector string, delimeter = ", "
        static vector<char*> Split(char* str) ;

        // standardized the string
        static char* standardized(char *src);
};


#endif
