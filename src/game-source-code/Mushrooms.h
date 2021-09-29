#ifndef MUSHROOMS_H
#define MUSHROOMS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Mushrooms
{
    public:
        Mushrooms();
        virtual ~Mushrooms();

        sf::RectangleShape mushrooms;
        void initMushrooms();

    protected:

    private:
};

#endif // MUSHROOMS_H
