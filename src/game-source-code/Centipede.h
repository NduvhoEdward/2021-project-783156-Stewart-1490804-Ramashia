#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Centipede
{
    public:
        Centipede();
        virtual ~Centipede();
        void draw_centipede(sf::RenderWindow*);
        void move_centipede();
        float centipede_getPosX();
        float centipede_getPosY();


    protected:

    private:
        sf::CircleShape centipede;
        void initCentipede();
        bool foward=true;


};

#endif // CENTIPEDE_H
