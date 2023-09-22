#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "Mushrooms.h"

const int WindowHeight = 600;
const int WindowWidth = 600;

struct CentipdSegment {
    CentipdSegment(int x, int y) : position(x, y) {}
    sf::Vector2i position;
};

using CentipdContainer = std::vector<CentipdSegment>;
enum class Direction { None,
                       Down,
                       Left,
                       Right };

class Centipede {
   public:
    Centipede();
    void draw_centipede(sf::RenderWindow *);
    void move_centipede();
    void special_Move();  /// For  cases when there is a centipede-mushroon collision
    float centipede_getPosX();
    float centipede_getPosY();
    void centipede_setPos(float x, float y);
    Mushrooms *curMushrooms;
    bool is_still_alive();
    inline static int segments = 10;

   private:
    // sf::CircleShape centipede;
    sf::Texture centipede_texture;
    sf::Sprite centipede;

    void initCentipede();
    bool foward = true;
    std::vector<std::vector<int>> mushroom_Positions;
};

#endif  // CENTIPEDE_H
