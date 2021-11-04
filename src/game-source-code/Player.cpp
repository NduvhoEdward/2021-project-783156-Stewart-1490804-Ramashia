#include "Player.h"

const int UpperBound = 50;
const int LowerBound = 100;
const int windowHeight = 600;
const int windowWidth = 600;
const int VerticalBound = 500;
const int HorizontalBound = 500;
const int alignBullet = 9;

Player::Player()
{
    initPlayer();
}

Player::~Player()
{
    //dtor
}

void Player::draw_player(sf::RenderWindow* win)
{
    win->draw(player);

}

void Player::move_player()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(player.getPosition().x<=10)
            return;

        player.move(-10.f, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(player.getPosition().x>=590)
            return;

        player.move(10.f, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(player.getPosition().y<=10)
            return;

        player.move(0.f, -10.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(player.getPosition().y>=590)
            return;

        player.move(0.f, 10.f);
    }
}

float Player::player_getPosX()
{
    return player.getPosition().x;
}

float Player::player_getPosY()
{
    return player.getPosition().y;
}

Blaster* Player::fire_bullet()
{
    int bullt_blastr_sync = 9;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){

        Blaster* bullet = new Blaster;
        bullet->set_blaster(player.getPosition().x+bullt_blastr_sync, player.getPosition().y);
        return bullet;
    }

    return nullptr;
}

void Player::initPlayer(){

    auto blasterSize = 20;
    playerTexture.loadFromFile("resources/blaster.png");
    player.setTexture(playerTexture);
    player.scale(sf::Vector2f(0.1538f, 0.1538f));
    player.setPosition(windowWidth/2,windowHeight-blasterSize);
}
