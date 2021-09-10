#ifndef POKEMON_H
#define POKEMON_H

#include <string>


class Pokemon
{
    public:

        Pokemon();
        virtual ~Pokemon();

        //--------Stat Functions-----//

        void CharmanderStats(); // Determines stats for Charmander
        void BulbasaurStats(); // Determines stats for Bulbasaur
        void SquirtleStats(); // Determines stats for Squirtle

        void setCurrentHealth(int h);

        int getCurrentHealth();

        void setPlayerSide();
        void setEnemySide();

        //----------Accessors---------//

        inline const std::string& getName() const { return this->name;}

        inline const int& getMaxHealth() const { return this->maxHealth;} 

        inline const int& getAttack() const { return this->attack;}

        inline const int& getSpeed() const { return this->speed;}

        inline const bool& getSideStatus() const { return this->friendOrFoe;}



    protected:

        std::string name;
         int maxHealth;
         int currentHealth;
         int attack;
         int speed;
         bool friendOrFoe;
};

#endif // POKEMON_H


