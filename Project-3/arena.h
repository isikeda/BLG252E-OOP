/* @Author
 * Student Name:  Eda Işık
 * Student ID : 150200089
 */

#ifndef _Arena
#define _Arena

#include <iostream>
#include <cstdlib>
#include "electricPokemon.h"
#include "psychicPokemon.h"

class Arena{
    public:
        Arena(); //Constructor
        void addPokemon(char, std::string, int, int);
        void simulateBattle();
        void spawnTerrain();
        void restartTerrain();
        void printRoundStats(int, int) const;
        void printMatchResults();
        
    private:
        ElectricPokemon *battleElectricPokemon; //The pointer that points to the electric pokemon at the arena
        PsychicPokemon *battlePsychicPokemon; //The pointer that points to the psychic pokemon at the arena
        std::string currentTerrain = "none"; //The terrain that battle goes on, initially none
        std::string winnerPokemon; //The winner pokemon of the battle
        int terrainCounter = 0; //The terrain counter for spawning the terrain
};


#endif