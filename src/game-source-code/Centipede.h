#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <vector>
#include "Mushrooms.h"

const int WindowHeight = 600;
const int WindowWidth = 600;

struct CentipdSegment{

    CentipdSegment(int x, int y) : position(x,y){}
    sf::Vector2i position;
};

using CentipdContainer = std::vector<CentipdSegment>;
enum class Direction{None, Down, Left, Right};


class Centipede
{
    public:
        Centipede();
        void draw_centipede(sf::RenderWindow*);
        void move_centipede();
        void special_Move();
        float centipede_getPosX();
        float centipede_getPosY();
        void centipede_setPos(float x, float y);
        Mushrooms *curMushrooms;

        void createCentipd(int segments, int x, int y);
        void split_the_centipd();

    protected:

    private:
        //sf::CircleShape centipede;
        sf::Texture centipede_texture;
        sf::Sprite centipede;

        void initCentipede();
        bool foward=true;
        std::vector<std::vector<int>> mushroom_Positions;

};

#endif // CENTIPEDE_H
