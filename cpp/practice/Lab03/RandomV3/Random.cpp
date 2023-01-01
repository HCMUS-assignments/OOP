#include "Random.hpp"

Random::Random(){
    srand(time(NULL));
}

Random::~Random(){

}

int Random::Next(){
    return rand();
}

int Random::Next(int max){
    return rand() % max;
}

