#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    Game game;

    game.splashScreen();

    while (game.Is_Window_Open())
    {
        game.update();
        if(!game.render())
            break;

    }

    return 0;
}
