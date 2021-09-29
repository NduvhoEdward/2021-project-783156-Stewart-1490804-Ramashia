#include "Player.h"

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
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
{
   Blaster* bullet= new Blaster;
   bullet->set_blaster(player.getPosition().x, player.getPosition().y);
   return bullet;
}

return nullptr;

}

void Player::initPlayer()
{
    player.setSize(sf::Vector2f(20.f,20.f));
    player.setFillColor(sf::Color::Red);
     //   player.setPosition(sf::Vectot2f(300,600));
    player.setPosition(300.f,500.f);
}
