#ifndef MUSHROOMS_H
#define MUSHROOMS_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Mushrooms {
   public:
    Mushrooms();
    virtual ~Mushrooms();
    void drawMushrooms(sf::RenderWindow* win);

   protected:
   private:
    void laodMushroomTexture();
    sf::Texture healthy_mushTex;
    sf::Texture IcanTakeIt_mushTex;
    sf::Texture nopIcanTakeIt_mushTex;
    void add_a_mushroom_at(float x, float y);

    std::vector<sf::Sprite> mushroomSprites;
    std::vector<int> mushroomLives;
    std::vector<std::vector<int>> mushPositions;  /// Make vector FLOAT type

    void createMushPositions();
    void createMushrooms(sf::Sprite& mushroom);
    int Num_Of_Mushrooms;

    friend class Game;
    friend class Centipede;
};

#endif  // MUSHROOMS_H
