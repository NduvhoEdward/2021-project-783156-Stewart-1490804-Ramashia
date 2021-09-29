#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Centipede.h"
#include "Player.h"
#include <vector>
#include "Blaster.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        const bool getWindowIsOpen() const;

        void update();
        bool render();
        void splashScreen();

    protected:

    private:
        Centipede pede;
        Centipede pede2;
        Player player;
        sf::RenderWindow*window;
        void initVariables();
        void initWindow();
        bool firstMove=true;
        std::vector<Blaster*> bullets;
        std::vector<int> delete_bullets;
        bool continueGame=true;
        bool gameBegin=false;
};

#endif // GAME_H
