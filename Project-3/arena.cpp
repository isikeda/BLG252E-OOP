/* @Author
 * Student Name: Eda Işık
 * Student ID : 150200089
 */

#include <iostream>

#include "arena.h"
#include "electricPokemon.h"
#include "psychicPokemon.h"

/*Constructor of the Arena class
  pointers that point to the electric and psychic pokemons setted as NULL*/
Arena::Arena(){
    this->battleElectricPokemon = NULL;
    this->battlePsychicPokemon = NULL;
}

/*This method gets the type of the pokemon, its name, its hit points and its damage values
  Then initializes the pokemons according to this values
  If new Pokemons enter the arena for a battle, the terrain is reset.*/
void Arena::addPokemon(char type, std::string pokemonName, int pokemonHitPoints, int pokemonDamage){
    if(type == 'e'){
        this->battleElectricPokemon = new ElectricPokemon(pokemonName, pokemonHitPoints, pokemonDamage);
    }else if(type == 'p'){
        this->battlePsychicPokemon = new PsychicPokemon(pokemonName, pokemonHitPoints, pokemonDamage);
    }
    restartTerrain();
}

/*This method simulates the battle with two pokemons*/
void Arena::simulateBattle(){
    int round = 1; /*round is initialized with 1*/
    currentTerrain = "none"; /*current terrain is reset to none at every battle begining*/
    terrainCounter = 0; /*terrain counter is reset to zero at every battle begining*/
    int heads = rand() % 2; /*First attacker determines randomly*/
    
    while(true){ /*Loop is goes until one pokemon faints*/ 
        if(currentTerrain == "none") spawnTerrain(); /*If terrain is none, spawns terrain before each round*/
        if(currentTerrain == "electric" || currentTerrain == "psychic") terrainCounter++; /*If terrain is electric or psychic the counter increases by one*/
        
        /*electric and psychic pokemon's isInOwnTerrain attributes updated if there is a need*/
        (currentTerrain == "electric") ? battleElectricPokemon->setInOwnTerrain(true) : battleElectricPokemon->setInOwnTerrain(false);
        (currentTerrain == "psychic") ? battlePsychicPokemon->setInOwnTerrain(true) : battlePsychicPokemon->setInOwnTerrain(false);

        int confusionCounter; /*the confusion counter of electric pokemon*/

        /*pokemons initializes or not power ups according to the possibilities and recharge values*/
        battleElectricPokemon->powerUp();
        battlePsychicPokemon->powerUp();
        
        /*temporary damage values of pokemons are initialized*/
        int tmpElectricDamage = battleElectricPokemon->getDamage();
        int tmpPsychicDamage = battlePsychicPokemon->getDamage();


        if(heads){ /*electric pokemon goes first*/
            /*electric pokemon attacks*/
            /*if electric pokemon is at a power up state, its damage is 300% for one round*/
            if(battleElectricPokemon->isInPowerUp()){ 
                tmpElectricDamage *= 3;
            }
            /*if electric pokemon is confused and is in its own terrain, the confusion ends since being in electric 
              terrain makes it immune to the confusion*/
            if(battleElectricPokemon->getConfusionStatus()){
                if(battleElectricPokemon->isInOwnTerrain()){
                    battleElectricPokemon->setConfusionStatus(false);
                }else{
                    /*if it is confused and is not in its own terrain, its damage set to the zero for that round and 
                      confusion counter decreases by one
                      when the counter is zero, the confusion ends*/
                    tmpElectricDamage = 0;
                    confusionCounter--;
                    if(!confusionCounter) battleElectricPokemon->setConfusionStatus(false);
                }
            }
            /*if damage of electric pokemon is greater than or equal to the hit point of the psychic pokemon 
              the psychic pokemon faints, round information and match results are printed*/
            if((battlePsychicPokemon->getHitPoints() - tmpElectricDamage) <= 0){
                battlePsychicPokemon->setFainted(true);
                winnerPokemon = battleElectricPokemon->getPokemonName();
                printRoundStats(round, heads);
                printMatchResults();
                break;
            }else{ /*if damage of electric pokemon is smaller than to the hit point of the psychic pokemon
                     the electric pokemon attacks to the psychic pokemon and decreases its hit points*/
                battlePsychicPokemon->updateHitPoint(tmpElectricDamage);
            }
            /*psychic pokemon attacks*/
            /*if psychic pokemon is in own terrain, damage of it doubles for one round*/
            if(battlePsychicPokemon->isInOwnTerrain()){
                tmpPsychicDamage *= 2;
            }
            /*if damage of psychic pokemon is greater than or equal to the hit point of the electric pokemon 
              the electric pokemon faints, round information and match results are printed*/
            if((battleElectricPokemon->getHitPoints() - tmpPsychicDamage) <= 0){
                battleElectricPokemon->setFainted(true);
                winnerPokemon = battlePsychicPokemon->getPokemonName();
                printRoundStats(round, heads);
                printMatchResults();
                break;
            }else{/*if damage of psychic pokemon is smaller than to the hit point of the electric pokemon
                    the psychic pokemon attacks to the electric pokemon and decreases its hit points*/
                battleElectricPokemon->updateHitPoint(tmpPsychicDamage);
            }
        }
        else{ /*psychic pokemon goes first*/ 
        /*everything is same but just the order of attacker pokemons with the if block
          (not: i just implemented the methods whose prototypes are given, for this reason i repeated somethings in my implementation)*/
            /*psychic pokemon attacks*/
            if(battlePsychicPokemon->isInOwnTerrain()){
                tmpPsychicDamage *= 2;
            }
            if((battleElectricPokemon->getHitPoints() - tmpPsychicDamage) <= 0){
                battleElectricPokemon->setFainted(true);
                winnerPokemon = battlePsychicPokemon->getPokemonName();
                printRoundStats(round, heads);
                printMatchResults();
                break;
            }else{
                battleElectricPokemon->updateHitPoint(tmpPsychicDamage);
            }
            //electric pokemon attacks
            if(battleElectricPokemon->isInPowerUp()){
                tmpElectricDamage *= 3;
            }
            if(battleElectricPokemon->getConfusionStatus()){
                if(battleElectricPokemon->isInOwnTerrain()){
                    battleElectricPokemon->setConfusionStatus(false);
                }else{
                    tmpElectricDamage = 0;
                    confusionCounter--;
                    if(!confusionCounter) battleElectricPokemon->setConfusionStatus(false);
                }
            }
            if((battlePsychicPokemon->getHitPoints() - tmpElectricDamage) <= 0){
                battlePsychicPokemon->setFainted(true);
                winnerPokemon = battleElectricPokemon->getPokemonName();
                printRoundStats(round, heads);
                printMatchResults();
                break;
            }else{
                battlePsychicPokemon->updateHitPoint(tmpElectricDamage);
            }
        }
        /*round information is printed after every round*/
        printRoundStats(round, heads);
        /*ElectricPokemon's confusion status and counter are set if necessary*/
        if(battlePsychicPokemon->isInPowerUp() && !battleElectricPokemon->isInOwnTerrain()){
            battleElectricPokemon->setConfusionStatus(true);
            confusionCounter = 3;
        }
        
        /*attacking pokemon changes*/
        heads = (heads == 1) ? 0 : 1;
        /*round increases by one*/
        round++;
        /*if terrain counter is 5, there is a need to spawning the terrain*/
        if(terrainCounter == 5) spawnTerrain();
    }
    /*Electric Pokemon and Psychic Pokemon pointers are deleted after the battle ends
      two new pokemons are accepted for new battle*/
    delete battleElectricPokemon;
    delete battlePsychicPokemon;
}

