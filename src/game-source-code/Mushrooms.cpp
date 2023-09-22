
#include "Mushrooms.h"

#include <iostream>

const int VerticalBound = 500;
const int HorizontalBound = 500;
const int UpperBound = 50;
const int LowerBound = 100;
const int windowHeight = 600;
const int windowWidth = 600;

Mushrooms::Mushrooms() {
    Num_Of_Mushrooms = 25;

    laodMushroomTexture();

    sf::Sprite mushroom(healthy_mushTex);

    auto blockSize = 20.0;
    float scaledWidth = blockSize / mushroom.getTexture()->getSize().x;
    float scaledheight = blockSize / mushroom.getTexture()->getSize().y;
    mushroom.scale(sf::Vector2f(scaledWidth, scaledheight));

    createMushPositions();
    createMushrooms(mushroom);
}

Mushrooms::~Mushrooms() {
}

void Mushrooms::drawMushrooms(sf::RenderWindow* window) {
    for (int i = 0; i < Num_Of_Mushrooms; i++) {
        window->draw(mushroomSprites[i]);
    }
}

void Mushrooms::createMushrooms(sf::Sprite& mushroom) {
    auto default_lives = 4;

    for (int i = 0; i < Num_Of_Mushrooms; i++) {
        mushroom.setPosition(mushPositions[i][0], mushPositions[i][1]);
        mushroomSprites.push_back(mushroom);

        // Load mushroom lives
        mushroomLives.push_back(default_lives);
    }
}

void Mushrooms::createMushPositions() {
    auto x = 0, y = 0;
    auto mushroomSize = 20;
    std::vector<int> temp;
    srand((unsigned)time(NULL));

    auto possibleXvalues = (windowWidth) / mushroomSize;
    auto possibleYvalues = (windowHeight - 3 * mushroomSize) / mushroomSize;  // Leaving some s
                                                                              //  pace at the top for match details

    int x_coords[possibleXvalues] = {0};
    int y_coords[possibleYvalues] = {mushroomSize};

    for (auto i = 1; i < possibleXvalues; i++) {
        x_coords[i] = x_coords[i - 1] + mushroomSize;
    }

    for (auto i = 1; i < possibleYvalues; i++) {
        y_coords[i] = y_coords[i - 1] + mushroomSize;
    }

    for (int i = 0; i < Num_Of_Mushrooms; i++) {
        temp.clear();
        x = x_coords[rand() % possibleXvalues];
        y = y_coords[rand() % possibleYvalues];

        temp.push_back(x);
        temp.push_back(y);

        mushPositions.push_back(temp);
    }
}

void Mushrooms::laodMushroomTexture() {
    healthy_mushTex.loadFromFile("../../assets/youCantSeeMe_mushroom.png");
    IcanTakeIt_mushTex.loadFromFile("../../assets/IcanTakeIt_mushTexture.png");
    nopIcanTakeIt_mushTex.loadFromFile("../../assets/nopCantTakeIt_mushroom.png");
}

void Mushrooms::add_a_mushroom_at(float x, float y) {
    sf::Sprite mushroom(healthy_mushTex);

    auto blockSize = 20.0;
    float scaledWidth = blockSize / mushroom.getTexture()->getSize().x;
    float scaledheight = blockSize / mushroom.getTexture()->getSize().y;
    mushroom.scale(sf::Vector2f(scaledWidth, scaledheight));

    mushroom.setPosition(x, y);
    mushroomSprites.push_back(mushroom);

    auto default_lives = 4;
    mushroomLives.push_back(default_lives);

    Num_Of_Mushrooms++;
}
