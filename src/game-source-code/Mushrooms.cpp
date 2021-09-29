#include "Mushrooms.h"

Mushrooms::Mushrooms()
{
    //ctor
}

Mushrooms::~Mushrooms()
{
    //dtor
}

void Mushrooms::initMushrooms()
{
    mushrooms.setSize(sf::Vector2f(10.f,10.f));
    mushrooms.setFillColor(sf::Color::Cyan);

}
