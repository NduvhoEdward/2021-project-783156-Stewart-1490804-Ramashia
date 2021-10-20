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

    friend class Centipede;

    public:
        Mushrooms();
        virtual ~Mushrooms();

        void drawMushrooms(sf::RenderWindow* win);


    protected:

    private:

        sf::Texture mushroomTexture;
        std::vector<sf::Sprite> mushroomSprites;
        std::vector<std::vector<int>> mushPositions;  /// Make vector FLOAT type

        void CreateMushPositions();
        void createMushrooms(sf::Sprite& mushroom);




};


#endif // MUSHROOMS_H
