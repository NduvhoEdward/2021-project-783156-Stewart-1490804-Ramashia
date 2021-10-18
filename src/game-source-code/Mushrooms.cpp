
#include "Mushrooms.h"
#include <iostream>



Mushrooms::Mushrooms(){
    //ctor
    mushroomTexture.loadFromFile("resources/smario_mashroom2.png");
    sf::Sprite mushroom(mushroomTexture);

    mushroom.scale(sf::Vector2f(0.1f, 0.1f));

    //sf::Vector2u size = mushroomTexture.getSize();
    //mushroom.setOrigin(size.x / 2, size.y / 2);
    //sf::Vector2f increment(0.4f, 0.4f);

    //std::cout << size.x <<"  "<<size.y <<std::endl;


    //std::vector<sf::Sprite> temp;
    //temp.push_back(mushroom);
    createMushrooms(mushroom);

}

Mushrooms::~Mushrooms(){
    //dtor
}

void Mushrooms::initMushrooms(){

//    mushrooms.setSize(sf::Vector2f(10.f,10.f));
//    mushrooms.setFillColor(sf::Color::Cyan);
//    sf::Sprite s = myMatrix[x][y];


}


void Mushrooms::drawMushrooms(sf::RenderWindow* window){

    //window->clear(sf::Color(16,16,16,255)); // Dark gray.
    window->draw(mushroomSprites[0]); // Drawing our sprite.
    //window->display();
}

void Mushrooms::createMushrooms(sf::Sprite mushroom){

    mushroomSprites.push_back(mushroom);
}



