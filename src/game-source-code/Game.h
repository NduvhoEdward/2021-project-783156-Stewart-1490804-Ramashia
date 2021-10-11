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

        void splashScreen();

        const bool Is_Window_Open() const;

        void update();
        bool render();


    protected:

    private:
        void initiate_variables();
        void initiate_window();
        bool firstMove=true;
        bool continueGame=true;
        bool gameBegin=false;

        sf::RenderWindow*window;
        Centipede pede;
        Centipede pede2;
        Player player;
        std::vector<Blaster*> bullets;
        std::vector<int> delete_bullets;

};

#endif // GAME_H
