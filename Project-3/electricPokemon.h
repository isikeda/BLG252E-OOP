/* @Author
 * Student Name:  Eda Işık
 * Student ID : 150200089
 */

#ifndef _ElectricPokemon
#define _ElectricPokemon

#include <iostream>
#include "pokemon.h"

class ElectricPokemon : public Pokemon{
    public:
        ElectricPokemon(std::string, int, int); //Constructor
        void printPokemon() const;
        const bool& getConfusionStatus()const {return this->confusionStatus;} //returns whether the electric pokemon is confused or not when called
        void setConfusionStatus(bool conf){this->confusionStatus = conf;} //sets the confusion status of the electric pokemon according to the parameter
    private:
        bool confusionStatus = false; //whether the electric pokemon is confused or not
};

#endif