#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    Game game;

    game.splashScreen();

    while (game.Window_Is_Open())
    {
        game.update();
        if(!game.render())
            break;

    }

    return 0;
}
