#include "Game.h"

const int FrameRate = 25;
const int alignBulletPxl = -9;

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
    if (!font.loadFromFile("resources/arial.ttf")){}

    sf::Text text;
    text.setFont(font); // font is a sf::Font
    text.setString("Hold 'Enter' to begin \nMove with the arrow keys \nPress the 'space' key to fire \nYour goal is to destroy the centipede \nBefore it eats you");
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

const bool Game::Window_Is_Open() const
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
    pede1.special_Move();

    Blaster *curBullet;
    curBullet=player.fire_bullet();
    if(curBullet!=nullptr)
    bullets.push_back(curBullet);

    for(unsigned i=0; i<bullets.size(); i++){

        //Searching for bullet-mushroom collisions
        checkBulletMushCol(i);

        bullets[i]->move_blaster();
        bullets[i]->draw_blaster(window);

        //To be moved into a bool function
        if(bullets[i]->blaster_getPosY()== pede1.centipede_getPosY() && bullets[i]->blaster_getPosX()+alignBulletPxl== pede1.centipede_getPosX())
        {
            //continueGame=false;
            // Turn pedeX into a mushroom
            auto x = pede1.centipede_getPosX();
            auto y = pede1.centipede_getPosY();
            mushrm.add_a_mushroom_at(x,y);
            // Make pede(X-1) the new head

            //Turn the Centipede, the behind part
        }
        else if(bullets[i]->blaster_getPosY()== pede2.centipede_getPosY() && bullets[i]->blaster_getPosX()+alignBulletPxl== pede2.centipede_getPosX()&&!firstMove)
        {
            //continueGame=false;
            // Turn pedeX into a mushroom
            auto x = pede2.centipede_getPosX();
            auto y = pede2.centipede_getPosY();
            mushrm.add_a_mushroom_at(x,y);
            // Make pede(X-1) the new head

            //Turn the Centipede, the behind part
        }
        else if(bullets[i]->blaster_getPosY()== pede3.centipede_getPosY() && bullets[i]->blaster_getPosX()+alignBulletPxl== pede3.centipede_getPosX()&&!firstMove)
        {
            //continueGame=false;
            // Turn pedeX into a mushroom
            auto x = pede3.centipede_getPosX();
            auto y = pede3.centipede_getPosY();
            mushrm.add_a_mushroom_at(x,y);
            // Make pede(X-1) the new head

            //Turn the Centipede, the behind part
        }
        if(bullets[i]->blaster_getPosY()== pede4.centipede_getPosY() && bullets[i]->blaster_getPosX()+alignBulletPxl== pede4.centipede_getPosX()&&!firstMove)
        {
            //continueGame=false;
            // Turn pedeX into a mushroom
            auto x = pede4.centipede_getPosX();
            auto y = pede4.centipede_getPosY();
            mushrm.add_a_mushroom_at(x,y);
            // Make pede(X-1) the new head

            //Turn the Centipede, the behind part
        }
        else if(bullets[i]->blaster_getPosY()== pede5.centipede_getPosY() && bullets[i]->blaster_getPosX()+alignBulletPxl== pede5.centipede_getPosX()&&!firstMove)
        {
            //continueGame=false;
            // Turn pedeX into a mushroom
            auto x = pede5.centipede_getPosX();
            auto y = pede5.centipede_getPosY();
            mushrm.add_a_mushroom_at(x,y);
            // Make pede(X-1) the new head

        }
        else if(bullets[i]->blaster_getPosY()== pede6.centipede_getPosY() && bullets[i]->blaster_getPosX()+alignBulletPxl== pede6.centipede_getPosX()&&!firstMove)
        {
            //continueGame=false;
            // Turn pedeX into a mushroom
            auto x = pede6.centipede_getPosX();
            auto y = pede6.centipede_getPosY();
            mushrm.add_a_mushroom_at(x,y);
            // Make pede(X-1) the new head
        }
        else if(bullets[i]->blaster_getPosY()== pede7.centipede_getPosY() && bullets[i]->blaster_getPosX()+alignBulletPxl== pede7.centipede_getPosX()&&!firstMove)
        {
            //continueGame=false;
            // Turn pedeX into a mushroom
            auto x = pede7.centipede_getPosX();
            auto y = pede7.centipede_getPosY();
            mushrm.add_a_mushroom_at(x,y);
            // Make pede(X-1) the new head

            //Turn the Centipede, the behind part
        }
        else if(bullets[i]->blaster_getPosY()== pede8.centipede_getPosY() && bullets[i]->blaster_getPosX()+alignBulletPxl== pede8.centipede_getPosX()&&!firstMove)
        {   //continueGame=false;
            // Turn pedeX into a mushroom
            auto x = pede8.centipede_getPosX();
            auto y = pede8.centipede_getPosY();
            mushrm.add_a_mushroom_at(x,y);
            // Make pede(X-1) the new head

            //Turn the Centipede, the behind part
        }
        else if(bullets[i]->blaster_getPosY()== pede9.centipede_getPosY() && bullets[i]->blaster_getPosX()+alignBulletPxl== pede9.centipede_getPosX()&&!firstMove)
        {
            //continueGame=false;
            // Turn pedeX into a mushroom
            auto x = pede9.centipede_getPosX();
            auto y = pede9.centipede_getPosY();
            mushrm.add_a_mushroom_at(x,y);
            // Make pede(X-1) the new head

            //Turn the Centipede, the behind part
        }
        else if(bullets[i]->blaster_getPosY()== pede10.centipede_getPosY() && bullets[i]->blaster_getPosX()+alignBulletPxl== pede10.centipede_getPosX()&&!firstMove)
        {
            //continueGame=false;
            // Turn pedeX into a mushroom
            auto x = pede10.centipede_getPosX();
            auto y = pede10.centipede_getPosY();
            mushrm.add_a_mushroom_at(x,y);
            // Make pede(X-1) the new head

            //Turn the Centipede, the behind part

        }

        if(bullets[i]->blaster_getPosY()<=0)
            delete_bullets.push_back(i);
    }


    for(unsigned i=0;i<delete_bullets.size();i++)
    {
       bullets.erase(bullets.begin()+delete_bullets[i]);
    }
    delete_bullets.clear();

    if(player.player_getPosY()== pede1.centipede_getPosY() && player.player_getPosX() == pede1.centipede_getPosX())
        continueGame=false;


    //Mushrooms rendering
    mushrm.drawMushrooms(window);

    window->display();
    firstMove=false;

    return continueGame;
}

