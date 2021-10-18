#ifndef MUSHROOMS_H
#define MUSHROOMS_H

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum mushroom_state{
    healthy,
    half_healthy,
    destroyed
};

class Mushrooms{

    public:
        Mushrooms();
        virtual ~Mushrooms();

        sf::RectangleShape mushrooms;
        void initMushrooms();
        void renderMushrooms(sf::RenderWindow* win);
        void drawMushrooms(sf::RenderWindow* win);

    protected:

    private:
        sf::Texture mushroomTexture;
        //std::vector<std::vector<sf::Sprite>> mushroomSprites;
        std::vector<sf::Sprite> mushroomSprites;
        //sf::Sprite mushroom
        void createMushrooms(sf::Sprite& mushroom);
        void CreateMushPositions();
        std::vector<std::vector<int>> mushPositions;   /// Make vector FLOAT type

};


#endif // MUSHROOMS_H
