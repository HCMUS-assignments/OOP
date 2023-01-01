#ifndef _DICE_HPP
#define _DICE_HPP

#include "Random.hpp"

class Dice {
    private:
        int _rollCount;
    public:
        // default constructor
        Dice();

        // destructor
        ~Dice();

        // methods
        int Roll();

        int RollCount() const;

};

#endif