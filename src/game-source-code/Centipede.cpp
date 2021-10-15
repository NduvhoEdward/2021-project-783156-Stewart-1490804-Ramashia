#include "Centipede.h"

Centipede::Centipede()
{
    initCentipede();
}

Centipede::~Centipede()
{
    //dtor
}

void Centipede::draw_centipede(sf::RenderWindow* win)
{
    win->draw(centipede);

}

void Centipede::move_centipede()
{
    if(centipede.getPosition().x >= 0&& centipede.getPosition().x <600 &&centipede.getPosition().y <600&&foward)
    {
        centipede.move(20.f, 0.f);
    }
    else if(centipede.getPosition().x >= 600 &&centipede.getPosition().y <600)
    {
        centipede.move(-20.f, 20.f);

        foward=false;
    }

    else if(centipede.getPosition().x >= 0&& centipede.getPosition().x <= 600 &&centipede.getPosition().y <600 &&!foward)
    {
        centipede.move(-20.f, 0.f);
    }

        else if(centipede.getPosition().x <= 0 &&centipede.getPosition().y <600 &&!foward)
    {
        centipede.move(20.f, 20.f);
        foward=true;
    }

    else if(centipede.getPosition().y >= 600)
    {
        centipede.setPosition(0,0);
    }
}

float Centipede::centipede_getPosX()
{
    return centipede.getPosition().x;
}

float Centipede::centipede_getPosY()
{
    return centipede.getPosition().y;
}

void Centipede::centipede_setPos(float x, float y)
{
    return centipede.setPosition(x, y);
}

void Centipede::initCentipede()
{
    centipede.setRadius(10.f);
    centipede.setFillColor(sf::Color::Cyan);
}
