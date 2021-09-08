#include "Game.h"
#include "Pokemon.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>


Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

//-----------------------------------------


int choosePoke() // Friend function: Returns choice int to createPokemon() to make Pokemon object for player.
 {
     int choice = 0;

     std::cout << "Enter a number to choose your Pokemon: \n"
              << "1: Charmander \n"
              << "2: Squirtle \n"
              << "3: Bulbasaur \n" << std::endl;


    while(!(std::cin >> choice))
    {
        std::cout << "Invalid input. Please enter a number. \n";

        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }


     if(choice > 0 && choice < 4)
     {
        return choice;
     }

     else if(choice <= 0 || choice >= 4)
     {
        std::cout << "Invalid number entered. Please try again. \n";

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        choosePoke();
     }

 }

//-----------------------------------------


int chooseAiPoke(int a, int b) // Friend function. Chooses between remaining two choices so they don't have the same Pokemon
{
    int choice = 0;

    int randNum = 0;

    int l = 4;
    int u = 5;

    randNum = (rand() % (u - l + 1)) + l;

    if(randNum == 4)
    {
        choice = a;
    }

    else if(randNum == 5)
    {
        choice = b;
    }


    return choice;
}

//-----------------------------------------


void createAiPokemon(Pokemon & enemy, int a) //Friend function: Creates Pokemon Object for the AI
 {
    switch(a)
    {
        case 1:
        {
            enemy.CharmanderStats();
            enemy.setEnemySide();

        }
        break;

        case 2:
        {
            enemy.SquirtleStats();
            enemy.setEnemySide();
        }
        break;


        case 3:
        {
            enemy.BulbasaurStats();
            enemy.setEnemySide();
        }
        break;
    }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
 }


//-------

void createPokemon(Pokemon & player, Pokemon & enemy) // Friend function: Creates Pokemon Object for the user. Once choice is made, calls createAiPoke() for the AI
 {
    switch(choosePoke())  // Add a function call to where it can choose the Pokemon for the AI out of the remaining choices
    {
        case 1:
        {
            player.CharmanderStats();
            player.setPlayerSide();
            createAiPokemon(enemy, chooseAiPoke(2, 3) );
        }
        break;

        case 2:
        {
            player.SquirtleStats();
            player.setPlayerSide();
            createAiPokemon(enemy, chooseAiPoke(1, 3 )); //If 2 is selected in chooseAiPoke(), it defaults to 3
        }
        break;


        case 3:
        {
            player.BulbasaurStats();
            player.setPlayerSide();
            createAiPokemon(enemy, chooseAiPoke(1, 2) );
        }
        break;
    }
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
 }

 //-------


void printInfo(Pokemon & a, Pokemon & b)  //Friend function
{
  std::cout << std::endl;
  std::cout << "Player's " << a.getName() << "\n";
  std::cout << a.getCurrentHealth() << " / " << a.getMaxHealth() << std::endl;
  std::cout << a.getAttack() << std::endl;
  std::cout << a.getSpeed() << "\n\n";


  std::cout << "Enemy's "  << b.getName() << "\n";
  std::cout << b.getCurrentHealth() << " / " << b.getMaxHealth() << std::endl;
  std::cout << b.getAttack() << std::endl;
  std::cout << b.getSpeed() << "\n\n\n";

}

//-----------------------------------------

void displaySprite(Pokemon & x)
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    if(x.getName() == "Charmander")
    {
        sf::Texture texture;
        if (!texture.loadFromFile("assets/charmander sprite.jpg"))
        {
            std::cout << "Could not load charmander texture" << std::endl;
        }

        sf::Sprite charmanderSprite;
        charmanderSprite.setTexture(texture);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(charmanderSprite);
            window.display();
        }
    }

    //-----

    else if(x.getName() == "Squirtle")
    {
        sf::Texture texture;
        if (!texture.loadFromFile("assets/squirtle sprite.jpg"))
        {
            std::cout << "Could not load squirtle texture" << std::endl;
        }

        sf::Sprite squirtleSprite;
        squirtleSprite.setTexture(texture);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(squirtleSprite);
            window.display();
        }

    }

    //-------

    else if(x.getName() == "Bulbasaur")
    {
        sf::Texture texture;
        if (!texture.loadFromFile("assets/bulbasaur sprite.jpg"))
        {
            std::cout << "Could not load bulbasaur texture" << std::endl;
        }

        sf::Sprite bulbasaurSprite;
        bulbasaurSprite.setTexture(texture);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(bulbasaurSprite);
            window.display();
        }
    }
}

//-----------------------------------------


void declareWinner(Pokemon & winner, Pokemon & loser)
{
    if(winner.getSideStatus() == true ) // The winner is the player
    {
        printInfo(winner, loser);
        std::cout << "The enemy has 0 health left! You win!! \n\n";
    }


    else if(winner.getSideStatus() == false) //The winner is the AI
    {
        printInfo(loser, winner);
        std::cout << "Your Pokemon has 0 health left! You lost...\n\n";
        std::cout << "Game Over...\n\n";
    }

    displaySprite(winner); // Display winning Pokemon sprite
}

//-----------------------------------------

