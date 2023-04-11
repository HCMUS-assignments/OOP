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

// define
void Utils::Menu() {

}

vector<char*> Utils::Split(char* str) {
    char* token;
    vector<char*> tokens;
    char* delim = ", ";
    token = strtok(str, delim);
    while (token != NULL) {
        tokens.push_back(token);
        token = strtok(NULL, delim);
    }
    return tokens;
} 

char* Utils::standardized(char *src) {

}
