#include "Pokemon.h"
#include "Game.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>


Pokemon::Pokemon()
{
    this->maxHealth = 0;
    this->currentHealth = 0;
    this->attack = 0;
    this->speed = 0;
} //ctor

Pokemon::~Pokemon(){} //dtor

void Pokemon::setCurrentHealth(int h)
{
    if(h < 0) { h = 0; }

    this->currentHealth = h;
}

//----

int Pokemon::getCurrentHealth() { return this->currentHealth;}

//-----------

void Pokemon::setPlayerSide(){ this->friendOrFoe = true;}

void Pokemon::setEnemySide(){ this->friendOrFoe = false;}

//---------Pokemon Stat Functions------/

void Pokemon::CharmanderStats()
{
    //-----Set Name----/

    this->name = "Charmander";

    //-----Set Health-----/
    int hStat = 0;

    int lower = 23;
    int upper = 25;

    srand (time(0));
    hStat = (rand() % (upper - lower + 1)) + lower;

    this->maxHealth = hStat;
    this->currentHealth = maxHealth;


    //----Set Attack----/

    int aStat = 0;

    int l = 7;
    int u = 9;

    srand (time(0));
    aStat = (rand() % (u - l + 1)) + l;

    this->attack = aStat;



    //----Set Speed---/

    int spdStat = 0;

    int low = 6;
    int up = 8;

    srand (time(0));
    spdStat = (rand() % (up - low + 1)) + low;

    this->speed = spdStat;

}


//-----



void Pokemon::BulbasaurStats()
{
    //-----Set Name----/

    this->name = "Bulbasaur";

    //-----Set Health-----/
    int hStat = 0;

    int lower = 29;
    int upper = 34;

    srand (time(0));
    hStat = (rand() % (upper - lower + 1)) + lower;

    this->maxHealth = hStat;
    this->currentHealth = maxHealth;


    //----Set Attack----/

    int aStat = 0;

    int low = 5;
    int up = 7;

    srand (time(0));
    aStat = (rand() % (up - low + 1)) + low;

    this->attack = aStat;



    //----Set Speed---/

    int spdStat = 0;

    int l = 3;
    int u = 5;

    srand (time(0));
    spdStat = (rand() % (u - l + 1)) + l;

    this->speed = spdStat;

}
        //------




void Pokemon::SquirtleStats()
{
    //-----Set Name----/

    this->name = "Squirtle";

    //-----Set Health-----/
    int hStat = 0;

    int lower = 25;
    int upper = 28;

    srand (time(0));
    hStat = (rand() % (upper - lower + 1)) + lower;

    this->maxHealth = hStat;
    this->currentHealth = maxHealth;


    //----Set Attack----/

    int aStat = 0;

    int l = 6;
    int u = 8;

    srand (time(0));
    aStat = (rand() % (u - l + 1)) + l;

    this->attack = aStat;



    //----Set Speed---/

    int spdStat = 0;

    int low = 4;
    int up = 6;

    srand (time(0));
    spdStat = (rand() % (up - low + 1)) + low;

    this->speed = spdStat;

}

//-------------



/**
 *Pokemon class Description:
 *
 * In the nested functions of the Game class, a switch case creates objects for the player and the AI
 * When object is created, unique stats (maxHealth, currentHealth = maxHealth, attack, speed)
 * for three Pokemon (Charmander, Squirtle, Bulbasaur) are generated via functions for each Pokemon
 *
 * Charmander will be stronger, faster, but less tanky
 * Squirtle will have balanced attack, health, and speed
 * Bulbasaur will be tankier, but slower, and neutral attack
 *
 * Need to experiment with stats a little more.
 *
 **/
