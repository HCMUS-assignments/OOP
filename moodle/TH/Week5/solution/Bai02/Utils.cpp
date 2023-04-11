#include "Utils.h"


// define
void Utils::Menu() {

}

vector<char*> Utils::Split(char* str) {
    char* token;
    vector<char*> tokens;
    char* delim = new char[3];
    strcpy(delim, ",");
    token = strtok(str, delim);
    while (token != NULL) {
        token = standardized(token);
        tokens.push_back(token);
        token = strtok(NULL, delim);
    }
    return tokens;
} 

char* Utils::standardized(char *src) {
    int i = 0;
    while (src[i] == ' ') {
        i++;
    }
    strcpy(src, src + i);
    i = strlen(src) - 1;
    while (src[i] == ' ') {
        i --;
    }
    src[i + 1] = '\0';
    return src;

}