void calculateDamage(Pokemon & attacker, Pokemon & defender) // Friend function
{
    std::cout << "" << defender.getName() << " took " << attacker.getAttack() << " damage!" << std::endl << std::endl;

    defender.setCurrentHealth(defender.getCurrentHealth() - attacker.getAttack());

    if(defender.getCurrentHealth() <= 0)
    {
        defender.setCurrentHealth(0);

        printInfo(attacker, defender);

        declareWinner(attacker);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

//-----------------------------------------



void playerTurn(Pokemon & p, Pokemon & e) // Friend function
{
    std::cout << "Player's Turn! \n\n";

    std::cout << "The player's " << p.getName() << " attacked the opponent's " << e.getName() << "! \n";

    calculateDamage(p, e);

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

//-------


void enemyTurn(Pokemon & p, Pokemon & e) // Friend function
{
    std::cout << "Enemy's Turn! \n\n";

    std::cout << "The opponent's " << e.getName() << " attacked the player's " << p.getName() << "! \n";

    calculateDamage(e, p);

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

//-----------------------------------------


bool healthCheck(Pokemon & x) // Friend function: Checks the health of the Pokemon that recently got attacked
{
    if(x.getCurrentHealth() <= 0) { return false;} //Let's see if it ever gets to this
    else if(x.getCurrentHealth() > 0) { return true; }
}

//-----------------------------------------


int tieBreaker(Pokemon & a, Pokemon & b) //Friend function --- Tiebreaker can run calculate damage itself
{
    int x = 1;
    int y = 2;
    int z;
    srand(time(NULL));
    z = (rand() % (y - x + 1)) + x;

    switch(z)
    {
    case 1:
        playerTurn(a, b);
        if(healthCheck(b) == true) { enemyTurn(a, b); }
        else{return 0;}
    break;

    case 2:
        enemyTurn(a, b);
        if(healthCheck(a) == true) { playerTurn(a, b); }
        else{return 0;}
    break;

    default:
        std::cout << "This shouldn't happen." << std::endl;
    }

}

//-----------------------------------------

void speedCheck(Pokemon & p, Pokemon & e) // Friend function
{
    if(p.getSpeed() > e.getSpeed()) // SPEED CHECK
    {
        playerTurn(p, e);
        if(healthCheck(e) == true) { enemyTurn(p, e);}
    }

    else if(p.getSpeed() < e.getSpeed() )
    {
        enemyTurn(p, e);
        if(healthCheck(p) == true) { playerTurn(p, e); }
    }

    else if(p.getSpeed() == e.getSpeed())
    {
        tieBreaker(p, e);
    }

}

//-----------------------------------------

 void battle(Pokemon & a, Pokemon & b)
 {
     printInfo(a, b);

     speedCheck(a, b);
 }

 //-----------------------------------------


bool fightOn(Pokemon & a, Pokemon & b)
{

    if(b.getCurrentHealth() > 0 && a.getCurrentHealth() > 0)  { return true; }
    else if(a.getCurrentHealth() <= 0 || b.getCurrentHealth() <= 0) { return false; }
}

 //----------------------------------


void Game::playGame()
{
    //-----Functions to start the game-----/

    Pokemon playerPokemon;
    Pokemon enemyPokemon;

    createPokemon(playerPokemon, enemyPokemon);


    //--------Functions to start the battle-------/

    std::cout << "\nThe player's Pokemon is " << playerPokemon.getName() << "! \n\n";

    std::cout << "The enemy's Pokemon is " << enemyPokemon.getName() << "! \n\n";

    do{battle(playerPokemon, enemyPokemon);}  //
    while(fightOn(playerPokemon, enemyPokemon) == true);
}


//-----------------------------------------

bool Game::retry()
{
      static bool tryAgain;
      char yes_no;
      std::cout << "Do you want to play again? Y/N \n";

      do //So I still need to create a way to prevent more than one character from being accepted (you), (no), etc as these will pass the test even though yes_no is a char...
      {
        std::cin >> yes_no;

        if(yes_no == 'Y' || yes_no == 'y')
        {
          std::cout << "Restarting game...\n\n";

          tryAgain = true;
        }


        else if(yes_no == 'N' || yes_no == 'n')
        {
          std::cout << "Thanks for playing!\n";
          std::cout << "Terminating...\n\n";

          tryAgain = false;
        }


        else if(!(yes_no))
        {
          std::cout << "Let's see if this ever happens...\n";
        }

        else
        {
          std::cout << "Invalid input. Please try again. \n";

          std::cin.clear();
          std::cin.ignore(10000, '\n');

          retry();
        }

        return tryAgain;

      } while(!(yes_no));

}




 /**     HOW THE BATTLE IS SUPPOSED TO GO
 Speed check determines who attacks first                                          // speedCheck(Pokemon & a, Pokemon & b) / tieBreaker(Pokemon & a, Pokemon & b)
 The attack happens                                                                // playerTurnPokemon & p, Pokemon & e() / enemyTurn(Pokemon & p, Pokemon & e)
 Damage is calculated                                                              // calculateDamage(Pokemon & a, Pokemon & b)
 Health check happens. If both Pokemon are still alive slower pokemon attacks next // healthCheck(Pokemon & a, Pokemon & b)
 The attack happens                                                                // playerTurn(Pokemon & p, Pokemon & e) / enemyTurn(Pokemon & p, Pokemon & e)
 Damage is calculated                                                              // calculateDamage(Pokemon & a, Pokemon & b)
 Health check happens. If both Pokemon are still alive the loop repeats            // healthCheck(Pokemon & a, Pokemon & b)
 calculateDamage has an if condition where if the defending pokemon is < 0 then
 the other pokemon is declared winner and fight ends. Then user is asked if        // declareWinner(Pokemon & x)
 they would like to play again. If so, game starts over. If not, game ends,        // playAgain()
**/
