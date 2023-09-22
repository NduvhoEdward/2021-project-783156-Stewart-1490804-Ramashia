#include "Centipede.h"

#include <iostream>

Centipede::Centipede() {
    initCentipede();
}

void Centipede::draw_centipede(sf::RenderWindow* win) {
    win->draw(centipede);
}

void Centipede::move_centipede() {
    if (centipede.getPosition().x >= 0 && centipede.getPosition().x < 600 && centipede.getPosition().y < 600 && foward) {
        centipede.move(20.f, 0.f);
    } else if (centipede.getPosition().x >= 600 && centipede.getPosition().y < 600) {
        centipede.move(-20.f, 20.f);
        foward = false;
    } else if (centipede.getPosition().x >= 0 && centipede.getPosition().x <= 600 && centipede.getPosition().y < 600 && !foward) {
        centipede.move(-20.f, 0.f);
    } else if (centipede.getPosition().x <= 0 && centipede.getPosition().y < 600 && !foward) {
        centipede.move(20.f, 20.f);
        foward = true;
    }

    else if (centipede.getPosition().y >= 600) {
        centipede.setPosition(0, 0);
    }
}

// For  cases when there is a centipede-mushroon collision
void Centipede::special_Move() {
    for (auto x = 0; x < curMushrooms->mushroomSprites.size(); x++) {
        if (centipede.getPosition().x == curMushrooms->mushroomSprites[x].getPosition().x && centipede.getPosition().y == curMushrooms->mushroomSprites[x].getPosition().y && foward) {
            centipede.move(-20.f, 20.f);
            foward = false;
        } else if (centipede.getPosition().x == curMushrooms->mushroomSprites[x].getPosition().x && centipede.getPosition().y == curMushrooms->mushroomSprites[x].getPosition().y && !foward) {
            centipede.move(20.f, 20.f);
            foward = true;
        }
    }
}

float Centipede::centipede_getPosX() {
    return centipede.getPosition().x;
}

float Centipede::centipede_getPosY() {
    return centipede.getPosition().y;
}

void Centipede::centipede_setPos(float x, float y) {
    return centipede.setPosition(x, y);
}

void Centipede::initCentipede() {
    centipede_texture.loadFromFile("../../assets/Centipede.png");

    centipede.setTexture(centipede_texture);
    auto blockSize = 20.0;
    float scaledWidth = blockSize / centipede.getTexture()->getSize().x;
    float scaledheight = blockSize / centipede.getTexture()->getSize().y;
    centipede.scale(sf::Vector2f(scaledWidth, scaledheight));
}

bool Centipede::is_still_alive() {
    return segments;
}
