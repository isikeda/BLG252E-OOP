/* @Author
 * Student Name: Eda Işık
 * Student ID : 150200089
 */

#ifndef _Pokemon
#define _Pokemon

#include <iostream>


class Pokemon{
    public:
        Pokemon(std::string, int, int, int, int); //Constructor
        void printPokemon() const; 
        const std::string& getPokemonName()const {return this->name;} //returns the reference of the name of pokemon when called
        const int& getHitPoints()const {return this->hitPoints;} //returns the reference of the hitPoint of pokemon when called
        const int& getDamage()const {return this->damage;} //returns the reference of the damage of pokemon when called
        const bool& isInPowerUp()const {return this->powerUpState;} //returns the reference of the powerUpState of pokemon when called
        const bool& isInOwnTerrain()const {return this->inOwnTerrain;} //returns the reference of whether the pokemon is in own terrain or not when called
        const bool& isFainted()const {return this->fainted;} //returns the reference of whether the pokemon is fainted or not when called
        void setInOwnTerrain(const bool terrainStatus) {this->inOwnTerrain = terrainStatus;} //sets whether the pokemon is in own terrain or not according to the parameter
        void setFainted(const bool);
        void powerUp();
        void updateHitPoint(const int);
    protected: //protected members are reachable from inherited class
        const std::string name; //name of pokemon, constant
    private:
        int hitPoints; //hitpoints of pokemon
        const int damage; //damage value of pokemon, constant
        const int powerUpChange; //powerUpChange of pokemon, constant
        const int recharge; //recharge of pokemon, constant
        int rechargeCounter = 0; //recharge counter for power up method
        bool fainted = false; //whether the pokemon is fainted or not
        bool powerUpState = false; //whether the pokemon is in a power up state of not
        bool inOwnTerrain = false; //whether the pokemon is in own terrain or not

};

#endif 