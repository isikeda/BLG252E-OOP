/* @Author
 * Student Name:  Eda Işık
 * Student ID : 150200089
 */

#include <iostream>

#include "PsychicPokemon.h"

/*Constructor of the PsychicPokemon Class, member initializer list is used. 
  When an psychic pokemon enters the arena, information about it appears.*/
PsychicPokemon::PsychicPokemon(std::string inName, int inHitPoints, int inDamage):Pokemon(inName, inHitPoints, inDamage, 30, 5){
    printPokemon();
}

/*printPokemon method of the Psychic Pokemon Class, 
  this method is overrides the printPokemon method of the base Pokemon class. 
  Since Name, HP and Damage values are belong to the base class, after the class special messages appears, 
  the printPokemon method of the base class is called.*/
void PsychicPokemon::printPokemon()const{
    std::cout << "Psychic Pokemon " << this->name << " has entered the area." << "\n";
    std::cout << "Class: Psychic" << "\n";
    Pokemon::printPokemon();
}