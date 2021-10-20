#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <vector>
#include "Mushrooms.h"

class Centipede
{
    public:
        Centipede();
        virtual ~Centipede();
        void draw_centipede(sf::RenderWindow*);
        void move_centipede();
        void special_Move();
        float centipede_getPosX();
        float centipede_getPosY();
        void centipede_setPos(float x, float y);
        Mushrooms *curMushrooms;

    protected:

    private:
        sf::CircleShape centipede;
        void initCentipede();
        bool foward=true;
        std::vector<std::vector<int>> mushroom_Positions;

};

#endif // CENTIPEDE_H
