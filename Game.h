#ifndef GAME_H
#define GAME_H

#include "Pokemon.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>

class Game
{
    public:
        Game(); // ctor

        virtual ~Game(); //dtor


        //-------------Game functions------------//


        void playGame(); // holds all the game functions and loops


        //-----------End game functions----------//

        bool retry(); // Asks the user if they want to play again



        //********************** Friend functions ***********************//


        //------Beginning Game Functions-----//

        friend int choosePoke(); // Chooses Pokemon for the user

        friend int chooseAiPoke(); // Chooses Pokemon for the AI randomly based on the choices that are left. Sends integer to createAiPokemon(int a)

        friend void createPokemon(); // Creates the object for the user's Pokemon and then generates stats for that Pokemon object

        friend void createAiPokemon(int a); // Creates an object for the AI's Pokemon and then generates their stats. Receives integer from chooseAiPoke()


        //----------Battle functions---------//


        friend void printInfo(Pokemon & a, Pokemon & b); // Prints info of both Pokemon at the beginning of each fight


        friend void speedCheck(Pokemon & a, Pokemon & b); // Called in battle. Determines when each Pokemon moves

        friend int tieBreaker(Pokemon & a, Pokemon & b); // In the event both Pokemon have the same speed, randomly determines who goes first


        friend void playerTurn(Pokemon & p, Pokemon & e);

        friend void enemyTurn(Pokemon & p, Pokemon & e);


        friend void calculateDamage(Pokemon & a, Pokemon & b); // Displays damage done and calculates post-damage health

        friend bool healthCheck(Pokemon & x); // Checks health after a Pokemon attacks to see if the defending Pokemon can still fight.

        friend void declareWinner(Pokemon & a, Pokemon & b); // Declares the winner of the battle


        friend void battle(Pokemon & a, Pokemon & b); // Function that calls all functions necessary for the battle

        friend bool fightOn(Pokemon & a, Pokemon & b); // Sentinel for do-while loop to end battle when false

        friend void displaySprite(); // Display sprite of winning Pokemon


};

#endif // GAME_H
