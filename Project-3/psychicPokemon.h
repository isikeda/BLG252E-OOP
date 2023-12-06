/* @Author
 * Student Name:  Eda Işık
 * Student ID : 150200089
 */

#ifndef _PsychicPokemon
#define _PsychicPokemon

#include <iostream>
#include "pokemon.h"

class PsychicPokemon : public Pokemon{
    public:
        PsychicPokemon(std::string, int, int); //constructor
        void printPokemon() const;
};

#endif