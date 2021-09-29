#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Blaster.h"

class Player
{
    public:
        Player();
        virtual ~Player();
        void draw_player(sf::RenderWindow*);
        void move_player();
        Blaster* fire_bullet();
        float player_getPosX();
        float player_getPosY();

    protected:

    private:
        sf::RectangleShape player;
        void initPlayer();
        bool foward=true;


};

#endif // _H