/*This methods prints the round information according the sample output*/
void Arena::printRoundStats(int round, int heads)const{
    std::cout << "Round: " << round << "\n";
    std::cout << "Current Terrain: " << this->currentTerrain << "\n";
    std::string first = (heads == 1) ? battleElectricPokemon->getPokemonName() : battlePsychicPokemon->getPokemonName();
    std::cout << first << " goes first." << "\n";
    if(battleElectricPokemon->isInPowerUp()){
        std::cout <<  battleElectricPokemon->getPokemonName() << " has initiated a power up." << "\n";
    } 
    if(battlePsychicPokemon->isInPowerUp()){
        std::cout <<  battlePsychicPokemon->getPokemonName() << " has initiated a power up." << "\n";
    } 
    std::cout << battleElectricPokemon->getPokemonName() << " HP: " << battleElectricPokemon->getHitPoints() << "\n";
    std::cout << battlePsychicPokemon->getPokemonName() << " HP: " << battlePsychicPokemon->getHitPoints() << "\n";
    if(battleElectricPokemon->getHitPoints() == battlePsychicPokemon->getHitPoints()){
        std::cout << "It is a tie!" << "\n\n\n";
    }else if(battleElectricPokemon->getHitPoints() > battlePsychicPokemon->getHitPoints()){
        std::cout << battleElectricPokemon->getPokemonName() << " is in the lead!" << "\n\n\n";
    }else{
        std::cout << battlePsychicPokemon->getPokemonName() << " is in the lead!" << "\n\n\n";
    }
}

/*This method determines the terrain that battle goes on according to the probabilities that given
  With 20% probability the terrain is electric
  With 20% probability the terrain is psychic
  With 60% probability the terrain is none*/
void Arena::spawnTerrain(){
    int decision = rand() % 100 + 1;
    if(decision <= 20){
        currentTerrain = "electric";
        terrainCounter = 0;
    } 
    else if(decision <= 40){
        currentTerrain = "psychic";
        terrainCounter = 0;
    } 
    else currentTerrain = "none";
}

/*This method spawns terrain when called*/
void Arena::restartTerrain(){
    spawnTerrain();
}

/*This method prints the match results when a pokemon faints*/
void Arena::printMatchResults(){
    std::cout << "Match results: " << "\n";
    std::cout << winnerPokemon << " has won the match!" << "\n\n\n";
}