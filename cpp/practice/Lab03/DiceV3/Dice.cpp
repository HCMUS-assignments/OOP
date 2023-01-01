#include "Dice.hpp"

Dice::Dice(){
    _rollCount = 0;
}

Dice::~Dice(){

}

int Dice::Roll(){
    _rollCount++;
    Random r = Random();
    int roll = r.Next();
    return roll % 6 + 1;
}

int Dice::RollCount() const{
    return _rollCount;
}

