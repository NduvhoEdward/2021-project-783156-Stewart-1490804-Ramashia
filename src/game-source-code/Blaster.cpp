#include "Blaster.h"


Blaster::Blaster()
{
    initBlaster();
}

Blaster::~Blaster()
{
    //dtor
}


void Blaster::draw_blaster(sf::RenderWindow* win)
{
    win->draw(blaster);

}

void Blaster::set_blaster(float x, float y)
{
    blaster.setPosition(x,y);
}

void Blaster::move_blaster()
{
   blaster.move(0,-10);
}

float Blaster::blaster_getPosX()
{
    return blaster.getPosition().x;
}

float Blaster::blaster_getPosY()
{
    return blaster.getPosition().y;
}

void Blaster::initBlaster()
{
    blaster.setSize(sf::Vector2f(8.f,8.f));
    blaster.setFillColor(sf::Color::Green);
     //   player.setPosition(sf::Vectot2f(300,600));

}
