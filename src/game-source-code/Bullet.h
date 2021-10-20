#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include "Blaster.h"
#include "Mushrooms.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

struct CentipdSegment{

    CentipdSegment(int x, int y) : position(x,y){}
    sf::Vector2i position;
};

class Bullet{

    friend class Blaster;

    public:
        Bullet();
        ~Bullet();
        void Initialize(Blaster *blast, float startPos_x, float startPos_y);
        void UpdateBullet();
        void DrawBullet(sf::RenderWindow* window);
        void Destroy();
        void Collision(){};

    protected:

    private:
        sf::Vector2f Pos;
        Blaster *player;
        sf::RectangleShape bullet;
        std::vector<sf::RectangleShape> firedBullets;

};

#endif // BULLET_H