// private functions
void Game::initiate_variables(){

    window = nullptr;
    pede1.curMushrooms=&mushrm;
}

void Game::initiate_window(){
    const int windowHeight = 600;
    const int windowWidth = 600;
    window = new sf::RenderWindow;
    window->create(sf::VideoMode(windowWidth, windowHeight), "Centipede++");
    window->setFramerateLimit(FrameRate);
}

void Game::checkBulletMushCol(auto& i)
{
    for(auto m=0; m<mushrm.mushroomSprites.size(); m++)
    {
        //If the bullet is in mushroom range, change shape or remove if needs be
        if(bullets[i]->blaster_getPosX()>mushrm.mushroomSprites[m].getPosition().x)
        {
            if(bullets[i]->blaster_getPosX()<mushrm.mushroomSprites[m].getPosition().x+20)
            {
                if(bullets[i]->blaster_getPosY()==mushrm.mushroomSprites[m].getPosition().y+20)
                {
                    --mushrm.mushroomLives[m];

                    if(mushrm.mushroomLives[m] == 3)
                        mushrm.mushroomSprites[m].setTexture(mushrm.IcanTakeIt_mushTex);

                    if(mushrm.mushroomLives[m] == 2)
                        mushrm.mushroomSprites[m].setTexture(mushrm.nopIcanTakeIt_mushTex);
                    //Delete the mushroom
                    if(mushrm.mushroomLives[m] == 1){
                        mushrm.mushroomSprites.erase(mushrm.mushroomSprites.begin()+m);
                        mushrm.Num_Of_Mushrooms--;
                    }
                    //Delete bullet
                    bullets.erase(bullets.begin()+i);
                }
            }
        }
    }
}


