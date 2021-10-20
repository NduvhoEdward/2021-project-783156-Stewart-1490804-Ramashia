
#include "Mushrooms.h"
#include <iostream>

const int Init_Num_Of_Mushrooms = 50;
const int VerticalBound = 500;
const int HorizontalBound = 500;
const int UpperBound = 50;
const int LowerBound = 100;
const int windowHeight = 600;
const int windowWidth = 600;

Mushrooms::Mushrooms(){
    //ctor
    mushroomTexture.loadFromFile("resources/mashroom.png");
    sf::Sprite mushroom(mushroomTexture);

    mushroom.scale(sf::Vector2f(0.07f, 0.06f));  //0.0625f, 0.055556f

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
    auto mushroomSize = 20;
    std::vector<int> temp;
    srand((unsigned)time(NULL));

    auto possibleXvalues = (windowWidth)/mushroomSize;
    auto possibleYvalues = (windowHeight-3*mushroomSize)/mushroomSize; //Leaving some s
                                                                       // pace at the top for match details

    int x_coords[possibleXvalues] = {0};
    int y_coords[possibleYvalues] = {mushroomSize};

    for(auto i=1; i<possibleXvalues; i++){
        x_coords[i] = x_coords[i-1]+mushroomSize;
    }

    for(auto i=1; i<possibleYvalues; i++){
        y_coords[i] = y_coords[i-1]+mushroomSize;
    }

    for(int i=0; i<Init_Num_Of_Mushrooms; i++){

        temp.clear();
        x = x_coords[rand()%possibleXvalues];
        y = y_coords[rand()%possibleYvalues];


        temp.push_back(x);
        temp.push_back(y);

        mushPositions.push_back(temp);

    }
}





