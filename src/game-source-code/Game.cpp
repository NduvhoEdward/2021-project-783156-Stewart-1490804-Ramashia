#include "Game.h"
#include "Centipede.h"
#include "Player.h"
#include "Mushrooms.h"

Game::Game()
{
    initiate_variables();
    initiate_window();
}

Game::~Game()
{
    delete window;
}

void Game::splashScreen()
{
    sf::Font font;
if (!font.loadFromFile("arial.ttf"))
{
    // error...
}
    sf::Text text;
    text.setFont(font); // font is a sf::Font
    text.setString(" Hold 'Enter' to begin \n Move with the arrow keys \n Hold the 'space' key to fire \n Your goal is to destroy the centipede \n before it eats you");
    text.setCharacterSize(24); // in pixels, not points!
    text.setFillColor(sf::Color::White);


    window->clear();
    while(!gameBegin && window->isOpen())
    {
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
        gameBegin=true;
        window->draw(text);
        window->display();
    }

}

const bool Game::Is_Window_Open() const
{
    return window->isOpen();
}



void Game::update()
{
    sf::Event event;
    while (window->pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window->close();
        }
    }
}

bool Game::render()
{

    window->clear();
    player.move_player();
    player.draw_player(window);

    pede1.draw_centipede(window);
    pede2.draw_centipede(window);
    pede3.draw_centipede(window);
    pede4.draw_centipede(window);
    pede5.draw_centipede(window);
    pede6.draw_centipede(window);
    pede7.draw_centipede(window);
    pede8.draw_centipede(window);
    pede9.draw_centipede(window);
    pede10.draw_centipede(window);

    pede1.move_centipede();
    auto x = pede1.centipede_getPosX();
    auto y = pede1.centipede_getPosY();
    if(x>=0 && x<600 && y<600){
        pede2.centipede_setPos(x-20.f, y);
    }

    Blaster *curBullet;
    curBullet=player.fire_bullet();
    if(curBullet!=nullptr)
    bullets.push_back(curBullet);

    for(unsigned i=0;i<bullets.size();i++)
    {
      bullets[i]->move_blaster();
      bullets[i]->draw_blaster(window);

      if(bullets[i]->blaster_getPosY()== pede.centipede_getPosY() && bullets[i]->blaster_getPosX()== pede.centipede_getPosX())
        continueGame=false;

      if(bullets[i]->blaster_getPosY()== pede2.centipede_getPosY() && bullets[i]->blaster_getPosX()== pede2.centipede_getPosX()&&!firstMove)
        continueGame=false;





    if(bullets[i]->blaster_getPosY()<=0)
    delete_bullets.push_back(i);
    }



    for(unsigned i=0;i<delete_bullets.size();i++)
    {
       bullets.erase(bullets.begin()+delete_bullets[i]);
    }
    delete_bullets.clear();

    if(player.player_getPosY()== pede.centipede_getPosY() && player.player_getPosX()== pede.centipede_getPosX())
        continueGame=false;

    pede.move_centipede();
    if(!firstMove)
    {
    pede2.draw_centipede(window);
    pede2.move_centipede();
    }

    window->display();
    firstMove=false;


    return continueGame;


}

// private functions
void Game::initiate_variables()
{
    window = nullptr;
}

void Game::initiate_window()
{
    window = new sf::RenderWindow;
    window->create(sf::VideoMode(600, 600), "Centipede++");
    window->setFramerateLimit(5);
}


