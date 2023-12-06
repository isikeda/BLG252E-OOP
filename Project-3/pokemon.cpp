/* @Author
 * Student Name:  Eda Işık
 * Student ID : 150200089
 */

#include <iostream>

#include "Pokemon.h"

/*Constructor of the Pokemon class, member initializer list is used for initializing the constant values*/
Pokemon::Pokemon(std::string inName, int inHitPoints, int inDamage, int inPowerUpChange, int inRecharge):name{inName}, hitPoints{inHitPoints}, damage{inDamage}, powerUpChange{inPowerUpChange}, recharge{inRecharge} {}

/*printPokemon method of the Pokemon Class, it prints the pokemon's informations*/
void Pokemon::printPokemon()const{
    std::cout << "\tName: " << this->name << "\n";
    std::cout << "\tHP: " << this->hitPoints << "\n";
    std::cout << "\tDamage: " << this->damage << "\n\n\n";
}

/*This method determines whether a pokemon is in a power up or not according to the powerUpChange
  If pokemon is in a powerUp, the counter is set to the recharge value
  Thanks to this counter, a pokemon cannot attempt powerUp everytime*/
void Pokemon::powerUp(){
    if(rechargeCounter > 0){
        rechargeCounter--;
        powerUpState = false;
        return;
    }
    /*decision is an integer value between 1 and 100
      if it is smaller than or equal to the powerUpChange of the pokemon,
      the pokemon initializes a power up*/
    int decision = rand() % 100 + 1;
    if(decision <= this->powerUpChange){
        powerUpState = true;
        rechargeCounter = recharge;
    } 
}

/*This method is used for update the hitpoint of the pokemon
  parameter is receivingDamage, the damage value of the attacking pokemon at that time*/
void Pokemon::updateHitPoint(const int receivingDamage){
    hitPoints -= receivingDamage;
}

/*This method is for setting the fainted status of the pokemon,
  If pokemon is fainted, the HitPoint of it is setted to the zero.*/
void Pokemon::setFainted(const bool faintStatus){
    this->fainted = faintStatus;
    this->hitPoints = 0;
}
