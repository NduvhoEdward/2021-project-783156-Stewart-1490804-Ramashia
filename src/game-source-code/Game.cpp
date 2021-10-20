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
    blastr.updateBlaster();
    //Bullt.UpdateBullet();
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

    pede10.centipede_setPos(pede9.centipede_getPosX(), pede9.centipede_getPosY());
    pede9.centipede_setPos(pede8.centipede_getPosX(), pede8.centipede_getPosY());
    pede8.centipede_setPos(pede7.centipede_getPosX(), pede7.centipede_getPosY());
    pede7.centipede_setPos(pede6.centipede_getPosX(), pede6.centipede_getPosY());
    pede6.centipede_setPos(pede5.centipede_getPosX(), pede5.centipede_getPosY());
    pede5.centipede_setPos(pede4.centipede_getPosX(), pede4.centipede_getPosY());
    pede4.centipede_setPos(pede3.centipede_getPosX(), pede3.centipede_getPosY());
    pede3.centipede_setPos(pede2.centipede_getPosX(), pede2.centipede_getPosY());
    pede2.centipede_setPos(pede1.centipede_getPosX(), pede1.centipede_getPosY());
    pede1.move_centipede();

    Blaster *curBullet;
    curBullet=player.fire_bullet();
    if(curBullet!=nullptr)
    bullets.push_back(curBullet);

    for(unsigned i=0;i<bullets.size();i++)
    {
      bullets[i]->move_blaster();
      bullets[i]->draw_blaster(window);

      if(bullets[i]->blaster_getPosY()== pede1.centipede_getPosY() && bullets[i]->blaster_getPosX()== pede1.centipede_getPosX())
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

    if(player.player_getPosY()== pede1.centipede_getPosY() && player.player_getPosX()== pede1.centipede_getPosX())
        continueGame=false;


    //Mushrooms rendering
    mushrm.drawMushrooms(window);

    //Blaster
    blastr.draw_blaster(window);



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


