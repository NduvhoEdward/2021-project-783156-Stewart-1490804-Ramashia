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
#include "Mushrooms.h"

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

        Centipede pede1;
        Centipede pede2;
        Centipede pede3;
        Centipede pede4;
        Centipede pede5;
        Centipede pede6;
        Centipede pede7;
        Centipede pede8;
        Centipede pede9;
        Centipede pede10;

        sf::RenderWindow*window;

        Player player;
        std::vector<Blaster*> bullets;
        std::vector<int> delete_bullets;

        //Mushrooms
        Mushrooms mushrm;

};

#endif // GAME_H
