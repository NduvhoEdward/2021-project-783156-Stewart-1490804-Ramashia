
#include "Mushrooms.h"
#include <iostream>

const int Init_Num_Of_Mushrooms = 20;
const int VerticalBound = 500;
const int HorizontalBound = 500;
const int UpperBound = 50;
const int LowerBound = 100;

Mushrooms::Mushrooms(){
    //ctor
    mushroomTexture.loadFromFile("resources/mashroom.png");
    sf::Sprite mushroom(mushroomTexture);

    mushroom.scale(sf::Vector2f(0.1f, 0.1f));

    CreateMushPositions();
    createMushrooms(mushroom);
}

Mushrooms::~Mushrooms(){
    //dtor
}

void Mushrooms::drawMushrooms(sf::RenderWindow* window){

    for(int i=0; i<Init_Num_Of_Mushrooms; i++){
        window->draw(mushroomSprites[i]);
    }
}

void Mushrooms::createMushrooms(sf::Sprite& mushroom){

    for(int i=0; i<Init_Num_Of_Mushrooms; i++){

        mushroom.setPosition(mushPositions[i][0],mushPositions[i][1]);
        mushroomSprites.push_back(mushroom);
    }
}

void Mushrooms::CreateMushPositions(){

    auto x = 0, y = 0;
    std::vector<int> temp;
    srand((unsigned)time(NULL));

    for(int i=0; i<Init_Num_Of_Mushrooms; i++){

        temp.clear();
        x = (rand()%HorizontalBound)+1;
        y = (rand()%VerticalBound)-LowerBound;

        temp.push_back(x);
        temp.push_back(y);

        mushPositions.push_back(temp);
    }
}




