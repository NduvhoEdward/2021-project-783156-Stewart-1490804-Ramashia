#include "Blaster.h"
#include "Bullet.h"

const int VerticalBound = 500;
const int HorizontalBound = 500;
const int UpperBound = 50;
const int LowerBound = 100;
const int windowHeight = 600;
const int windowWidth = 600;

Blaster::Blaster(){

    initBlaster();
}

Blaster::~Blaster(){
    //dtor
}

void Blaster::draw_blaster(sf::RenderWindow* win){

    win->draw(blaster);
}

void Blaster::set_blaster(float x, float y){

    blaster.setPosition(x,y);
}

void Blaster::move_blaster(){

   blaster.move(0,-10);
}

float Blaster::blaster_getPosX(){

    return blaster.getPosition().x;
}

float Blaster::blaster_getPosY(){

    return blaster.getPosition().y;
}

void Blaster::initBlaster(){

    auto blasterSize = 20;
    blasterTexture.loadFromFile("resources/blaster.png");
    blaster.setTexture(blasterTexture);
    blaster.scale(sf::Vector2f(0.1538f, 0.1538f));
    blaster.setPosition(windowWidth/2,windowHeight-blasterSize);
}

void Blaster::updateBlaster(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        if(blaster.getPosition().x<=10)
            return;
        blaster.move(-10.f, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        if(blaster.getPosition().x>=590)
            return;
        blaster.move(10.f, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        if(blaster.getPosition().y<=10)
            return;
        blaster.move(0.f, -10.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

        if(blaster.getPosition().y>=590)
            return;
        blaster.move(0.f, 10.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){

        Bullet bullt;
    }
}









