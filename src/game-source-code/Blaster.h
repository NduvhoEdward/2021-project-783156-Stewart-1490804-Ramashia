#ifndef BLASTER_H
#define BLASTER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Blaster
{
    public:
        Blaster();
        virtual ~Blaster();
        void draw_blaster(sf::RenderWindow*);
        void set_blaster(float, float);
        void move_blaster();
        float blaster_getPosX();
        float blaster_getPosY();

    protected:

    private:
        sf::RectangleShape blaster;
        void initBlaster();
        bool foward=true;


};

#endif // CENTIPEDE_H
