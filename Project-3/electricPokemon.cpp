/* @Author
 * Student Name:  Eda Işık
 * Student ID : 150200089
 */

#include <iostream>

#include "ElectricPokemon.h"

/*Constructor of the ElectricPokemon Class, member initializer list is used. 
  When an electric pokemon enters the arena, information about it appears.*/
ElectricPokemon::ElectricPokemon(std::string inName, int inHitPoints, int inDamage):Pokemon(inName, inHitPoints, inDamage, 20, 3){
    printPokemon();
}

/*printPokemon method of the Electric Pokemon Class, 
  this method is overrides the printPokemon method of the base Pokemon class. 
  Since Name, HP and Damage values are belong to the base class, after the class special messages appears, 
  the printPokemon method of the base class is called.*/
void ElectricPokemon::printPokemon()const{
    std::cout << "Electric Pokemon " << this->name << " has entered the area." << "\n";
    std::cout << "Class: Electric" << "\n";
    Pokemon::printPokemon();
}